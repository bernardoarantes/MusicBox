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

#define ENTRIES_PATH "data/entries.jsonl"
#define USERS_PATH "data/users.jsonl"
#define API_KEY "SOME_KEY"

int main() {
    httplib::Server svr;


    Repository users(USERS_PATH, UserParser());
    Repository entries(ENTRIES_PATH, EntryParser());

    Workspace workspace(users, entries);
    RegistryService registry(users.size(), entries.size());

    UserService user_service(workspace, registry);
    EntryService entry_service(workspace, registry);

    SpotifyAPIQueryService spotify_api_query_service(API_KEY);

    EndpointFactory endpoint_factory(svr, entry_service, user_service, spotify_api_query_service);

    svr.listen("0.0.0.0", 8080);
}

