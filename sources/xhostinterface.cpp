#include "xhostinterface.h"

void XHostInterface::LogMessage(LogAdapter::ELogLevel level, const std::string &message) {
    LogAdapter::WriteMessage(level, message);
}

void XHostInterface::LogSystemMessage(const std::string &message) {
    LogAdapter::WriteMessage(LogAdapter::eInfo, message);
}
