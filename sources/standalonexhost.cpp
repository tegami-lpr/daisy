#include "standalonexhost.h"

#include <filesystem>

int StandaloneXHost::XPluginStart() {
    m_rootPath = std::filesystem::current_path();
    for (auto const& dir_entry : std::filesystem::directory_iterator(m_rootPath)) {
        if (!dir_entry.is_regular_file()) continue;
        auto fl_ext = dir_entry.path().extension();
        if (fl_ext != ".js") continue;

        printf("%s\n", dir_entry.path().c_str());
        auto nexus = new JSNexus(this);
        bool res = nexus->ExecFile(dir_entry.path().c_str());

        if (!res) {
            delete nexus;
            continue;
        }

        m_jsnexus.push_back(nexus);
    }

    return 1;
}

std::string StandaloneXHost::GetRootPath() {
    return m_rootPath;
}
