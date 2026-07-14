#ifndef GETUSERHANDLER
#define GETUSERHANDLER

#include "httplib.h"
#include "json.hpp"
#include "service/UserService.cpp"
#include "service/handler/DefaultHandler.cpp"

using httplib::Request;
using httplib::Response;
using httplib::Server;
using nlohmann::json;
using std::string;

class GetUserHandler : public DefaultHandler {
    private:
        UserService *user_service;

    public:
        GetUserHandler(UserService &user_service) {
            this->user_service = &user_service;
        }

        const json getData(const Request &req) override {
            if (!req.has_param("user_id"))
                throw FormatException("missing user_id param");

            json j;
            j["user_id"] = req.get_param_value("user_id");
            return j;
        }

        const json handle(const json &j) override {
            const string user_id = extract(j, "user_id");
            const string name = user_service->getName(user_id);
            return json::parse("{\"name\":\"" + name + "\"}");
        }
};

#endif
