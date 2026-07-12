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

        const json formatMusic(const json &api_music) const {
            json music;
            music["id"] = api_music["id"];
            music["title"] = api_music["name"];
            music["album"] = api_music["album"]["id"];
            music["duration"] = api_music["duration"];
            music["artists"] = json::array();

            for (json artist : api_music["artists"])
                music["artists"] += artist["id"];

            return music;
        }

        const json formatAlbum(const json &api_album) const {
            json album;
            album["id"] = api_album["id"];
            album["title"] = api_album["name"];
            album["type"] = api_album["type"];
            album["release_date"] = api_album["release_date"];
            album["artists"] = json::array();

            for (json artist : api_album["artists"]) {
                album["artists"] += artist["id"];
            }

            return album;
        }

        const json formatArtist(const json &api_artist) const {
            json artist;
            artist["id"] = api_artist["id"];
            artist["name"] = api_artist["name"];
            return artist;
        }

    public:
        SpotifyAPIQueryService(const string &api_key) :
            api_key(api_key) {}

        const json findMusicByName(const string &name, unsigned page) override {
            if (auto res = cli.Get("/v1/search?q=" + name + "&type=track&offset=" + std::to_string(10 * page), getHeaders())) {
                json data = json::parse(res->body);
                json j = json::array();

                for (json music : data["tracks"]["items"])
                    j += formatMusic(music);

                return j;
            } else {
                throw EntityNotFoundException("failed to fetch from spotify api");
            }
        }

        const json findMusicByAlbum(const string &album_id, unsigned page) override {
            if (auto res = cli.Get("/v1/albums/" + album_id + "/tracks?offset=" + std::to_string(10 * page), getHeaders())) {
                json data = json::parse(res->body);
                json j = json::array();

                for (json music : data["tracks"]["items"])
                    j += formatMusic(music);

                return j;
            } else {
                throw EntityNotFoundException("failed to fetch from spotify api");
            }
        }

        const json findAlbumByName(const string &name, unsigned page) override {
            if (auto res = cli.Get("/v1/search?q=" + name + "&type=album&offset=" + std::to_string(10 * page), getHeaders())) {
                json data = json::parse(res->body);
                json j = json::array();

                for (json album : data["albums"]["items"]) {
                    j += formatAlbum(album);
                }

                return j;
            } else {
                throw EntityNotFoundException("failed to fetch from spotify api");
            }
        }

        const json findAlbumByArtist(const string &artist_id, unsigned page) override {
            if (auto res = cli.Get("/v1/artist/" + artist_id + "/albums?offset=" + std::to_string(10 * page), getHeaders())) {
                json data = json::parse(res->body);
                json j = json::array();

                for (json album : data["albums"]["items"]) {
                    j += formatAlbum(album);
                }

                return j;
            } else {
                throw EntityNotFoundException("failed to fetch from spotify api");
            }
        }

        const json findArtistByName(const string &name, unsigned page) override {
            if (auto res = cli.Get("/v1/search?q=" + name + "&type=artist&offset=" + std::to_string(10 * page), getHeaders())) {
                json data = json::parse(res->body);
                json j = json::array();

                for (json artist : data["artists"]["items"]) {
                    j += formatArtist(artist);
                }

                return j;
            } else {
                throw EntityNotFoundException("failed to fetch from spotify api");
            }
        }
};

#endif
