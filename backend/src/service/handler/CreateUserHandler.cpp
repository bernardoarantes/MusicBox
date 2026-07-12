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

        const json handle(const json &j) override {
            const string name     = extract(j, "name");
            const string email    = extract(j, "email");
            const string password = extract(j, "password");
            userService->addUser(name, email, password);
            return "";
        }
};

#endif
