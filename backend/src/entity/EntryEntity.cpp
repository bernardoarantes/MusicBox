#ifndef ENTRYENTITY
#define ENTRYENTITY

#include "entity/Entity.cpp"

class EntryEntity : public Entity {
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

        const string getId() const override {
            return this->id;
        }

        string getOwnerId() {
            return this->owner_id;
        }

        json toJson() const override {
            return "{\"id\":\"" + id + 
                   "\",\"owner_id\":\"" + owner_id +
                   "\",\"type\":\"" + type +
                   "\",\"target_id\":\"" + target_id +
                   "\",\"comment\":\"" + comment +
                   "\",\"rating\":\"" + std::to_string(rating) +
                   "}";
        }

};

#endif
