#ifndef ENTRYPARSER
#define ENTRYPARSER

#include "service/EntityParser.cpp"
#include "entity/EntryEntity.cpp"

class EntryParser : public EntityParser {
    public:
        const EntryEntity *parseJson(const json &j) const override {
            return new EntryEntity(j["id"], j["owner_id"], j["type"], j["target_id"], j["comment"], j["rating"]);
        }
};

#endif
