#ifndef CREATEENTRYHANDLER
#define CREATEENTRYHANDLER

#include "exceptions/FormatException.cpp"
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

        void operator()(const Request &req, Response res) override final {
            json data = json::parse(req.body);
            const string user_id   = extract(data, "user_id", res);
            const string type      = extract(data, "type", res);
            const string target_id = extract(data, "target_id", res);
            const string comment   = extract(data, "comment", res);
            unsigned rating        = extract(data, "rating", res);
            entryService->addEntry(user_id, type, target_id, comment, rating);
        }
};

#endif
