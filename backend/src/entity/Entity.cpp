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
        virtual ~Entity() = default;

        /**
         * @returns Internal Id from entity.
         */
        virtual const string getId() const = 0;

        /**
         * @returns Serialized Entity in Json format.
         */
        virtual json toJson() const = 0;

};

#endif
