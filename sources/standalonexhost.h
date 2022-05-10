#ifndef STANDALONEXHOST_H
#define STANDALONEXHOST_H

#include "xhostinterface.h"
#include "jsnexus.h"
#include <filesystem>
#include <list>

class StandaloneXHost : public XHostInterface {
public:
    int XPluginStart();

    std::string GetRootPath() override;

private:
    std::list <JSNexus*> m_jsnexus;
    std::filesystem::path m_rootPath;
};


#endif //STANDALONEXHOST_H
