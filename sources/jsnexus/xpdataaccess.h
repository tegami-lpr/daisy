#ifndef XPDATAACCESS_H
#define XPDATAACCESS_H

#include "jsnexus.h"

class XPDataAccess {
public:
    explicit XPDataAccess(JSNexus *nexus);
    void CreateXPDObject();

private:

    static void js_openDataRef(js_State *J);
    static void js_createDataRef(js_State *J);
    static void js_isDataRefExists(js_State *J);

    JSNexus *m_nexus;
};


#endif //XPDATAACCESS_H
