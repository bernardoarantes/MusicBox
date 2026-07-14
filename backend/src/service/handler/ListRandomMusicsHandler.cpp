#ifndef LISTRANDOMMUSICHANDLER
#define LISTRANDOMMUSICHANDLER

#include "httplib.h"
#include "json.hpp"
#include "service/MusicQueryInterface.cpp"
#include "service/handler/DefaultHandler.cpp"
#include <sstream>

using httplib::Request;
using httplib::Response;
using httplib::Server;
using nlohmann::json;
using std::string;

class ListRandomMusicsHandler : public DefaultHandler {
    private:
        MusicQueryInterface *music_query_interface;

    public:
        ListRandomMusicsHandler(MusicQueryInterface &music_query_interface) {
            this->music_query_interface = &music_query_interface;
        }
        const json handle(const json &j) override {
            return music_query_interface->queryRandomMusics();
        }
};

#endif
