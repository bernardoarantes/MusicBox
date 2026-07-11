#include "Entity.cpp"
#include <vector>

using std::vector;

class AlbumEntity : Entity {
    private:
        const string id;
        const string title;
        const string type;
        const string release_date;
        const vector<string> artists;

    public:
        AlbumEntity(const string &id, const string &title, const string &albumType, const vector<string> &artistIds, unsigned duration) :
            id(id),
            title(title),
            type(albumType),
            artists(artistIds) {}

      string getId() override {
          return this->id;
      }

      string toJson() override {
          string artists_str = "[";
          for (string artist : artists) {
              artists_str.append(artist).append(",");
          }
          artists_str.append("]");
          return "{\"id\":\"" + id + 
                 "\",\"title\":\"" + title +
                 "\",\"type\":" + type  +
                 "\",\"release_date\":" + release_date  +
                 "\",\"artists\":\"" + artists_str + "}";
      }

};
