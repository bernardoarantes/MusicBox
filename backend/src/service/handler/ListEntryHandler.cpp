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
        EntryService *entry_service;

    public:
        ListEntryHandler(EntryService &entry_service) {
            this->entry_service = &entry_service;
        }

        const json handle(const json &j) override {
            const string user_id = extract(j, "user_id");
            return entry_service->fetchEntriesFromOwner(user_id);
        }
};

#endif
