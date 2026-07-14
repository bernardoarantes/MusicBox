#ifndef CHECKFORENTRYHANDLER
#define CHECKFORENTRYHANDLER

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

class CheckForEntryHandler : public DefaultHandler {
    private:
        EntryService *entry_service;

    public:
        CheckForEntryHandler(EntryService &entry_service) {
            this->entry_service = &entry_service;
        }

        const json getData(const Request &req) override {
            if (!req.has_param("user_id"))
                throw FormatException("missing 'user_id' param");

            if (!req.has_param("music_id"))
                throw FormatException("missing 'track_id' param");

            json j;
            j["user_id"] = req.get_param_value("user_id");
            j["music_id"] = req.get_param_value("track_id");
            return j;
        }

        const json handle(const json &j) override {
            const string user_id  = extract(j, "user_id");
            const string track_id = extract(j, "track_id");
            return entry_service->checkForEntry(user_id, track_id);
        }
};

#endif
