#ifndef ENTITYPARSER
#define ENTITYPARSER

#include "entity/Entity.cpp"
#include <json.hpp>

using nlohmann::json;

class EntityParser {
    public:
        virtual const Entity *parseJson(const json &j) const = 0;
};

#endif
