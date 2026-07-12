#ifndef ARTISTENTITY
#define ARTISTENTITY

#include "entity/Entity.cpp"

class ArtistEntity : Entity {
    private:
        const string id;
        const string name;

    public:
        ArtistEntity(const string &id, const string &name) :
            id(id),
            name(name) {}

        string getId() override {
            return this->id;
        }

        json toJson() override {
            return "{\"id\":\"" + id + 
                   "\",\"name\":\"" + name +
                   "}";
        }

};

#endif
