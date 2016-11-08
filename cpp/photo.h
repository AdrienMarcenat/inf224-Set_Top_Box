#ifndef PHOTO_H
#define PHOTO_H

#include "multimedia.h"
#include "table.h"

class Photo: public Multimedia
{
    public:
        /// Creates a Video.
        Photo(float longitude, float latitude,
              std::string name = "", std::string pathname = "");
        // Destructor.
        virtual ~Photo();

        /** Getter for the attribute latitude
         * \see latitude.
         * \return the attribute latitude.
         */
        float getLatitude() const;
        
        /** Rewrites the attribute latitude
         * \param value the new latitude.
         * \see latitude.
         */
        void setLatitude(float value);
        
        /** Getter for the attribute longitude
         * \see longitude.
         * \return the attribute longitude.
         */
        float getLongitude() const;
        
        /** Rewrites the attribute longitude
         * \param value the new longitude.
         * \see longitude.
         */
        void setLongitude(float value);

        /** Displays the attributes of this object in a stream.
         * \param stream the stream in which to write.
         */
        virtual void display(std::ostream& stream) const;
        
        /** Plays this object. 
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
        /// Longitude of the Photo, default value is 0.
        float longitude = 0;
        /// Latitude of the Photo, default value is 0.
        float latitude = 0;

        void* operator new(std::size_t); 

};


#endif // PHOTO_H
