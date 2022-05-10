#include <string>

#include "jsnexus.h"
#include "standalonexhost.h"
#include "logadapter.h"

int main() {

    LogAdapter::Init();
    auto xh = new StandaloneXHost();

    xh->XPluginStart();

//    auto nexus = new JSNexus(xh);
//    nexus->ExecFile("test.js");
//
//    nexus->Update();
//
//    delete nexus;

    delete xh;

    return 0;
}
