#ifndef USERPARSER
#define USERPARSER

#include <iostream>
#include "service/EntityParser.cpp"
#include "entity/UserEntity.cpp"

class UserParser : public EntityParser {
    public:
        const UserEntity *parseJson(const json &j) const override {
            return new UserEntity(j["id"], j["email"], j["name"], j["password"]);
        }
};

#endif
