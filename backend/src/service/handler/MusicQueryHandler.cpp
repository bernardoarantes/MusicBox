#ifndef MUSICQUERYHANDLER
#define MUSICQUERYHANDLER

#import "httplib.h"
#import "json.hpp"
#import "service/MusicQueryInterface.cpp"
#import "service/handler/DefaultHandler.cpp"

using httplib::Request;
using httplib::Response;
using httplib::Server;
using nlohmann::json;
using std::string;

class MusicQueryHandler : public DefaultHandler {
    private:
        MusicQueryInterface *music_query_interface;

    public:
        MusicQueryHandler(MusicQueryInterface &music_query_interface) {
            this->music_query_interface = &music_query_interface;
        }

        void operator()(const Request &req, Response res) override final {
            json data = json::parse(req.body);
            const string music_query = extract(data, "query", res);
            unsigned page = extract(data, "page", res);

            const json ans = music_query_interface->findMusicByName(music_query, page);
            res.set_content(ans.dump(), "application/json");
        }
};

#endif
