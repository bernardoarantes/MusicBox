#ifndef ENDPOINTFACTORY
#define ENDPOINTFACTORY

#include "httplib.h"
#include "exception"
#include "service/handler/CreateEntryHandler.cpp"
#include "service/UserService.cpp"

using httplib::Request;
using httplib::Response;
using httplib::Server;
using std::string;

class EndpointFactory {
    public:
        EndpointFactory(Server &svr, EntryService &entryService, UserService &userService) {
            loadEndpoints(svr, entryService, userService);
        }

    private:
        void loadEndpoints(Server &svr, EntryService &entryService, UserService &userService) {
            registerEndpoint(svr, new CreateEntryHandler(entryService), "/create-entry");
        }

        void registerEndpoint(Server &svr, Server::Handler *handler, string pattern) {
            svr.Get(pattern, *handler);
            new std::exception();
        };
};

#endif
