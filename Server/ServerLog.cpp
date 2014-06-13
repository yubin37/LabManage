// Author: Yubin Yang
// Date: 2014-06-14

#include <iostream>
#include "ServerLog.h"
#include <cstdio>
#include <ctime>

#define MAXLENGTH 1023
ServerLog::ServerLog(std::string logFileName)
{
    fd.reset(fopen(logFileName.c_str(), "a"));
    if (!fd) {
	   std::cout << "Cannot open the file " << logFileName << std::endl;
	   exit(EXIT_FAILURE);
    }

}

bool ServerLog::addLog(std::string format, ...)
{
    va_list args;
    va_start(args, format);

    char logLine[MAXLENGTH + 1];
    logLine[MAXLENGTH] = '\0';
    try {
	   vfprintf_s(fd.get, format.c_str(), args);
    }
    catch (std::exception e) {
	   std::cout << "Error" << e.what() << std::endl;
	   return false;
    }
    return true;
}

bool ServerLog::addLogWithoutTime(std::string format, ...)
{
    va_list args;
    va_start(args, format);
    return addLog(format, args);
}

bool ServerLog::addLogWithTime(std::string format, ...)
{
    va_list args;
    va_start(args, format);
    format = "20%s " + format;
    time_t rawTime;
    struct tm* timeInfo;
    time(&rawTime);
    timeInfo = localtime(&rawTime);
    return addLog(format, asctime(timeInfo), args);
}