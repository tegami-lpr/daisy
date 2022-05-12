#include "xpdataaccess.h"

XPDataAccess::XPDataAccess(JSNexus *nexus) {
    m_nexus = nexus;
}

void XPDataAccess::CreateXPDObject() {
    auto jsState = m_nexus->GetJSState();
    //Creating new 'XPDataAccess' object and adding function for creating dataref objects
    js_newobject(jsState);
    //'openDataRef' function for open or create new XP dataref. return JS object;
    js_newcfunction(jsState, js_openDataRef, "openDataRef", 1);
    js_defproperty(jsState, -2, "openDataRef", JS_READONLY);
    //'createDataRef' function for create new XP dataref. return JS object;
    js_newcfunction(jsState, js_createDataRef, "createDataRef", 1);
    js_defproperty(jsState, -2, "createDataRef", JS_READONLY);
    //'isDataRefExists' function for checking dataref existence
    js_newcfunction(jsState, js_isDataRefExists, "isDataRefExists", 1);
    js_defproperty(jsState, -2, "isDataRefExists", JS_READONLY);
    js_defglobal(jsState, "XPDataAccess", JS_READONLY);
}

void XPDataAccess::js_openDataRef(js_State *J) {
    auto nexus = JSNexus::get_nexus_ptr(J);
    //auto xhost = nexus->GetXHost();

    js_pushundefined(J);
}

void XPDataAccess::js_createDataRef(js_State *J) {
    auto nexus = JSNexus::get_nexus_ptr(J);
    js_pushundefined(J);
}

void XPDataAccess::js_isDataRefExists(js_State *J) {
    js_pushboolean(J, false);
}
