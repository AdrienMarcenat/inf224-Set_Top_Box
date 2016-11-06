#include "film.h"
#include "serialize_exception.h"

Film::Film(const float* chapters, std::size_t chapterCount,
           std::string name, std::string pathname)
    : Video(0, name, pathname)
    , chapters(nullptr)
    , chapterCount(chapterCount)
{
    setChapters(chapters, chapterCount);

    int l = 0;
    for (std::size_t i = 0; i < chapterCount; i++)
    {
        l += chapters[i];
    }
    setLength(l);
}

Film::Film(Film const& film_copie) //Copy constructor, avoid to have a same pointer shared by two instances of a same Film.
    : Video(film_copie.getLength())
    , chapters(nullptr)
    , chapterCount(0)
{
    setChapters(film_copie.chapters, film_copie.chapterCount);   
}

Film& Film::operator=(Film const& film_copie)
{ 
    Video::operator=(film_copie);
    setChapters(film_copie.chapters, film_copie.chapterCount);
    setLength(film_copie.getLength());

    return *this;
}

Film::~Film()
{ 
    std::cout << "Film destroyed" << std::endl;
    delete [] chapters;
}

const float* Film::getChapters() const
{
    return chapters;
}

void Film::setChapters(const float* value, const std::size_t size)
{
    if(chapters != nullptr)
        delete [] chapters;
    chapters = new float[size];
    chapterCount = size;
    for (std::size_t i = 0; i < size; i++)
    {
        chapters[i] = value[i];
    }
}

const std::size_t Film::getChapterLength(int num) const
{
    return chapters[num];
}

std::size_t Film::getChapterCount() const
{
    return chapterCount;
}

void Film::display(std::ostream& stream) const
{
    stream << "Name: " + name;
    stream << " Pathname: " + pathname;
    stream << " Number of chapters: ";
    stream << chapterCount;
    stream << " Chapters_length: ";
    for (std::size_t i = 0; i < chapterCount; i++)
    {
        stream << chapters[i];
        if (i != chapterCount - 1)
            stream << ", ";
    }
}

void Film::serialize(std::ostream& stream) const
{
    stream << "Film"; 
    stream << ";";
    stream << chapterCount;
    stream << ";";
    for (std::size_t i = 0; i < chapterCount; i++)
    {
        stream << chapters[i] << ";";
    }
    stream << name; 
    stream << ";";
    stream << pathname;
    stream << ";";
}

bool Film::unserialize(std::istream& stream)
{
    std::string args;
    getline(stream, args, ';');
    try
    {
        chapterCount = std::stof(args, nullptr);

        if(chapters != nullptr)
            delete [] chapters;
        chapters = new float[chapterCount];

        for (std::size_t i = 0; i < chapterCount; i++)
        {
            getline(stream, args, ';');
            chapters[i] = std::stof(args, nullptr);
        }
    }
    catch(const std::exception& e)
    {
        throw SerializeException(std::string(e.what()) + " Arguments is " + args);
    }

    getline(stream, name, ';');
    getline(stream, pathname, ';');

    return true;
}
