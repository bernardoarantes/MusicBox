#ifndef MUSICQUERYINTERFACE
#define MUSICQUERYINTERFACE

#include "entity/MusicEntity.cpp"
#include "entity/AlbumEntity.cpp"
#include "entity/ArtistEntity.cpp"
#include "json.hpp"

using nlohmann::json;

class MusicQueryInterface {
    public:
        virtual const json findMusicByName(const string &name, unsigned page);
        virtual const json findMusicByAlbum(const string &albumId, unsigned page);
        virtual const json findMusicByArtist(const string &artistId, unsigned page);

        virtual const json findAlbumByName(const string &name, unsigned page);
        virtual const json findAlbumByArtist(const string &artistId, unsigned page);

        virtual const json findArtistByName(const string &name, unsigned page);
};

#endif
