#ifndef MOCKQUERYSERVICE
#define MOCKQUERYSERVICE

#include "exceptions/EntityNotFoundException.cpp"
#include "json.hpp"
#include "service/MusicQueryInterface.cpp"
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using nlohmann::json;
using std::string;
using std::vector;

class MockQueryService : public MusicQueryInterface {
    private:
        vector<json> tracks;
        vector<json> albums;
        vector<json> artists;

        bool containsIgnoreCase(const string &str, const string &search) const {
            if (search.empty()) return true;
            auto it = std::search(
                str.begin(), str.end(),
                search.begin(), search.end(),
                [](char ch1, char ch2) { return std::tolower(ch1) == std::tolower(ch2); }
            );
            return it != str.end();
        }

    public:
        MockQueryService() {
            // Define 5 Artists
            artists = {
                {{"id", "art_queen"}, {"name", "Queen"}},
                {{"id", "art_daftpunk"}, {"name", "Daft Punk"}},
                {{"id", "art_billie"}, {"name", "Billie Eilish"}},
                {{"id", "art_mj"}, {"name", "Michael Jackson"}},
                {{"id", "art_beatles"}, {"name", "The Beatles"}}
            };

            // Define 5 Albums
            albums = {
                {{"id", "alb_night"}, {"title", "A Night at the Opera"}, {"type", "album"}, {"release_date", "1975-11-21"}, {"cover", "https://i.scdn.co/image/ab67616d0000b273e319b7b4c6443ab7d1ffae17"}, {"artists", "art_queen"}},
                {{"id", "alb_ram"}, {"title", "Random Access Memories"}, {"type", "album"}, {"release_date", "2013-05-17"}, {"cover", "https://i.scdn.co/image/ab67616d0000b273b331c035f8d9518d6e3c32cc"}, {"artists", "art_daftpunk"}},
                {{"id", "alb_smile"}, {"title", "WHEN WE ALL FALL ASLEEP, WHERE DO WE GO?"}, {"type", "album"}, {"release_date", "2019-03-29"}, {"cover", "https://i.scdn.co/image/ab67616d0000b27350a94ca0efaf66f36ad52b2b"}, {"artists", "art_billie"}},
                {{"id", "alb_thriller"}, {"title", "Thriller"}, {"type", "album"}, {"release_date", "1982-11-30"}, {"cover", "https://i.scdn.co/image/ab67616d0000b2734121faee31fc3c3479ad0e0e"}, {"artists", "art_mj"}},
                {{"id", "alb_abbey"}, {"title", "Abbey Road"}, {"type", "album"}, {"release_date", "1969-09-26"}, {"cover", "https://i.scdn.co/image/ab67616d0000b2733d98a0ae7c5863ad54f0e4b8"}, {"artists", "art_beatles"}}
            };

            // Define 30 Tracks
            tracks = {
                // Queen - A Night at the Opera (7 tracks)
                {{"id", "tr_bohemian"}, {"title", "Bohemian Rhapsody"}, {"album", "alb_night"}, {"cover", "https://i.scdn.co/image/ab67616d0000b273e319b7b4c6443ab7d1ffae17"}, {"duration", 354000}, {"artists", "art_queen"}},
                {{"id", "tr_youremybest"}, {"title", "You're My Best Friend"}, {"album", "alb_night"}, {"cover", "https://i.scdn.co/image/ab67616d0000b273e319b7b4c6443ab7d1ffae17"}, {"duration", 172000}, {"artists", "art_queen"}},
                {{"id", "tr_loveofmylife"}, {"title", "Love of My Life"}, {"album", "alb_night"}, {"cover", "https://i.scdn.co/image/ab67616d0000b273e319b7b4c6443ab7d1ffae17"}, {"duration", 217000}, {"artists", "art_queen"}},
                {{"id", "tr_deathontwo"}, {"title", "Death on Two Legs"}, {"album", "alb_night"}, {"cover", "https://i.scdn.co/image/ab67616d0000b273e319b7b4c6443ab7d1ffae17"}, {"duration", 223000}, {"artists", "art_queen"}},
                {{"id", "tr_39"}, {"title", "'39"}, {"album", "alb_night"}, {"cover", "https://i.scdn.co/image/ab67616d0000b273e319b7b4c6443ab7d1ffae17"}, {"duration", 211000}, {"artists", "art_queen"}},
                {{"id", "tr_imlovewithcar"}, {"title", "I'm in Love with My Car"}, {"album", "alb_night"}, {"cover", "https://i.scdn.co/image/ab67616d0000b273e319b7b4c6443ab7d1ffae17"}, {"duration", 185000}, {"artists", "art_queen"}},
                {{"id", "tr_seaside"}, {"title", "Seaside Rendezvous"}, {"album", "alb_night"}, {"cover", "https://i.scdn.co/image/ab67616d0000b273e319b7b4c6443ab7d1ffae17"}, {"duration", 135000}, {"artists", "art_queen"}},

                // Daft Punk - Random Access Memories (6 tracks)
                {{"id", "tr_getlucky"}, {"title", "Get Lucky"}, {"album", "alb_ram"}, {"cover", "https://i.scdn.co/image/ab67616d0000b273b331c035f8d9518d6e3c32cc"}, {"duration", 249000}, {"artists", "art_daftpunk"}},
                {{"id", "tr_instantcrush"}, {"title", "Instant Crush"}, {"album", "alb_ram"}, {"cover", "https://i.scdn.co/image/ab67616d0000b273b331c035f8d9518d6e3c32cc"}, {"duration", 337000}, {"artists", "art_daftpunk"}},
                {{"id", "tr_loseyourself"}, {"title", "Lose Yourself to Dance"}, {"album", "alb_ram"}, {"cover", "https://i.scdn.co/image/ab67616d0000b273b331c035f8d9518d6e3c32cc"}, {"duration", 353000}, {"artists", "art_daftpunk"}},
                {{"id", "tr_givelife"}, {"title", "Give Life Back to Music"}, {"album", "alb_ram"}, {"cover", "https://i.scdn.co/image/ab67616d0000b273b331c035f8d9518d6e3c32cc"}, {"duration", 274000}, {"artists", "art_daftpunk"}},
                {{"id", "tr_giorgio"}, {"title", "Giorgio by Moroder"}, {"album", "alb_ram"}, {"cover", "https://i.scdn.co/image/ab67616d0000b273b331c035f8d9518d6e3c32cc"}, {"duration", 544000}, {"artists", "art_daftpunk"}},
                {{"id", "tr_contact"}, {"title", "Contact"}, {"album", "alb_ram"}, {"cover", "https://i.scdn.co/image/ab67616d0000b273b331c035f8d9518d6e3c32cc"}, {"duration", 383000}, {"artists", "art_daftpunk"}},

                // Billie Eilish - WHEN WE ALL FALL ASLEEP, WHERE DO WE GO? (6 tracks)
                {{"id", "tr_badguy"}, {"title", "bad guy"}, {"album", "alb_smile"}, {"cover", "https://i.scdn.co/image/ab67616d0000b27350a94ca0efaf66f36ad52b2b"}, {"duration", 194000}, {"artists", "art_billie"}},
                {{"id", "tr_buryafriend"}, {"title", "bury a friend"}, {"album", "alb_smile"}, {"cover", "https://i.scdn.co/image/ab67616d0000b27350a94ca0efaf66f36ad52b2b"}, {"duration", 193000}, {"artists", "art_billie"}},
                {{"id", "tr_whenpartyover"}, {"title", "when the party's over"}, {"album", "alb_smile"}, {"cover", "https://i.scdn.co/image/ab67616d0000b27350a94ca0efaf66f36ad52b2b"}, {"duration", 196000}, {"artists", "art_billie"}},
                {{"id", "tr_allgoodgirls"}, {"title", "all the good girls go to hell"}, {"album", "alb_smile"}, {"cover", "https://i.scdn.co/image/ab67616d0000b27350a94ca0efaf66f36ad52b2b"}, {"duration", 168000}, {"artists", "art_billie"}},
                {{"id", "tr_wishyouweregay"}, {"title", "wish you were gay"}, {"album", "alb_smile"}, {"cover", "https://i.scdn.co/image/ab67616d0000b27350a94ca0efaf66f36ad52b2b"}, {"duration", 221000}, {"artists", "art_billie"}},
                {{"id", "tr_ilomilo"}, {"title", "ilomilo"}, {"album", "alb_smile"}, {"cover", "https://i.scdn.co/image/ab67616d0000b27350a94ca0efaf66f36ad52b2b"}, {"duration", 156000}, {"artists", "art_billie"}},

                // Michael Jackson - Thriller (6 tracks)
                {{"id", "tr_billiejean"}, {"title", "Billie Jean"}, {"album", "alb_thriller"}, {"cover", "https://i.scdn.co/image/ab67616d0000b2734121faee31fc3c3479ad0e0e"}, {"duration", 294000}, {"artists", "art_mj"}},
                {{"id", "tr_beatit"}, {"title", "Beat It"}, {"album", "alb_thriller"}, {"cover", "https://i.scdn.co/image/ab67616d0000b2734121faee31fc3c3479ad0e0e"}, {"duration", 258000}, {"artists", "art_mj"}},
                {{"id", "tr_thriller"}, {"title", "Thriller"}, {"album", "alb_thriller"}, {"cover", "https://i.scdn.co/image/ab67616d0000b2734121faee31fc3c3479ad0e0e"}, {"duration", 357000}, {"artists", "art_mj"}},
                {{"id", "tr_wannabestartin"}, {"title", "Wanna Be Startin' Somethin'"}, {"album", "alb_thriller"}, {"cover", "https://i.scdn.co/image/ab67616d0000b2734121faee31fc3c3479ad0e0e"}, {"duration", 363000}, {"artists", "art_mj"}},
                {{"id", "tr_humannature"}, {"title", "Human Nature"}, {"album", "alb_thriller"}, {"cover", "https://i.scdn.co/image/ab67616d0000b2734121faee31fc3c3479ad0e0e"}, {"duration", 246000}, {"artists", "art_mj"}},
                {{"id", "tr_pyt"}, {"title", "P.Y.T. (Pretty Young Thing)"}, {"album", "alb_thriller"}, {"cover", "https://i.scdn.co/image/ab67616d0000b2734121faee31fc3c3479ad0e0e"}, {"duration", 238000}, {"artists", "art_mj"}},

                // The Beatles - Abbey Road (5 tracks)
                {{"id", "tr_together"}, {"title", "Come Together"}, {"album", "alb_abbey"}, {"cover", "https://i.scdn.co/image/ab67616d0000b2733d98a0ae7c5863ad54f0e4b8"}, {"duration", 259000}, {"artists", "art_beatles"}},
                {{"id", "tr_something"}, {"title", "Something"}, {"album", "alb_abbey"}, {"cover", "https://i.scdn.co/image/ab67616d0000b2733d98a0ae7c5863ad54f0e4b8"}, {"duration", 182000}, {"artists", "art_beatles"}},
                {{"id", "tr_sun"}, {"title", "Here Comes the Sun"}, {"album", "alb_abbey"}, {"cover", "https://i.scdn.co/image/ab67616d0000b2733d98a0ae7c5863ad54f0e4b8"}, {"duration", 185000}, {"artists", "art_beatles"}},
                {{"id", "tr_heavy"}, {"title", "I Want You (She's So Heavy)"}, {"album", "alb_abbey"}, {"cover", "https://i.scdn.co/image/ab67616d0000b2733d98a0ae7c5863ad54f0e4b8"}, {"duration", 467000}, {"artists", "art_beatles"}},
                {{"id", "tr_darling"}, {"title", "Oh! Darling"}, {"album", "alb_abbey"}, {"cover", "https://i.scdn.co/image/ab67616d0000b2733d98a0ae7c5863ad54f0e4b8"}, {"duration", 207000}, {"artists", "art_beatles"}}
            };
        }

