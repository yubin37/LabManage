// Author: Yubin Yang
// Date: 23014-06-15

#include "ServerLog.h"
#include "winsock.h"
#include "mysql.h"
#include "DatabaseOperate.h"
#include <iostream>
#include <string>


extern ServerLog serverLog;

DatabaseOperate::DatabaseOperate(std::string hostName, std::string databaseName, std::string userName, std::string userPassword, int port)
{
    setHostName(hostName);
    setDatabaseName(databaseName);
    setUserName(userName);
    setUserPassword(userPassword);
    setPortNumber(port);

    if (buildConnection())
	   serverLog.addLogWithTime("%s\n", "Connect the mysql server success!");
}

bool DatabaseOperate::buildConnection()
{
    con = mysql_init((MYSQL*)0);
    if (!con) {
	   serverLog.addLogWithTime("%s\n", "Can not initialze the mysql struct!");
	   exit(EXIT_FAILURE);
    }

    mysql_real_connect(con, getHostName().c_str(),
	   getUserName().c_str(), getUserPassword().c_str(),
	   getDatabaseName().c_str(), (unsigned)getPortNumber(), NULL, 0);

    if (!con) {
	   serverLog.addLogWithTime("%s\n", "Cannot connnect the mysql server");
	   exit(EXIT_FAILURE);
    }
    return true;
}

bool DatabaseOperate::databaseQuery(std::string sqlQueryStatement)
{
    if (0 == mysql_real_query(con, sqlQueryStatement.c_str(), sqlQueryStatement.length())) {
	   serverLog.addLogWithTime("%s\n", ("Query Operation: " + sqlQueryStatement + " success!").c_str());
	   return true;
    }
    else {
	   serverLog.addLogWithTime("%s\n", ("Query Operation: " + sqlQueryStatement + " fail!").c_str());
	   return false;
    }
}

MYSQL_RES* DatabaseOperate::databaseFetchResult(std::string sqlQueryStatement)
{
    if (!databaseQuery(sqlQueryStatement)) {
	   return NULL;
    }
    else {
	   return mysql_store_result(con);
    }
}