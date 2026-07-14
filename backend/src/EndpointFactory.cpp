#ifndef ENDPOINTFACTORY
#define ENDPOINTFACTORY

#include "exception"
#include "httplib.h"
#include "service/UserService.cpp"
#include "service/handler/CreateEntryHandler.cpp"
#include "service/handler/CreateUserHandler.cpp"
#include "service/handler/GetUserHandler.cpp"
#include "service/handler/ListEntryByUserHandler.cpp"
#include "service/handler/ListEntryByMusicHandler.cpp"
#include "service/handler/ListRandomMusicsHandler.cpp"
#include "service/handler/LoginHandler.cpp"
#include "service/handler/SearchQueryHandler.cpp"
#include "service/handler/FetchQueryHandler.cpp"
#include "service/handler/CheckForEntryHandler.cpp"

using httplib::Request;
using httplib::Response;
using httplib::Server;
using std::string;

class EndpointFactory {
    public:
        EndpointFactory(Server &svr, EntryService &entry_service, UserService &user_service, MusicQueryInterface &music_query_interface) {
            loadEndpoints(svr, entry_service, user_service, music_query_interface);
        }

    private:
        void loadEndpoints(Server &svr, EntryService &entry_service, UserService &user_service, MusicQueryInterface &music_query_interface) {
            registerPostEndpoint(svr, "/create-entry", CreateEntryHandler(entry_service));
            registerPostEndpoint(svr, "/create-user",  CreateUserHandler(user_service));
            registerPostEndpoint(svr, "/login",        LoginHandler(user_service));

            registerGetEndpoint(svr, "/list-user-entries",  ListEntryByUserHandler(entry_service));
            registerGetEndpoint(svr, "/list-music-entries", ListEntryByMusicHandler(entry_service));
            registerGetEndpoint(svr, "/search",             SearchQueryHandler(music_query_interface));
            registerGetEndpoint(svr, "/fetch",              FetchQueryHandler(music_query_interface));
            registerGetEndpoint(svr, "/list-random-musics", ListRandomMusicsHandler(music_query_interface));
            registerGetEndpoint(svr, "/get-user",           GetUserHandler(user_service));
            registerGetEndpoint(svr, "/check-for-entry",    CheckForEntryHandler(entry_service));
        }

        void registerGetEndpoint(Server &svr, string pattern, Server::Handler handler) {
            svr.Get(pattern, handler);
        };

        void registerPostEndpoint(Server &svr, string pattern, Server::Handler handler) {
            svr.Post(pattern, handler);
        };
};

#endif
