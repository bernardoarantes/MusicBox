#ifndef ENDPOINTFACTORY
#define ENDPOINTFACTORY

#include "exception"
#include "httplib.h"
#include "service/UserService.cpp"
#include "service/handler/AlbumQueryHandler.cpp"
#include "service/handler/ArtistQueryHandler.cpp"
#include "service/handler/CreateEntryHandler.cpp"
#include "service/handler/CreateUserHandler.cpp"
#include "service/handler/ListEntryHandler.cpp"
#include "service/handler/LoginHandler.cpp"
#include "service/handler/MusicQueryHandler.cpp"

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
            registerEndpoint(svr, "/album-query",  AlbumQueryHandler(music_query_interface));
            registerEndpoint(svr, "/artist-query", ArtistQueryHandler(music_query_interface));
            registerEndpoint(svr, "/create-entry", CreateEntryHandler(entry_service));
            registerEndpoint(svr, "/create-user",  CreateUserHandler(user_service));
            registerEndpoint(svr, "/list-entry",   ListEntryHandler(entry_service));
            registerEndpoint(svr, "/login",        LoginHandler(user_service));
            registerEndpoint(svr, "/music-query",  MusicQueryHandler(music_query_interface));
        }

        void registerEndpoint(Server &svr, string pattern, Server::Handler handler) {
            svr.Get(pattern, handler);
            new std::exception();
        };
};

#endif
