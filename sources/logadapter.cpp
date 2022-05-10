#include "logadapter.h"
#include <loguru.hpp>

void LogAdapter::Init() {
    int argc=1;
    const char* argv[] = {"none", nullptr};
    loguru::g_preamble_uptime = false;
    loguru::g_preamble_thread = false;
    loguru::g_preamble_file = false;
    loguru::g_preamble_header = false;

    auto options = loguru::Options();
    options.signal_options = loguru::SignalOptions::none();
    loguru::init(argc, (char**)&argv, options);
    loguru::add_file("daisy.log", loguru::Truncate, loguru::Verbosity_INFO);
}

void LogAdapter::WriteMessage(LogAdapter::ELogLevel level, const std::string& message) {
    switch (level) {
        case eError:
            VLOG_F(loguru::Verbosity_ERROR, "%s", message.c_str());
            break;
        case eWarning:
            VLOG_F(loguru::Verbosity_WARNING, "%s", message.c_str());
            break;
        default:
        //case eInfo:
            VLOG_F(loguru::Verbosity_INFO, "%s", message.c_str());
            break;
    }
}
