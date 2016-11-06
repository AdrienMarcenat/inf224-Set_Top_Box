#include "photo.h"
#include "serialize_exception.h"

Photo::Photo(float longitude, float latitude,
             std::string name, std::string pathname)
    : Multimedia(name, pathname)
    ,longitude(longitude)
    ,latitude(latitude)
{
}

Photo::~Photo()
{
    std::cout << "destruction d'une photo" << std::endl;
}


float Photo::getLatitude() const
{
    return latitude;
}

void Photo::setLatitude(float value)
{
    latitude = value;
}
float Photo::getLongitude() const
{
    return longitude;
}

void Photo::setLongitude(float value)
{
    longitude = value;
}

void Photo::display(std::ostream& stream) const
{
    stream << "Name: " + name;
    stream << " Pathname: " + pathname;
    stream << " Longitude: ";
    stream << longitude;
    stream << " Latitude: ";
    stream << latitude;
}

void Photo::play() const
{
    system(("imagej " + pathname +" &").c_str());
}

void Photo::serialize(std::ostream& stream) const
{
    stream << "Photo"; 
    stream << ";";
    stream << longitude;
    stream << ";";
    stream << latitude;
    stream << ";";
    stream << name; 
    stream << ";";
    stream << pathname;
    stream << ";";
}

bool Photo::unserialize(std::istream& stream)
{
    std::string args;

    try
    {
        getline(stream, args, ';');
        longitude = std::stof(args, nullptr);
        getline(stream, args, ';');
        latitude  = std::stof(args, nullptr);
    }
    catch(const std::exception& e)
    {
        throw SerializeException(std::string(e.what()) + " Arguments is " + args);
    }

    getline(stream, name, ';');
    getline(stream, pathname, ';');

    return true;
}
