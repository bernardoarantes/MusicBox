#ifndef FETCHQUERYHANDLER
#define FETCHQUERYHANDLER

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

class FetchQueryHandler : public DefaultHandler {
    private:
        MusicQueryInterface *music_query_interface;

    public:
        FetchQueryHandler(MusicQueryInterface &music_query_interface) {
            this->music_query_interface = &music_query_interface;
        }

        const json getData(const Request &req) override {
            if (!req.has_param("type"))
                throw FormatException("missing 'type' param");

            if (!req.has_param("query"))
                throw FormatException("missing 'query' param");

            json j;
            j["query"] = req.get_param_value("query");
            j["type"] = req.get_param_value("type");
            return j;
        }

        const json handle(const json &j) override {
            const string type        = extract(j, "type");
            const string music_query = extract(j, "query");
            return music_query_interface->fetch(type, music_query);
        }
};

#endif
