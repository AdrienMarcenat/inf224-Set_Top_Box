#include "table.h"
#include "factory.h"

Table::Table()
{
    factory.registerClass("Photo", 
            [] {
                return std::make_shared<Photo>(0, 0);  
            });
    
    factory.registerClass("Video", 
            [] {
                return std::make_shared<Video>(0);  
            });

    factory.registerClass("Film", 
            [] {
                return std::make_shared<Film>(nullptr, 0);  
            });

}

Mulptr Table::createPhoto(Name name, float x, float y, std::string pathname)
{
    Mulptr photo = std::make_shared<Photo>(x, y, name, pathname);
    multimediaTable.insert(std::make_pair(name, photo));

    return photo;
}

Mulptr Table::createVideo(Name name, float len, std::string pathname)
{
    Mulptr video = std::make_shared<Video>(len, name, pathname);
    multimediaTable.insert(std::make_pair(name, video));

    return video;
}

Mulptr Table::createFilm(Name name, const float* chapters, std::size_t chapterCount, std::string pathname)
{
    Mulptr film = std::make_shared<Film>(chapters, chapterCount, name, pathname);
    multimediaTable.insert(std::make_pair(name, film));

    return film;
}

Gptr Table::createGroupe(Name name)
{
    Gptr groupe = std::make_shared<Groupe>(name);
    groupeTable.insert(std::make_pair(name, groupe));

    return groupe;
}

void Table::erase(Name name)
{
    if(multimediaTable.find(name) != multimediaTable.end())
    {
        Mulptr mul = multimediaTable[name];
        for (auto g : groupeTable)
        {
            g.second->remove(mul);         
        }
        multimediaTable.erase(name);
    }

    if (groupeTable.find(name) != groupeTable.end())
    {
        groupeTable.erase(name);
    }
}

void Table::find(Name name, std::ostream& stream) const 
{
    auto mul = multimediaTable.find(name);
    if(mul != multimediaTable.end())
    {
        (*mul).second->display(stream);
    }
    
    auto g = groupeTable.find(name);
    if (g != groupeTable.end())
    {
        stream << name << " : ";
        (*g).second->display(stream);
    }
}

void Table::play(Name name) const 
{
    auto mul = multimediaTable.find(name);
    if(mul != multimediaTable.end())
    {
       (*mul).second->play();
    }
}

// On ne sérialise que la table des objets
void Table::serialize(std::ostream& stream) const
{
    stream << "Table";
    stream << ";";
    for(auto mul : multimediaTable)
    {
        stream << mul.first; // Le nom de l'objet
        stream << ";";
        mul.second->serialize(stream);
    }
    stream << " ;";
    stream << "#"; /* Mot-clef pour signaler la fin de la sérialisation d'une table
                             utile pour désérialiser un table */
}

void Table::unserialize(std::istream& stream) 
{
    std::map<Name, Mulptr> new_multimediaTable;
    //std::map<Name, Gptr> new_groupeTable;
    std::string name;
    std::string type;
    getline(stream, name, ';');
    getline(stream, type, ';');
    while(type != "#")
    {
        if (type == "Groupe")
        {

        }
        else
        {
            Mulptr objet = factory.create(type, stream);
            new_multimediaTable.insert(std::make_pair(name, objet));
        }
        getline(stream, name, ';');
        getline(stream, type, ';');
    }
    multimediaTable = new_multimediaTable;
    //groupeTable = new_groupeTable;
}
