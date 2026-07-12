#ifndef CREATEUSERHANDLER
#define CREATEUSERHANDLER

#include "httplib.h"
#include "json.hpp"
#include "service/UserService.cpp"
#include "service/handler/DefaultHandler.cpp"

using httplib::Request;
using httplib::Response;
using httplib::Server;
using nlohmann::json;
using std::string;

class CreateUserHandler : public DefaultHandler {
    private:
        UserService *userService;

    public:
        CreateUserHandler(UserService &userService) {
            this->userService = &userService;
        }

        void operator()(const Request &req, Response res) override final {
            json data = json::parse(req.body);
            const string name     = extract(data, "name", res);
            const string password = extract(data, "password", res);
            userService->addUser(name, password);
        }
};

#endif
