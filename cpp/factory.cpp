#include "factory.h"
#include "photo.h"
#include "video.h"
#include "film.h"


void Factory::registerClass(std::string key, std::function<Mulptr()> fun)
{
    if (map.find(key) == map.end())
    {
        map[key] = fun;
    }
}

Mulptr Factory::create(std::string key, std::istream& stream) 
{
    if (map.find(key) != map.end())
    {
        Mulptr objet = map[key]();
        objet->unserialize(stream);
        return objet;
    }

    return nullptr;
}
