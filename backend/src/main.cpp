#define CPPHTTPLIB_OPENSSL_SUPPORT
#include "httplib.h"
#include "EndpointFactory.cpp"
#include "service/RegistryService.cpp"
#include "service/UserParser.cpp"
#include "service/UserService.cpp"
#include "service/EntryParser.cpp"
#include "service/EntryService.cpp"
#include "service/MusicQueryInterface.cpp"
#include "service/SpotifyAPIQueryService.cpp"
#include "service/persistence/Repository.cpp"
#include <cstdlib>

#define ENTRIES_PATH "data/entries.jsonl"
#define USERS_PATH "data/users.jsonl"

int main() {
    httplib::Server svr;

    const char* spotify_api_key_env = std::getenv("SPOTIFY_API_KEY");
    std::string spotify_api_key = spotify_api_key_env ? spotify_api_key_env : "SOME_KEY";

    Repository users(USERS_PATH, UserParser());
    Repository entries(ENTRIES_PATH, EntryParser());

    Workspace workspace(users, entries);
    RegistryService registry(users.size(), entries.size());

    UserService user_service(workspace, registry);
    EntryService entry_service(workspace, registry);

    SpotifyAPIQueryService spotify_api_query_service(spotify_api_key);

    EndpointFactory endpoint_factory(svr, entry_service, user_service, spotify_api_query_service);

    svr.set_pre_routing_handler([](const httplib::Request &req, httplib::Response &res) {
            res.set_header("Access-Control-Allow-Origin", "*"); 
            res.set_header("Access-Control-Allow-Methods", "POST, GET, OPTIONS, PUT, DELETE");
            res.set_header("Access-Control-Allow-Headers", "Content-Type, Authorization");

            if (req.method == "OPTIONS") {
                res.status = 200;
                return httplib::Server::HandlerResponse::Handled;
            }
            return httplib::Server::HandlerResponse::Unhandled;
        });
    svr.listen("0.0.0.0", 8080);
}

