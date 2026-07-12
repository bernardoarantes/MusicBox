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

        void operator()(const Request &req, Response res) override final {
            json data = json::parse(req.body);
            const string album_query = extract(data, "query", res);
            unsigned page = extract(data, "page", res);

            const json ans = music_query_interface->findAlbumByName(album_query, page);
            res.set_content(ans.dump(), "application/json");
        }
};

#endif
