#include "Entity.cpp"
#include <vector>

using std::vector;

class EntryEntity : Entity {
    private:
        const string id;
        const string type;
        const string target_id;
        const string comment;
        const unsigned rating;

    public:
        EntryEntity(const string &id, const string &type, const string &target_id, const string &comment, unsigned rating) :
            id(id),
            type(type),
            target_id(target_id),
            comment(comment),
            rating(rating) {}

        string getId() override {
            return this->id;
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
