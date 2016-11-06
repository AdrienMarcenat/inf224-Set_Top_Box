#include "groupe.h"

Groupe::Groupe(std::string name)
    : name(name)
{
    
}

std::string Groupe::getName() const
{
    return name;
}

void Groupe::display(std::ostream &stream) const
{
    for (auto& m : *this)
    {
        m->display(stream);
    }
}

void Groupe::serialize(std::ostream& stream) const
{
    stream << "Groupe";
    stream << ";";
    for (auto& m : *this)
    {
        m->serialize(stream);
    }
}
