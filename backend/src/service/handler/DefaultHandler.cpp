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

    protected:
        const json extract(const json &data, const char *field) const {
            if (!data.contains(field))
                throw FormatException(string(field) + " not found");
            return data[field];
        }


        virtual const json handle(const json &data) = 0;

        virtual const json getData(const Request &req) {
            return json::parse(req.body);
        }

    public:
        void operator()(const Request &req, Response &res) {
            try {
                json data = getData(req);
                json j = handle(data);
                res.status = 200;
                res.set_content(j.dump(), "text/plain");
            } catch (FormatException e) {
                res.status = 400;
                res.set_content(e.what(), "text/plain");
            } catch (ValidationException e) {
                res.status = 400;
                res.set_content(e.what(), "text/plain");
            }
        }
};

#endif
