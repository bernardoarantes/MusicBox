#ifndef LISTENTRYBYMUSICHANDLER
#define LISTENTRYBYMUSICHANDLER

#include "httplib.h"
#include "json.hpp"
#include "service/EntryService.cpp"
#include "service/handler/DefaultHandler.cpp"

using httplib::Request;
using httplib::Response;
using httplib::Server;
using nlohmann::json;
using std::string;

class ListEntryByMusicHandler : public DefaultHandler {
    private:
        EntryService *entry_service;

    public:
        ListEntryByMusicHandler(EntryService &entry_service) {
            this->entry_service = &entry_service;
        }

        const json getData(const Request &req) override {
            if (!req.has_param("music_id"))
                throw FormatException("missing music_id param");

            auto a = req.get_param_value("music_id");

            return json::parse("{\"music_id\":\"" + a + "\"}");
        }

        const json handle(const json &j) override {
            const string music_id = extract(j, "music_id");
            return entry_service->fetchEntriesFromMusic(music_id);
        }
};

#endif
