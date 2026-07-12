#ifndef DEFAULTHANDLER
#define DEFAULTHANDLER

#import "exceptions/FormatException.cpp"
#import "httplib.h"
#import "json.hpp"
#import "service/EntryService.cpp"

using httplib::Request;
using httplib::Response;
using httplib::Server;
using nlohmann::json;
using std::string;

class DefaultHandler : public Server::Handler {
    public:
        const json extract(json data, const char *field, Response &res) const {
            if (!data.contains(field)) {
                res.status = 400;
                res.set_content("{\"error\":\"Missing fields\"}", "application/json");
                throw FormatException(string(field) + " not found");
            }
            return data[field];
        }

        virtual void operator()(const Request &req, Response res);
};

#endif
