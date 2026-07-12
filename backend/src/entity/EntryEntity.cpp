#ifndef ENTRYENTITY
#define ENTRYENTITY

#include "entity/Entity.cpp"
#include <vector>

using std::vector;

class EntryEntity : Entity {
    private:
        const string id;
        const string owner_id;
        const string type;
        const string target_id;
        const string comment;
        const unsigned rating;

    public:
        EntryEntity(const string &id, const string& owner_id, const string &type, const string &target_id, const string &comment, unsigned rating) :
            id(id),
            owner_id(owner_id),
            type(type),
            target_id(target_id),
            comment(comment),
            rating(rating) {}

        string getId() override {
            return this->id;
        }

        string getOwnerId() {
            return this->getOwnerId();
        }

        string toJson() override {
            return "{\"id\":\"" + id + 
                   "\",\"type\":\"" + type +
                   "\",\"target_id\":\"" + target_id +
                   "\",\"comment\":\"" + comment +
                   "\",\"rating\":\"" + std::to_string(rating) +
                   "}";
        }

};

#endif
