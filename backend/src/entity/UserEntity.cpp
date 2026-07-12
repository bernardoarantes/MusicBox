#ifndef USERENTITY
#define USERENTITY

#include "entity/Entity.cpp"

class UserEntity : public Entity {
    private:
        const string id;
        const string name;
        const string password;

    public:
        UserEntity(const string &id, const string &name, const string &password) :
            id(id),
            name(name),
            password(password) {}

        const string getId() const override {
            return this->id;
        }

        json toJson() const override {
            return "{\"id\":\"" + id + 
                   "\",\"name\":\"" + name +
                   "\",\"password\":\"" + password +
                   "}";
        }

};

#endif
