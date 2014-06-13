// ServerLog: Used to log the server event.
// Author: Yubin Yang
// date: 2014-06-14

#ifndef SERVERLOG_H_INCLUDE
#define SERVERLOG_H_INCLUDE
#include <string>
#include <cstdarg>
#include <fstream>
#include <memory>
class ServerLog {
public:
    ServerLog(std::string logFileName);
    bool addLogWithTime(std::string, ...);
    bool addLogWithoutTime(std::string, ...);

private:
    bool addLog(std::string, ...);
    std::shared_ptr<FILE > fd;
};

#endif