#ifndef ALBUMENTITY
#define ALBUMENTITY

#include "entity/Entity.cpp"
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
        AlbumEntity(const string &id, const string &title, const string &albumType, const string &release_date, const vector<string> &artistIds) :
            id(id),
            title(title),
            type(albumType),
            release_date(release_date),
            artists(artistIds) {}

        string getId() override {
            return this->id;
        }

        json toJson() override {
            string artists_str = "[";
            for (string artist : artists) {
                artists_str.append(artist).append(",");
            }
            artists_str.append("]");
            return "{\"id\":\"" + id + 
                   "\",\"title\":\"" + title +
                   "\",\"type\":" + type  +
                   "\",\"release_date\":" + release_date  +
                   "\",\"artists\":\"" + artists_str +
                   "}";
        }

};

#endif
