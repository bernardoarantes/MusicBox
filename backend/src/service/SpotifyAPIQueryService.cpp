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
            music["cover"] = api_music["album"]["images"][0]["url"];
            music["duration"] = api_music["duration_ms"];
            music["artists"] = api_music["artists"][0]["id"];

            return music;
        }

        const json formatAlbum(const json &api_album) const {
            json album;
            album["id"] = api_album["id"];
            album["title"] = api_album["name"];
            album["type"] = api_album["type"];
            album["release_date"] = api_album["release_date"];
            album["cover"] = api_album["images"][0]["url"];
            album["artists"] = api_album["artists"][0]["id"];

            return album;
        }

        const json formatArtist(const json &api_artist) const {
            json artist;
            artist["id"] = api_artist["id"];
            artist["name"] = api_artist["name"];
            return artist;
        }

    public : SpotifyAPIQueryService(const string &api_key)
             : api_key(api_key) {}

             const json query(const string &type, const string &query, unsigned page = 0) override {
                 if (auto res = cli.Get("/v1/search?limit=10&q=" + query + "&type=" + type + "&offset=" + std::to_string(10 * page), getHeaders())) {
                     json data = json::parse(res->body);
                     json j = json::array();

                     for (json item : data[type + "s"]["items"])
                         if (type == "track")
                             j += formatMusic(item);
                         else if (type == "album")
                             j += formatAlbum(item);
                         else if (type == "artist")
                             j += formatArtist(item);

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

             const json fetch(const string &type, const string &ids) override {
                 if (auto res = cli.Get("/v1/" + type + "/" + ids, getHeaders())) {
                     json data = json::parse(res->body);
                     json j;
                     string dat = data.dump();

                         if (type == "tracks")
                             j = formatMusic(data);
                         else if (type == "albums")
                             j = formatAlbum(data);
                         else if (type == "artists")
                             j = formatArtist(data);

                     return j;

                 } else {
                     throw EntityNotFoundException("failed to fetch from spotify api");
                 }
             }

             const json queryRandomMusics() override {
                 if (auto res_1 = cli.Get("/v1/featured-playlists?limit=1")) {
                     json data = json::parse(res_1->body);
                     json j = json::array();
                     if (auto res = cli.Get(data["playlists"]["items"][0]["items"]["href"])) {
                         for (json music : data["tracks"]["items"])
                             j += formatMusic(music);

                         return j;
                     } else {
                         throw EntityNotFoundException("failed to fetch from spotify api");
                     }

                 } else {
                     throw EntityNotFoundException("failed to fetch from spotify api");
                 }
             }
};

#endif
