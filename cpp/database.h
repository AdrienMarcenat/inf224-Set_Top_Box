#include <vector>
#include <memory>
#include <string>
#include <iostream>
#include <sstream>

#include "tcpserver.h"
#include "table.h"

using namespace cppu;

const int PORT = 3331;

class DataBase 
{
    public:
      
        /** Reads the commands sent to the server, executes them, and writes the answer.
         *@param cnx .
         *@param request the request sent to the server.
         *@param response the response sent to the client.
         */
        bool processRequest(TCPConnection& cnx, const std::string& request, std::string& response);

        /** Registers in the map commands a new command associated with a name. 
         * @param name the key associated with th command.
         * @param fun the commands to register.
         * @see commands.
         */
        void registerCommand(std::string name, std::function<void(Name, std::ostream&)> fun); 
       
    private:
        /// Contains the server's command.
        std::map<std::string, std::function<void(Name, std::ostream&)> > commands; };

