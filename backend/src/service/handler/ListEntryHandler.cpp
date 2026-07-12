#ifndef LISTENTRYHANDLER
#define LISTENTRYHANDLER

#include "httplib.h"
#include "json.hpp"
#include "service/EntryService.cpp"
#include "service/handler/DefaultHandler.cpp"

using httplib::Request;
using httplib::Response;
using httplib::Server;
using nlohmann::json;
using std::string;

class ListEntryHandler : public DefaultHandler {
    private:
        EntryService *entryService;

    public:
        ListEntryHandler(EntryService &entryService) {
            this->entryService = &entryService;
        }

        void operator()(const Request &req, Response res) override final {
            json data = json::parse(req.body);
            const string user_id = extract(data, "user_id", res);
            res.set_content(entryService->fetchEntriesFromOwner(user_id).dump(), "application/json");
        }
};

#endif
