#ifndef DEFAULTHANDLER
#define DEFAULTHANDLER

#include "exceptions/ValidationException.cpp"
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

        const json extract(const json &data, const char *field) const {
            if (!data.contains(field))
                throw FormatException(string(field) + " not found");
            return data[field];
        }

        virtual const json handle(const json &data) = 0;

        void operator()(const Request &req, Response res) {
            try {
                json data = json::parse(req.body);
                json j = handle(data);
                res.status = 200;
                res.set_content(j.dump(), "json");
            } catch (FormatException e) {
                res.status = 400;
                res.set_content(e.what(), "error");
            } catch (ValidationException e) {
                res.status = 400;
                res.set_content(e.what(), "error");
            }
        }
};

#endif
