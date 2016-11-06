#include "serialize_exception.h"

SerializeException::SerializeException()
    : message("")
{

};

SerializeException::SerializeException(std::string error)
    : message(error)
{

};

SerializeException::SerializeException(Status status) 
{
    switch(status) 
    {
        case SerializeException::NO_NAME_FOUND:
            message = "No name found";
            break;
        default:
            message = "Unknown error";
    }
}

SerializeException::~SerializeException() 
{

}
