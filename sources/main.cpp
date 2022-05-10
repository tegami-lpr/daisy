#include <string>

#include "jsnexus.h"
#include "standalonexhost.h"
#include "logadapter.h"

int main() {

    LogAdapter::Init();
    auto xh = new StandaloneXHost();

    xh->XPluginStart();

    xh->XPluginStop();
    delete xh;

    return 0;
}
