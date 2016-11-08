#ifndef FACTORY_H
#define FACTORY_H

#include "multimedia.h"
#include <string>
#include <map>
#include <functional>
#include <iostream>

class Factory
{
    private:
        /// Map containing lambda functions which create Mulptr.
        std::map<std::string, std::function<Mulptr()> > map;

    public:
        /** Adds a new entry in map.
         * \param key the key associated with the function.
         * \param fun the function associated with the key.
         */
        void registerClass(std::string key, std::function<Mulptr()> fun);

        /** Creates a Mulptr by calling the function associated with key, and unserializes the pointed object with the given stream.
         * \param key the key associated with the desired function.
         * \param stream the stream to unserialize the created object.
         * return a Mulptr pointing an unserialized object.
         */
        Mulptr create(std::string key, std::istream& stream);
};

#endif // FACTORY_H
