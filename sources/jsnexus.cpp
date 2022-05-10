#include "jsnexus.h"
#include "js_support.h"
#include <string>

JSNexus::JSNexus(XHostInterface *xhost) {
    m_xhost = xhost;
    m_jsState = js_newstate(nullptr, nullptr, JS_STRICT);

    //Adding link to our instance to js global object
    js_setcontext(m_jsState, this);
    js_setreport(m_jsState, js_report);

//    js_pushglobal(m_jsState);
//    js_newobject(m_jsState);
//    js_newuserdata(m_jsState, "nexus", this, nullptr);
//    js_setproperty(m_jsState, -2,"nexus");

    //Creating global functions
    defineGlobalObjects();
}

JSNexus::~JSNexus() {
    js_freestate(m_jsState);
}

bool JSNexus::ExecFile(const std::string& fileName) {
    auto res = js_dofile(m_jsState, fileName.c_str());
    return !res;
}

void JSNexus::Update() {
    js_getglobal(m_jsState, "global");
    if (js_isobject(m_jsState, -1) == 0) {
        //TODO: log
        return;
    }
    if (js_hasproperty(m_jsState, -1, "update") == 0) {
        m_xhost->LogMessage(LogAdapter::eInfo, "global.update() is not exists!");
        return;
    }
    if (js_iscallable(m_jsState, -1) == 0) {
        m_xhost->LogMessage(LogAdapter::eError, "global.update() is not callable!");
        //TODO: stop execution
        return;
    }

    js_getglobal(m_jsState, "global"); //Push 'this' value for function call
    js_call(m_jsState, 0);
}

void JSNexus::defineGlobalObjects() {

    //Creating new 'global' object and adding some properties
    js_newobject(m_jsState);
    //'log' function for logging messages to plugin's logfile
    js_newcfunction(m_jsState, js_log, "log", 1);
    js_defproperty(m_jsState, -2, "log", JS_READONLY);
    //'syslog' function for logging messages to XP log
    js_newcfunction(m_jsState, js_syslog, "syslog", 1);
    js_defproperty(m_jsState, -2, "syslog", JS_READONLY);
    js_setglobal(m_jsState, "global");


//    js_newcfunction(m_jsState, js_log, "log", 1);
//    js_setglobal(m_jsState, "log");
//    js_newcfunction(m_jsState, js_syslog, "syslog", 1);
//    js_setglobal(m_jsState, "syslog");

    js_newcfunction(m_jsState, js_import_Js, "import_js", 1);
    js_setglobal(m_jsState, "import_js");
}

void JSNexus::js_log(js_State *J) {
    const char *msg = js_tostring(J, 1);
    std::string jsMsg = "JS: " + std::string(msg);
    //Logger::Debug(jsMsg);
    //printf("%s\n", jsMsg.c_str());

    auto nexusPtr = get_nexus_ptr(J);
    nexusPtr->m_xhost->LogMessage(LogAdapter::eInfo, jsMsg);
    js_pushundefined(J);
}

void JSNexus::js_syslog(js_State *J) {
    const char *msg = js_tostring(J, 1);
    std::string jsMsg = "JS: " + std::string(msg);

    auto nexusPtr = get_nexus_ptr(J);
    nexusPtr->m_xhost->LogSystemMessage(jsMsg);
    js_pushundefined(J);
}

void JSNexus::js_report(js_State *J, const char *message) {
    std::string jsMsg = "JS engine: " + std::string(message);
    //printf("%s\n", jsMsg.c_str());
    auto nexusPtr = get_nexus_ptr(J);
    nexusPtr->m_xhost->LogMessage(LogAdapter::eError, jsMsg);
}

void JSNexus::js_import_Js(js_State *J) {
    const char *msg = js_tostring(J, 1);
    std::string jsMsg = "importing " + std::string(msg);

    auto nexusPtr = get_nexus_ptr(J);
    nexusPtr->m_xhost->LogMessage(LogAdapter::eInfo, jsMsg);

    auto res = js_dofile(J, msg);
    if (res) {
        js_throw(J);
    }

    js_pushundefined(J);
}

JSNexus *JSNexus::get_nexus_ptr(js_State *J) {
//    js_pushglobal(J);
//    js_getproperty(J, -1, "nexus");
//    auto ptr = js_touserdata(J, -1, "nexus");
//    auto nexusPtr = static_cast<JSNexus*>(ptr);
//    js_pop(J, 1);
    auto ptr = js_getcontext(J);
    auto nexusPtr = reinterpret_cast<JSNexus*>(ptr);
    return nexusPtr;
}
