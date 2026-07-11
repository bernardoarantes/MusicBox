#include "Entity.cpp"
#include <vector>

using std::vector;

class UserEntity : Entity {
    private:
        const string id;
        const string name;
        const string password;

    public:
        UserEntity(const string &id, const string &name, const string &password) :
            id(id),
            name(name),
            password(password) {}

        string getId() override {
            return this->id;
        }

        string toJson() override {
            return "{\"id\":\"" + id + 
                   "\",\"name\":\"" + name +
                   "}";
        }

};
