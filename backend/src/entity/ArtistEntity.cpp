#include "Entity.cpp"
#include <vector>
#include <format>

using std::vector;

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

      string toJson() override {
          return "{\"id\":\"" + id + 
                 "\",\"name\":\"" + name + "}";
      }

};
