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
