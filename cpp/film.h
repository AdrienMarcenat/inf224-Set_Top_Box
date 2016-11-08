#ifndef FILM_H
#define FILM_H

#include "video.h"
#include "table.h"
#include <vector>
#include <cstddef>


class Film: public Video
{
    public:
        /// Creates a Film, use the method setChapter() to cpoy the given float array.
        Film(const float* chapters, std::size_t chapterCount,
             std::string name = "", std::string pathname = "");
        /// Copy constructor, allows to copy an existing Film without sharing the same array(pointer) of chapters,
        //  which would have been an issue when deleted the original or the copy.
        Film(Film const& film_copie); 
        /// We redefine the operator = to avoid the issue discussed in the copy constructor.
        Film& operator=(Film const& film_copie); 
        /// Destructor, delete the entire array chapters (no memory leak).
        virtual ~Film();

        /** Getter for the attribute chapters.
         * \see chapters.
         * \return the attribute chapters.
         * \note we return it with const, so the array is not mutable outside the object.
         */
        const float* getChapters() const; 

        /** Rewrites the attribute chapters and chapterCount by copying a given float array.
         * \param value the new chapters.
         * \param chapterCount the new size of chapters.
         * \see chapters.
         * \see chapterCount.
         */
        void setChapters(const float* value, const std::size_t chapterCount);
        
        /** Get the length of a specific chapter, if it exist.
         * \param num the number of the chapter.
         * \return the length of .
         */
        const std::size_t  getChapterLength(int num) const;

        /** Getter for the attribute chapterCount.
         * \see chapterCount.
         * \return the attribute chapterCount.
         */
        std::size_t  getChapterCount() const;

        /** Displays the attributes of this object in a stream.
         * \param stream the stream in which to write.
         */
        virtual void display(std::ostream &stream) const;
        
        /** Serializes this object in a given stream.
         * \param stream the stream in which to write.
         */
        virtual void serialize(std::ostream& stream) const;
        
        /** Unserializes this object by reading a given stream, rewriting all attributes.
         * \param stream the stream to read.
         */
        virtual bool unserialize(std::istream& stream);

    private:

        /// A float array containing the length of each chapter.
        float* chapters;
        /// The size of chapters.
        std::size_t chapterCount;

        void* operator new(std::size_t);
};

#endif // FILM_H
