#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H

#include <string>
#include <iostream>
#include <memory> 


class Multimedia
{
    public:

        /// Creates a Multimedia object, but since this class is pure virtual, it cannot be instanciated.
        Multimedia();
        /// The super constructor called by the deriving classes.
        Multimedia(std::string name, std::string pathame);
        /// Virtual destructor.
        virtual ~Multimedia();

        /** Rewrites the attribute name.
        * @param name the new name.
        * @see name.
        */
        void setName(std::string name);
        
        /** Getter for the attribute name.
        * @see name.
        * @return the attribute name.
        */
        std::string getName() const;

        /** Rewrites the attribute pathname.
        * @param pathname the new pathname.
        * @see pathname.
        */
        void setPathName(std::string pathname);

        /** Getter for the attribute pathname.
         * @see pathname.
         * @return the attribute pathname.
         */
        std::string getPathName() const;

        /** Displays the attributes of this object in a stream.
         * @param stream the stream in which to write.
         */
        virtual void display(std::ostream& stream) const;
         
        /** Plays this object. This method is pure virtual, leading this class to be abstract too.
         */
        virtual void play() const = 0;
        
        /** Serializes this object in a given stream.
         * @param stream the stream in which to write.
         */
        virtual void serialize(std::ostream& stream) const = 0;

        /** Unserializes this object by reading a given stream, rewriting all attributes.
         * @param stream the stream to read.
         */
        virtual bool unserialize(std::istream& stream) = 0;

    protected:
        /// The name of the Multimedia object, used by the class Table. Default value is "";
        std::string name;
        /// The path of this object. Default value is "".
        std::string pathname;
};

/// We use shared_ptr to manipulate Multimedia objects.
typedef std::shared_ptr<Multimedia> Mulptr;

#endif // MULTIMEDIA_H
