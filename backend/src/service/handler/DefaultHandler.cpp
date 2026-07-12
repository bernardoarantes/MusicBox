#ifndef DEFAULTHANDLER
#define DEFAULTHANDLER

#include "exceptions/FormatException.cpp"
#include "httplib.h"
#include "json.hpp"
#include "service/EntryService.cpp"

using httplib::Request;
using httplib::Response;
using httplib::Server;
using nlohmann::json;
using std::string;

class DefaultHandler : public Server::Handler {
    public:
        virtual ~DefaultHandler() = default;

        const json extract(json data, const char *field, Response &res) const {
            if (!data.contains(field)) {
                res.status = 400;
                res.set_content("{\"error\":\"Missing fields\"}", "application/json");
                throw FormatException(string(field) + " not found");
            }
            return data[field];
        }

        virtual void operator()(const Request &req, Response res) = 0;
};

#endif
