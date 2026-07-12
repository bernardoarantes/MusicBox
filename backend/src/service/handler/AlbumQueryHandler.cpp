#ifndef LISTALBUMSHANDLER
#define LISTALBUMSHANDLER

#include "httplib.h"
#include "json.hpp"
#include "service/MusicQueryInterface.cpp"
#include "service/handler/DefaultHandler.cpp"

using httplib::Request;
using httplib::Response;
using httplib::Server;
using nlohmann::json;
using std::string;

class AlbumQueryHandler : public DefaultHandler {
    private:
        MusicQueryInterface *music_query_interface;

    public:
        AlbumQueryHandler(MusicQueryInterface &music_query_interface) {
            this->music_query_interface = &music_query_interface;
        }

        const json handle(const json &j) override {
            const string album_query = extract(j, "query");
            unsigned page            = extract(j, "page");
            return music_query_interface->findAlbumByName(album_query, page);
        }
};

#endif
