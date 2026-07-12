#ifndef SPOTIFYAPIQUERYSERVICE
#define SPOTIFYAPIQUERYSERVICE

#include "exceptions/EntityNotFoundException.cpp"
#include "httplib.h"
#include "json.hpp"
#include "service/MusicQueryInterface.cpp"
#include <iostream>

#define SPOTIFY_ENDPOINT "https://api.spotify.com"

using httplib::Client;
using httplib::Headers;
using nlohmann::json;

class SpotifyAPIQueryService : public MusicQueryInterface {
    private:
        Client cli = Client(SPOTIFY_ENDPOINT);
        string api_key;

        Headers getHeaders() const {
            return {
                { "Authorization", "Bearer " + api_key},
            };
        }

    public:
        SpotifyAPIQueryService(const string &api_key) :
            api_key(api_key) {}

        const json findMusicByName(const string &name, unsigned page) override {
            if (auto res = cli.Get("/v1/search?q=" + name + "&type=track&offset=" + std::to_string(10 * page), getHeaders())) {
                json data = json::parse(res->body);
                json response = json();

                for (json music : data["tracks"]["items"]) {
                    response["id"] = music["id"];
                    response["title"] = music["name"];
                    response["album"] = music["album"]["id"];
                    response["duration"] = music["duration"];
                    response["artists"] = json::array();

                    for (json artist : music["artists"]) {
                        response["artists"] += artist["id"];
                    }
                }
                return response;
            } else {
                throw EntityNotFoundException("failed to fetch from spotify api");
            }
        }

        const json findMusicByAlbum(const string &album_id, unsigned page) override {
            if (auto res = cli.Get("/v1/albums/" + album_id + "/tracks?offset=" + std::to_string(10 * page), getHeaders())) {
                json data = json::parse(res->body);
                json response = json();

                for (json music : data["items"]) {
                    response["id"] = music["id"];
                    response["title"] = music["name"];
                    response["album"] = album_id;
                    response["duration"] = music["duration"];
                    response["artists"] = json::array();

                    for (json artist : music["artists"]) {
                        response["artists"] += artist["id"];
                    }
                }

                return response;
            } else {
                throw EntityNotFoundException("failed to fetch from spotify api");
            }
        }

        const json findAlbumByName(const string &name, unsigned page) override {
            if (auto res = cli.Get("/v1/search?q=" + name + "&type=album&offset=" + std::to_string(10 * page), getHeaders())) {
                json data = json::parse(res->body);
                json response = json();

                for (json album : data["albums"]["items"]) {
                    response["id"] = album["id"];
                    response["title"] = album["name"];
                    response["type"] = album["type"];
                    response["release_date"] = album["release_date"];
                    response["artists"] = json::array();

                    for (json artist : album["artists"]) {
                        response["artists"] += artist["id"];
                    }
                }

                return response;
            } else {
                throw EntityNotFoundException("failed to fetch from spotify api");
            }
        }

        const json findAlbumByArtist(const string &artist_id, unsigned page) override {
            if (auto res = cli.Get("/v1/artist/" + artist_id + "/albums?offset=" + std::to_string(10 * page), getHeaders())) {
                json data = json::parse(res->body);
                json response = json();

                for (json album : data["items"]) {
                    response["id"] = album["id"];
                    response["title"] = album["name"];
                    response["type"] = album["type"];
                    response["release_date"] = album["release_date"];
                    response["artists"] = json::array();

                    for (json artist : album["artists"]) {
                        response["artists"] += artist["id"];
                    }
                }

                return response;
            } else {
                throw EntityNotFoundException("failed to fetch from spotify api");
            }
        }

        const json findArtistByName(const string &name, unsigned page) override {
            if (auto res = cli.Get("/v1/search?q=" + name + "&type=artist&offset=" + std::to_string(10 * page), getHeaders())) {
                json data = json::parse(res->body);
                json response = json();

                for (json album : data["artists"]["items"]) {
                    response["id"] = album["id"];
                    response["name"] = album["name"];
                }

                return response;
            } else {
                throw EntityNotFoundException("failed to fetch from spotify api");
            }
        }
};

#endif
