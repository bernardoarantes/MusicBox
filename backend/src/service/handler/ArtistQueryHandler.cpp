#ifndef ARTISTQUERYHANDLER
#define ARTISTQUERYHANDLER

#include "httplib.h"
#include "json.hpp"
#include "service/MusicQueryInterface.cpp"
#include "service/handler/DefaultHandler.cpp"

using httplib::Request;
using httplib::Response;
using httplib::Server;
using nlohmann::json;
using std::string;

class ArtistQueryHandler : public DefaultHandler {
    private:
        MusicQueryInterface *music_query_interface;

    public:
        ArtistQueryHandler(MusicQueryInterface &music_query_interface) {
            this->music_query_interface = &music_query_interface;
        }

        const json handle(const json &j) override {
            const string artist_query = extract(j, "query");
            unsigned page             = extract(j, "page");
            return  music_query_interface->findMusicByName(artist_query, page);
        }
};

#endif
