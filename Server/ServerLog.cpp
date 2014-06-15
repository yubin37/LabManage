// Author: Yubin Yang
// Date: 2014-06-14

#include <iostream>
#include "ServerLog.h"
#include <cstdio>
#include <ctime>

#define MAXLENGTH 1024
#define TIMELENGTH 20
ServerLog::ServerLog(std::string logFileName)
{
    fd = fopen(logFileName.c_str(), "a");
    if (!fd) {
	   std::cout << "Cannot open the file " << logFileName << std::endl;
	   exit(EXIT_FAILURE);
    }

}

ServerLog::~ServerLog()
{
    ;
}
bool ServerLog::addLog(char* logLine, std::string format, va_list args)
{
    try {
	   vsprintf(logLine, format.c_str(), args);
    }
    catch (std::exception e) {
	   std::cout << "Error: " << e.what() << std::endl;
	   return false;
    }
    return true;
}

bool ServerLog::addLogWithoutTime(std::string format, ...)
{
    va_list args;
    va_start(args, format);
    char logLine[MAXLENGTH];
    bool result = addLog(logLine,format, args);
    if (result)
	   fwrite(logLine, sizeof(char), strlen(logLine), fd);
    va_end(args);
    return result;
}

bool ServerLog::addLogWithTime(std::string format, ...)
{
    va_list args;
    va_start(args, format);
   
    time_t rawTime = time(0);
    char timeLine[TIMELENGTH + 1];
    strftime(timeLine, TIMELENGTH + 1, "%Y-%m-%d %H:%M:%S ", localtime(&rawTime));

    char logLine[MAXLENGTH];
    bool result = addLog(logLine, format, args);

    if (result){
	   char logLineWithTime[MAXLENGTH + TIMELENGTH + 1];
	   strncpy(logLineWithTime, timeLine, strlen(timeLine) + 1);
	   strcat(logLineWithTime, logLine);
	   fwrite(logLineWithTime, sizeof(char),strlen(logLineWithTime), fd);
    }
    va_end(args);
    return result;
}