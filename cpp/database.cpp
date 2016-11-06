#include "database.h"


bool DataBase::processRequest(TCPConnection& cnx, const std::string& request, std::string& response)
{
    std::cerr << "\nRequest: '" << request << "'" << std::endl;

    std::stringstream stream(request);
    std::string cmd;
    std::string arg;
    while(!stream.eof())
    {   
        std::getline(stream, cmd, ' '); // The command's name
        std::getline(stream, arg, ' '); // The object's name

        if (commands.find(cmd) != commands.end())
        {
            std::stringstream answer;
            commands[cmd](arg, answer);  
            response = cmd + " " + arg + ": " + answer.str(); 
        }
        if (cmd == "close") // Close the connection if the request is "close"
            return false;  
    }

    std::cerr << "response: " << response << std::endl;

    return true;
}

void DataBase::registerCommand(std::string name, std::function<void(Name, std::ostream&)> fun)
{
    if (commands.find(name) == commands.end())
        commands[name] = fun;  
};
