#ifndef GROUPE_H
#define GROUPE_H

#include <list>
#include <string>
#include <iostream>

#include "multimedia.h"


class Groupe: public std::list<Mulptr>
{
    public:
        /// Creates an emtpy Groupe.
        Groupe(std::string name);

        /** Getter for the attribute name.
         * \see name.
         * \return the attribute name.
         */
        std::string getName() const;

        /** Displays the ame of the Groupe and the attributes of the Multimedia object within.
         * \param stream the stream in which to write.
         * \note this method calls the display method of the contained object.
         */
        void display(std::ostream &stream) const;

        /** Serializes the Groupe and its content by calling the serialize methods of the contained Multimedia objects.
         * \param stream the stream in which to serialize the Groupe.
         * \see unserialize.
         */ 
        void serialize(std::ostream& stream) const;

        /// Unimplemented.
        bool unserialize(std::istream& stream) const;

    private:
        /// The name of this Groupe. Used in the class Table.
        std::string name;

};

#endif //GROUPE_H
