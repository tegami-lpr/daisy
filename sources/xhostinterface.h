#ifndef XHOSTINTERFACE_H
#define XHOSTINTERFACE_H

#include "logadapter.h"

#include <cstdint>
#include <string>

class XHostInterface {
public:
    virtual void LogMessage(LogAdapter::ELogLevel, const std::string &message);
    virtual void LogSystemMessage(const std::string &message);
    virtual std::string GetRootPath() = 0;
};


#endif //XHOSTINTERFACE_H
