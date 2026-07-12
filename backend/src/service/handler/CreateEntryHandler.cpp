#ifndef CREATEENTRYHANDLER
#define CREATEENTRYHANDLER

#include "httplib.h"
#include "json.hpp"
#include "service/EntryService.cpp"
#include "service/handler/DefaultHandler.cpp"

using httplib::Request;
using httplib::Response;
using httplib::Server;
using nlohmann::json;
using std::string;

class CreateEntryHandler : public DefaultHandler {
    private:
        EntryService *entryService;

    public:
        CreateEntryHandler(EntryService &entryService) {
            this->entryService = &entryService;
        }

        const json handle(const json &j) override {
            const string user_id   = extract(j, "user_id");
            const string type      = extract(j, "type");
            const string target_id = extract(j, "target_id");
            const string comment   = extract(j, "comment");
            unsigned rating        = extract(j, "rating");
            entryService->addEntry(user_id, type, target_id, comment, rating);
            return "";
        }
};

#endif
