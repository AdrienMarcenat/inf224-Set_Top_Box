#ifndef VIDEO_H
#define VIDEO_H

#include "multimedia.h"
#include "table.h"

class Video: public Multimedia
{
    public:
        /// Creates a Video.
        Video(float length,
              std::string name = "", std::string pathname = "");
        /// Destructor.
        virtual ~Video();

        /** Getter for the attribute length.
         * \return length.
         * \see length.
         */
        float getLength() const;

        /** Rewrites the attribute length.
         * \param length the new length.
         * \see length.
         */
        void setLength(float length);

        /** Displays the attributes of this object in a given stream.
         * \param stream the stream in which to write.
         */
        virtual void display(std::ostream& stream) const;

        /** Plays this object
         */
        virtual void play() const;

        /** Serializes this object in a given stream.
         * \param stream the stream in which to write.
         */
        virtual void serialize(std::ostream& stream) const;

        /** Unserializes this object by reading a given stream, rewriting all attributes.
         * \param stream the stream to read.
         */
        virtual bool unserialize(std::istream& stream);

    private:

        /// The length of this video, default value is 0;
        float length = 0;

        void* operator new(std::size_t);
        friend Mulptr Table::createVideo(Name, float,  std::string); 
};

#endif // VIDEO_H
