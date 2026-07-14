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

            if (!req.has_param("target_id"))
                throw FormatException("missing 'target_id' param");

            json j;
            j["user_id"] = req.get_param_value("user_id");
            j["target_id"] = req.get_param_value("target_id");
            return j;
        }

        const json handle(const json &j) override {
            const string user_id   = extract(j, "user_id");
            const string target_id = extract(j, "target_id");
            return entry_service->checkForEntry(user_id, target_id);
        }
};

#endif
