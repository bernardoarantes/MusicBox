#ifndef MUSICENTITY
#define MUSICENTITY

#include "entity/Entity.cpp"
#include <vector>

using std::vector;

class MusicEntity : Entity {
    private:
        const string id;
        const string title;
        const string album;
        const unsigned duration;
        const vector<string> artists;

    public:
        MusicEntity(const string &id, const string &title, const string &albumId, const vector<string> &artistIds, unsigned duration) :
            id(id),
            title(title),
            album(albumId),
            duration(duration),
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
                   "\",\"album\":\"" + album +
                   "\",\"artists\":\"" + artists_str +
                   "\",\"duration_ms\":" + std::to_string(duration) +
                   "}";
        }

};

#endif