        const json query(const string &type, const string &query_str, unsigned page = 0) override {
            json result = json::array();
            if (type == "track") {
                for (const auto &track : tracks) {
                    string title = track["title"];
                    string artist_id = track["artists"];
                    string artist_name = "";
                    for (const auto &art : artists) {
                        if (art["id"] == artist_id) {
                            artist_name = art["name"];
                            break;
                        }
                    }
                    if (containsIgnoreCase(title, query_str) || containsIgnoreCase(artist_name, query_str)) {
                        result.push_back(track);
                    }
                }
            } else if (type == "album") {
                for (const auto &album : albums) {
                    string title = album["title"];
                    if (containsIgnoreCase(title, query_str)) {
                        result.push_back(album);
                    }
                }
            } else if (type == "artist") {
                for (const auto &artist : artists) {
                    string name = artist["name"];
                    if (containsIgnoreCase(name, query_str)) {
                        result.push_back(artist);
                    }
                }
            }
            return result;
        }

        const json findMusicByAlbum(const string &album_id, unsigned page) override {
            json result = json::array();
            for (const auto &track : tracks) {
                if (track["album"] == album_id) {
                    result.push_back(track);
                }
            }
            return result;
        }

        const json findAlbumByArtist(const string &artist_id, unsigned page) override {
            json result = json::array();
            for (const auto &album : albums) {
                if (album["artists"] == artist_id) {
                    result.push_back(album);
                }
            }
            return result;
        }

        const json fetch(const string &type, const string &ids) override {
            if (type == "tracks") {
                for (const auto &track : tracks) {
                    if (track["id"] == ids) {
                        return track;
                    }
                }
            } else if (type == "albums") {
                for (const auto &album : albums) {
                    if (album["id"] == ids) {
                        return album;
                    }
                }
            } else if (type == "artists") {
                for (const auto &artist : artists) {
                    if (artist["id"] == ids) {
                        return artist;
                    }
                }
            }
            throw EntityNotFoundException("Mock entity not found: " + type + " / " + ids);
        }

        const json queryRandomMusics() override {
            json result = json::array();
            for (size_t i = 0; i < std::min(tracks.size(), (size_t)10); ++i) {
                result.push_back(tracks[i]);
            }
            return result;
        }
};

#endif
