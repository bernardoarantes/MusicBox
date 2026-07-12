#ifndef ENTITY
#define ENTITY

#include <string>

using std::string;

/**
 * Entity interface.
 */
class Entity {
    public:
        /**
         * @returns Internal Id from entity.
         */
        virtual string getId();

        /**
         * @returns Serialized Entity in Json format.
         */
        virtual string toJson();
};

#endif
