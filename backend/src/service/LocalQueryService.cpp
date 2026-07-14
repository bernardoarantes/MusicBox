#ifndef LOCALQUERYSERVICE
#define LOCALQUERYSERVICE

#include "exceptions/EntityNotFoundException.cpp"
#include "httplib.h"
#include "json.hpp"
#include "service/MusicQueryInterface.cpp"
#include <iostream>

using nlohmann::json;

class LocalQueryService : public MusicQueryInterface {
    json data;
    private:
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
            album["title"] = api_album["title"];
            album["type"] = api_album["type"];
            album["release_date"] = api_album["release_date"];
            album["cover"] = api_album["cover"];
            album["artists"] = api_album["artists"][0]["id"];

            return album;
        }

        const json formatArtist(const json &api_artist) const {
            json artist;
            artist["id"] = api_artist["id"];
            artist["name"] = api_artist["name"];
            return artist;
        }

    public:
        LocalQueryService(const string &file_path) {
            std::ifstream file(file_path);

            data = json::parse(file);

            file.close();
        }

        const json query(const string &type, const string &query, unsigned page = 0) override {
            json j = json::array();

            for (json item : data[type + "s"])
                if (type == "track")
                    j += formatMusic(item);
                else if (type == "album")
                    j += formatAlbum(item);
                else if (type == "artist")
                    j += formatArtist(item);

            return j;
        }

        const json findMusicByAlbum(const string &album_id, unsigned page) override {
            json j = json::array();

            for (json music : data["tracks"])
                j += formatMusic(music);

            return j;
        }


        const json findAlbumByArtist(const string &artist_id, unsigned page) override {
            json j = json::array();

            for (json album : data["albums"])
                j += formatAlbum(album);

            return j;
        }

        const json fetch(const string &type, const string &ids) override {
            json j;

            for (json item : data[type])
                if (type == "tracks" && item["id"] == ids)
                    j = formatMusic(item);
                else if (type == "albums" && item["id"] == ids)
                    j = formatAlbum(item);
                else if (type == "artists" && item["id"] == ids)
                    j = formatArtist(item);

            return j;
        }

        const json queryRandomMusics() override {
            // if (auto res_1 = cli.Get("/v1/featured-playlists?limit=1")) {
            //     json data = json::parse(res_1->body);
            //     json j = json::array();
            //     if (auto res = cli.Get(data["playlists"]["items"][0]["items"]["href"])) {
            //         for (json music : data["tracks"]["items"])
            //             j += formatMusic(music);
            //
            //         return j;
            //     } else {
            //         throw EntityNotFoundException("failed to fetch from spotify api");
            //     }
            //
            // } else {
            //     throw EntityNotFoundException("failed to fetch from spotify api");
            // }
            return json();
        }
};

#endif
