#ifndef ENTITY
#define ENTITY

#include <string>
#include "json.hpp"

using std::string;
using nlohmann::json;

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
        virtual json toJson();
};

#endif
