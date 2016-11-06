#ifndef TABLE_H
#define TABLE_H

#include "multimedia.h"
#include "photo.h"
#include "video.h"
#include "film.h"
#include "groupe.h"
#include "factory.h"

#include <map>
#include <string>
#include <iostream>
#include <memory>

typedef std::string Name;
typedef std::shared_ptr<Groupe> Gptr;

class Table
{
    public:

        /// Creates a new Table with empty maps.
        Table();

        /** Creates a new Photo and puts it into the multimedia table.
         * @param name the name of the Photo, wich is also the key in the multimedia table.
         * @param x the longitude of the Photo.
         * @param y the latitude of the Photo.
         * @param pathname the pathname of the Photo.
         * @see Photo.
         * @see multimediaTable.
         * @see Mulptr.
         * @return a Mulptr pointing the created Photo.
         */
        Mulptr createPhoto(Name name, float x, float y, std::string pathname = "");

        /** Creates a new Video and puts it into the multimedia table.
         * @param name the name of the Video, wich is also the key in the multimedia table.
         * @param len the length of the Video.
         * @param pathname the pathname of the Video.
         * @see Video.
         * @see multimediaTable.
         * @see Mulptr.
         * @return a Mulptr pointing the created Video.
         */
        Mulptr createVideo(Name name, float len, std::string pathname = "");
            
        /** Creates a new Film and puts it into the multimedia table.
         * @param name the name of the Film, wich is also the key in the multimedia table.
         * @param chapters a float array containing the length of each chapter.
         * @param chapterCount the total number of chapters in the Film, i.e. the size of the param chapters.
         * @param pathname the pathname of the Film.
         * @see Film.
         * @see multimediaTable.
         * @see Mulptr.
         * @return a Mulptr pointing the created Film.
         */       
        Mulptr createFilm(Name name, const float* chapters, std::size_t chapterCount, std::string pathname = "");

        /** Creates a new empty Groupe and puts it into the group table.
         * @param name the name of the Groupe, wich is also the key in the group table.
         * @see Groupe.
         * @see groupeTable.
         * @see Gptr.
         * @return a Gptr pointing the created Group.
         */  
        Gptr createGroupe(Name name);

        /** Erases, if it exists, the pointer with the the key name in both table.          
         * @param name the key of the object to erase.
         * @note Since we use shared_ptr, the pointing object is destroyed only if it was the last shared_pointer.
         */ 
        void erase(Name name);
        
        /** Finds and displays, if it exists, the attributes of the object with the given name.
         * @param name the name of the object to display.
         * @param stream the stream in which to display.
         */ 
        void find(Name name, std::ostream& stream) const;

        /** Finds and plays, if it exists, the multimedia object with the given name.
         * @param name the name of the object to play.
         */ 
        void play(Name name) const;

        /** Serializes the Table and its content by calling the serialize methods of the Multimedia and Groupe objects.
         *  The resulting string begins with "Table" and ends with "#", and for each Group or Multimedia object, 
         *  we write the name of this object and then call its serialize method. Each of these string are separated by ";"
         *  so if you have a Table containig a video named "Batman" with a length of 3.2, and a Groupe named "Movies" 
         *  contening only this video, the serialization will look like this: 
         *  "Table;Movies;Groupe;Batman;Video;3.2;Batman;;Batman;Video;3.2;Batman;; ;#".
         *  The character # is the end of the serialisation, which is useful for unserialisation.
         * @param stream the stream in which to serialize the Table.
         * @see unserialize.
         */ 
        void serialize(std::ostream& stream) const;

        /** Unserializes the Table by reading the given stream, rewriting all its attributes. It uses the factory. 
         * @param stream the stream to read.
         * @see serialize.
         * @see factory.
         * @note Groupes are not unserialized, so the groupeTable will remain empty after calling this method.
         */ 
        void unserialize(std::istream& stream);

    private:

        /// A map containing some Gptr.
        std::map<Name, Gptr> groupeTable; 
        /// A map containing some Mulptr,.
        std::map<Name, Mulptr> multimediaTable; 

        /** Used for unserialization, it can construct Mulptr.
        * @see unserialize.
        */
        Factory factory;
};

#endif // TABLE_H
