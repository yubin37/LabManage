// Server Program.
// Author: Yubin Yang
// Date: 2014-06-13

#include "Server.h"
#include <string>
#include <iostream>
#include <exception>
#include <sql.h>

Server::Server(std::string hostName , int databasePort , std::string databaseUserName, std::string databaseUserPassword, int serverPort ) {
    setHostName(hostName);
    setDatabasePort(databasePort);
    setDatabaseUserName(databaseUserName);
    setDatabaseUserPassword(databaseUserPassword);

}