#ifndef LOGINHANDLER
#define LOGINHANDLER

#include "httplib.h"
#include "json.hpp"
#include "service/UserService.cpp"
#include "service/handler/DefaultHandler.cpp"

using httplib::Request;
using httplib::Response;
using httplib::Server;
using nlohmann::json;
using std::string;

class LoginHandler : public DefaultHandler {
    private:
        UserService *user_service;

    public:
        LoginHandler(UserService &user_service) {
            this->user_service = &user_service;
        }

        const json handle(const json &j) override {
            const string email    = extract(j, "email");
            const string password = extract(j, "password");

            const string user_id = user_service->checkLogin(email, password);
            return json::parse("{\"user_id\":\""+ user_id + "\",\"name\":\"" + user_service->getName(user_id) + "\"}");
        }
};

#endif
