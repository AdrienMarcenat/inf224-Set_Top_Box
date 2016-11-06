#ifndef SERIALIZE_EXCEPTION_H
#define SERIALIZE_EXCEPTION_H
#include <exception>
#include <string>

class SerializeException: public std::exception
{
    public:
        enum Status{NO_NAME_FOUND};

        SerializeException();
        SerializeException(Status status);
        SerializeException(std::string error);
        virtual ~SerializeException();

        const char* what() const throw() override
        {
            return std::string("SerializeException : " + message).c_str();
        }

    private:
        std::string message;
};
#endif /* SERIALIZE_EXCEPTION_H */
