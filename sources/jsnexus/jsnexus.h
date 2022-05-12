#ifndef MJSTEST_JSNEXUS_H
#define MJSTEST_JSNEXUS_H

#include "xhostinterface.h"
#include <mujs.h>
#include <string>

class XPDataAccess;

class JSNexus {
public:
    explicit JSNexus(XHostInterface *xhost);
    ~JSNexus();
    bool ExecFile(const std::string& fileName);
    void Update();

    void OnPlaneLoaded();
    void OnPlaneUnLoaded();
    void OnAirportLoaded();
    void OnPlaneCrashed();

    js_State *GetJSState();
    XPDataAccess *GetXPDataAccessObject();
    XHostInterface *GetXHost();

    static JSNexus* get_nexus_ptr(js_State *J);
private:
    void defineGlobalObjects();
    void callEventFunc(const std::string& funcName);

    static void js_log(js_State *J);
    static void js_syslog(js_State *J);
    static void js_report(js_State *J, const char *message);

    static void js_import_js(js_State *J);

    js_State *m_jsState;
    XHostInterface *m_xhost;
    XPDataAccess *m_XPDataAccessObject;
};


#endif //MJSTEST_JSNEXUS_H
