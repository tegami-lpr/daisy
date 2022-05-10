#ifndef LOGADAPTER_H
#define LOGADAPTER_H

#include <cstdint>
#include <string>

class LogAdapter {
public:
    enum ELogLevel: uint8_t {
        eInfo = 0,
        eWarning,
        eError
    };

    static void Init();
    static void WriteMessage(ELogLevel level, const std::string& message);
};


#endif //LOGADAPTER_H
