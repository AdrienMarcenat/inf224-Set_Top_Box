#include "video.h"
#include "serialize_exception.h"

Video::Video(float length, std::string name, std::string pathname)
    :Multimedia(name, pathname)
    ,length(length)
{
}

Video::~Video()
{
    std::cout << "destruction d'une vidéo" << std::endl;
}

float Video::getLength() const
{
    return length;
}

void Video::setLength(float length)
{
    this->length = length;
}

void Video::display(std::ostream& stream) const
{
    stream << "Name: " + name;
    stream << " Pathname: " + pathname;
    stream << " Length: ";
    stream <<  length;
}

void Video::play() const
{
    system(("mpv " + pathname +" &").c_str());
}

void Video::serialize(std::ostream& stream) const
{
    stream << "Video"; 
    stream << ";";
    stream << length;
    stream << ";";
    stream << name; 
    stream << ";";
    stream << pathname;
    stream << ";";
}

bool Video::unserialize(std::istream& stream)
{
    std::string args;
    getline(stream, args, ';');
    try
    {
        length = std::stof(args, nullptr);
    }
    catch(const std::exception& e)
    {
        throw SerializeException(std::string(e.what()) + " Argument is " + args);
    }
    getline(stream, name, ';');
    getline(stream, pathname, ';');

    return true;
}
