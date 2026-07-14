#ifndef MUSICQUERYINTERFACE
#define MUSICQUERYINTERFACE

#include "json.hpp"
#include <string>

using nlohmann::json;
using std::string;

class MusicQueryInterface {
    public:
        virtual ~MusicQueryInterface() = default;

        virtual const json query(const string &type, const string &query, unsigned page = 0) = 0;

        virtual const json findMusicByAlbum(const string &albumId, unsigned page) = 0;

        virtual const json findAlbumByArtist(const string &artistId, unsigned page) = 0;

        virtual const json fetch(const string &type, const string &ids) = 0;

        virtual const json queryRandomMusics() = 0;
};

#endif
