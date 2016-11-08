#include "multimedia.h"

Multimedia::Multimedia()
{
}

Multimedia::Multimedia(std::string name, std::string pathname)
    : name(name)
    , pathname(pathname)
{
}

Multimedia::~Multimedia()
{
}

void Multimedia::setName(std::string name)
{
    this->name = name;
}

std::string Multimedia::getName() const
{
    return name;
}

void Multimedia::setPathName(std::string pathname)
{
    this->pathname = pathname;
}

std::string Multimedia::getPathName() const
{
    return pathname;
}

void Multimedia::display(std::ostream& stream) const
{
    stream << "name: " + name + " pathname: " + pathname;
    stream << std::endl;
}

std::ostream& Multimedia::operator<<(std::ostream& os)
{
    serialize(os);
    return os;
}

std::istream& Multimedia::operator>>(std::istream& is)
{
    unserialize(is);
    return is;
}
