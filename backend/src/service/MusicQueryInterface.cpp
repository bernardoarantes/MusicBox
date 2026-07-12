#ifndef MUSICQUERYINTERFACE
#define MUSICQUERYINTERFACE

// #include "entity/MusicEntity.cpp"
// #include "entity/AlbumEntity.cpp"
// #include "entity/ArtistEntity.cpp"
#include "json.hpp"
#include <string>

using nlohmann::json;
using std::string;

class MusicQueryInterface {
    public:
        virtual ~MusicQueryInterface() = default;

        virtual const json findMusicByName(const string &name, unsigned page) = 0;
        virtual const json findMusicByAlbum(const string &albumId, unsigned page) = 0;

        virtual const json findAlbumByName(const string &name, unsigned page) = 0;
        virtual const json findAlbumByArtist(const string &artistId, unsigned page) = 0;

        virtual const json findArtistByName(const string &name, unsigned page) = 0;
};

#endif
