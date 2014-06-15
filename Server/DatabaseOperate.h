// This class is used to connect the mysql database server
// and operate the database
// Author: Yubin Yang
// Date: 2014-06-15

#ifndef DATABASEOPERATE_H_INCLUDE
#define DATABASEOPERATE_H_INCLUDE
#include <iostream>
#include <string>
#include "winsock.h"
#include "ServerLog.h"
#include "mysql.h"


extern ServerLog serverLog;

class DatabaseOperate
{
public:
    DatabaseOperate(std::string hostName, std::string databaseName, std::string userName, std::string userPassword, int port);

    bool databaseQuery(std::string sqlQueryStatement);
    MYSQL_RES *databaseFetchResult(std::string sqlQueryStatement);

    std::string getHostName() { return hostName; }
    std::string getDatabaseName() { return databaseName; }
    std::string getUserName() { return userName; }
    std::string getUserPassword() { return userPassword; }
    int getPortNumber() { return portNumber; }
private:
    std::string hostName;
    std::string databaseName;
    std::string userName;
    std::string userPassword;
    int portNumber;

    void inline setHostName(std::string name)
    {
	   hostName = name;
    }

    void inline setDatabaseName(std::string name)
    {
	   databaseName = name;
    }

    void inline setUserName(std::string name)
    {
	   userName = name;
    }

    void inline setUserPassword(std::string password)
    {
	   userPassword = password;
    }

    void inline setPortNumber(int port)
    {
	   portNumber = port;
    }

    MYSQL *con;
    bool buildConnection();
};

#endif