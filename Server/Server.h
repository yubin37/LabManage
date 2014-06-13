// Server Program. 
// Author: Yubin Yang
// Date: 2014-06-13
// The declaration of Server Class which provide the basic function of the Program.

#ifndef SERVER_H_INCLUDE
#define SERVER_H_INCLUDE

#include <string>
class Server {
public:

    Server(std::string hostName, int databasePort, std::string databasebUserName, std::string databaseUserPassword, int serverPort);
private:
    std::string hostName;
    int databasePort;
    std::string databaseUserName;
    std::string databaseUserPassword;
    int serverPort;
    
    void inline setHostName(std::string name) { hostName = name; }
    void inline setDatabasePort(int port) { databasePort = port; }
    void inline setDatabaseUserName(std::string name) { databaseUserName = name; }
    void inline setDatabaseUserPassword(std::string password) { databaseUserPassword = password; }
    void inline setServerPort(int port) {serverPort = port; }

    std::string inline getHostName() { return hostName; }
    int inline getDtabasePort() { return databasePort; }
    std::string inline getDatabaseUserName() { return databaseUserName; }
    std::string inline getDatabaseUserPassword() { return databaseUserPassword; }
    int inline getServerPort() { return serverPort; }

};
#endif