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
            // Define Artists
            artists = {
                {{"id", "3eVa5w3URK5duf6eyVDbu9"}, {"name", "ROSÉ"}},
                {{"id", "0du5cEVh5yTK9QJze8zA0C"}, {"name", "Bruno Mars"}},
                {{"id", "06HL4z0CvFAxyc27GXpf02"}, {"name", "Taylor Swift"}},
                {{"id", "3hv9jJF3adDNsBSIQDqcjp"}, {"name", "Mark Ronson"}},
                {{"id", "2DaxqgrOhkeH0fpeiQq2f4"}, {"name", "Oasis"}},
                {{"id", "0C0XlULifJtAgn6ZNCW2eu"}, {"name", "The Killers"}},
                {{"id", "2AsusXITU8P25dlRNhcAbG"}, {"name", "Gotye"}},
                {{"id", "4tZwfgrHOc3mvqYlEYSvVi"}, {"name", "Daft Punk"}},
                {{"id", "6eUKZXaKkcviH0Ku9w2n3V"}, {"name", "Ed Sheeran"}},
                {{"id", "5YGY8feqx7naU7z4HrwZM6"}, {"name", "Miley Cyrus"}},
                {{"id", "1mbgj8ERPs8lWi7t5cYrdy"}, {"name", "Zaz"}},
                {{"id", "4Z8W4fKeB5YxbusRsdQVPb"}, {"name", "Radiohead"}},
                {{"id", "0lAWpj5szCSwM4rUMHYmrr"}, {"name", "Måneskin"}},
                {{"id", "1hJuGCUpefX24GFmss9bjH"}, {"name", "Amy Macdonald"}},
                {{"id", "2o5jDhtHVPhrJdv3cEQ99Z"}, {"name", "Tiësto"}},
                {{"id", "329e4yvIujISKGKz1BZZbO"}, {"name", "Farruko"}},
                {{"id", "7eehGkMnqCS6Hp7HJIXH9e"}, {"name", "Crystal Rock"}},
                {{"id", "0fTSzq9jAh4c36UVb4V7CB"}, {"name", "Alex Warren"}},
                {{"id", "0cQbJU1aAzvbEmTuljWLlF"}, {"name", "No Doubt"}},
                {{"id", "1vCWHaC5f2uS3yhpwWbIA6"}, {"name", "Avicii"}},
                {{"id", "1HY2Jd0NmPuamShAr6KMms"}, {"name", "Lady Gaga"}},
                {{"id", "3OsRAKCvk37zwYcnzRf5XF"}, {"name", "Moby"}},
                {{"id", "762310PdDnwsDxAQxzQkfX"}, {"name", "Depeche Mode"}},
                {{"id", "6liAMWkVf5LH7YR9yfFy1Y"}, {"name", "Portishead"}},
                {{"id", "6rqlONGmPuP2wJVSfliLBI"}, {"name", "Peter Fox"}},
                {{"id", "0L8ExT028jH3ddEcZwqJJ5"}, {"name", "Red Hot Chili Peppers"}},
                {{"id", "0uq5PttqEjj3IH1bzwcrXF"}, {"name", "Spice Girls"}},
                {{"id", "2Cd98zHVdZeOCisc6Gi2sB"}, {"name", "Technotronic"}},
                {{"id", "2rblp9fJo16ZPTcKDtlmKW"}, {"name", "MC Hammer"}},
                {{"id", "26dSoYclwsYLMAKD3tpOr4"}, {"name", "Britney Spears"}},
                {{"id", "6olE6TJLqED3rqDCT0FyPh"}, {"name", "Nirvana"}}
            };

            // Define Albums
            albums = {
                {{"id", "2IYQwwgxgOIn7t3iF6ufFD"}, {"title", "APT."}, {"type", "album"}, {"release_date", "2024-10-18"}, {"cover", "https://i.scdn.co/image/ab67616d0000b27336032cb4acd9df050bc2e197"}, {"artists", "3eVa5w3URK5duf6eyVDbu9"}},
                {{"id", "1yGbNOtRIgdIiGHOEBaZWf"}, {"title", "1989 (Deluxe)"}, {"type", "album"}, {"release_date", "2014-01-01"}, {"cover", "https://i.scdn.co/image/ab67616d0000b27352b2a3824413eefe9e33817a"}, {"artists", "06HL4z0CvFAxyc27GXpf02"}},
                {{"id", "3vLaOYCNCzngDf8QdBg2V1"}, {"title", "Uptown Special"}, {"type", "album"}, {"release_date", "2015-01-12"}, {"cover", "https://i.scdn.co/image/ab67616d0000b2739860171ddfee17f77a570cf6"}, {"artists", "3hv9jJF3adDNsBSIQDqcjp"}},
                {{"id", "2u30gztZTylY4RG7IvfXs8"}, {"title", "(What's The Story) Morning Glory?"}, {"type", "album"}, {"release_date", "1995-10-02"}, {"cover", "https://i.scdn.co/image/ab67616d0000b2732f2eeee9b405f4d00428d84c"}, {"artists", "2DaxqgrOhkeH0fpeiQq2f4"}},
                {{"id", "4piJq7R3gjUOxnYs6lDCTg"}, {"title", "Hot Fuss"}, {"type", "album"}, {"release_date", "2004-01-01"}, {"cover", "https://i.scdn.co/image/ab67616d0000b273ccdddd46119a4ff53eaf1f5d"}, {"artists", "0C0XlULifJtAgn6ZNCW2eu"}},
                {{"id", "3Sags1sVK0ynALAsA9gPTQ"}, {"title", "Making Mirrors"}, {"type", "album"}, {"release_date", "2011-01-01"}, {"cover", "https://i.scdn.co/image/ab67616d0000b273b17e6fe9a59f8876adb9f90b"}, {"artists", "2AsusXITU8P25dlRNhcAbG"}},
                {{"id", "4m2880jivSbbyEGAKfITCa"}, {"title", "Random Access Memories"}, {"type", "album"}, {"release_date", "2013-05-20"}, {"cover", "https://i.scdn.co/image/ab67616d0000b2739b9b36b0e22870b9f542d937"}, {"artists", "4tZwfgrHOc3mvqYlEYSvVi"}},
                {{"id", "3T4tUhGYeRNVUGevb0wThu"}, {"title", "÷ (Deluxe)"}, {"type", "album"}, {"release_date", "2017-03-03"}, {"cover", "https://i.scdn.co/image/ab67616d0000b273ba5db46f4b838ef6027e6f96"}, {"artists", "6eUKZXaKkcviH0Ku9w2n3V"}},
                {{"id", "5DvJgsMLbaR1HmAI6VhfcQ"}, {"title", "Endless Summer Vacation"}, {"type", "album"}, {"release_date", "2023-08-18"}, {"cover", "https://i.scdn.co/image/ab67616d0000b27366fd0917f38d472c8576754e"}, {"artists", "5YGY8feqx7naU7z4HrwZM6"}},
                {{"id", "6MuoqipFgorIZEYwGWEFAU"}, {"title", "Zaz"}, {"type", "album"}, {"release_date", "2010-05-10"}, {"cover", "https://i.scdn.co/image/ab67616d0000b2733b5969aba116e8248a3e6369"}, {"artists", "1mbgj8ERPs8lWi7t5cYrdy"}},
                {{"id", "6dVIqQ8qmQ5GBnJ9shOYGE"}, {"title", "OK Computer"}, {"type", "album"}, {"release_date", "1997-05-28"}, {"cover", "https://i.scdn.co/image/ab67616d0000b273c8b444df094279e70d0ed856"}, {"artists", "4Z8W4fKeB5YxbusRsdQVPb"}},
                {{"id", "2qJw6w5XwQO0PQlSWPu7Tw"}, {"title", "Chosen"}, {"type", "album"}, {"release_date", "2017-12-08"}, {"cover", "https://i.scdn.co/image/ab67616d0000b273fa0ab3a28b5c52d8a5f97045"}, {"artists", "0lAWpj5szCSwM4rUMHYmrr"}},
                {{"id", "5DaToG3KvHnUgTPqY4cEbq"}, {"title", "This Is The Life (Deluxe)"}, {"type", "album"}, {"release_date", "2007-01-01"}, {"cover", "https://i.scdn.co/image/ab67616d0000b273aa2d1f1ecc9aa8f82fd56f7c"}, {"artists", "1hJuGCUpefX24GFmss9bjH"}},
                {{"id", "2adSO4KU3FDjeM1PXCRDZm"}, {"title", "The Business"}, {"type", "album"}, {"release_date", "2020-09-16"}, {"cover", "https://i.scdn.co/image/ab67616d0000b273f461bbc21a9bcec43a926973"}, {"artists", "2o5jDhtHVPhrJdv3cEQ99Z"}},
                {{"id", "2A5ksnhz7YWbRLvFMjX1j1"}, {"title", "Pepas"}, {"type", "album"}, {"release_date", "2021-06-24"}, {"cover", "https://i.scdn.co/image/ab67616d0000b2733e3957dcca26c5f4ecf015ad"}, {"artists", "329e4yvIujISKGKz1BZZbO"}},
                {{"id", "4PPyCdPF3JVlmuCqdlGPAu"}, {"title", "I'm Good (Blue)"}, {"type", "album"}, {"release_date", "2022-10-21"}, {"cover", "https://i.scdn.co/image/ab67616d0000b2732377894e1a33b519ce36ff48"}, {"artists", "7eehGkMnqCS6Hp7HJIXH9e"}},
                {{"id", "6xomx5ekO7qHDvDh57rZ5S"}, {"title", "Ordinary"}, {"type", "album"}, {"release_date", "2025-02-07"}, {"cover", "https://i.scdn.co/image/ab67616d0000b273fa2bcf3df669bde08b2e7d36"}, {"artists", "0fTSzq9jAh4c36UVb4V7CB"}},
                {{"id", "3VekjWskUut57hx6W9wqL8"}, {"title", "Tragic Kingdom"}, {"type", "album"}, {"release_date", "1995-10-10"}, {"cover", "https://i.scdn.co/image/ab67616d0000b2736ebd5e789646a833b8f7d4ba"}, {"artists", "0cQbJU1aAzvbEmTuljWLlF"}},
                {{"id", "2H6i2CrWgXE1HookLu8Au0"}, {"title", "True"}, {"type", "album"}, {"release_date", "2013-09-16"}, {"cover", "https://i.scdn.co/image/ab67616d0000b273e14f11f796cef9f9a82691a7"}, {"artists", "1vCWHaC5f2uS3yhpwWbIA6"}},
                {{"id", "2I6LyArz82waG94e9V5B9d"}, {"title", "Abracadabra"}, {"type", "album"}, {"release_date", "2025-02-03"}, {"cover", "https://i.scdn.co/image/ab67616d0000b273edd364b4d7ffb5155ccd4ca9"}, {"artists", "1HY2Jd0NmPuamShAr6KMms"}},
                {{"id", "4KZWx8zo5ym89aopr0dBIb"}, {"title", "Play"}, {"type", "album"}, {"release_date", "1999-05-17"}, {"cover", "https://i.scdn.co/image/ab67616d0000b273f675ddc7a8c113362f983f8b"}, {"artists", "3OsRAKCvk37zwYcnzRf5XF"}},
                {{"id", "0Tg76MY2wNK4j37iCb6qyH"}, {"title", "Violator (Deluxe)"}, {"type", "album"}, {"release_date", "1990-03-19"}, {"cover", "https://i.scdn.co/image/ab67616d0000b273234bbbad4dce31cd2950af3e"}, {"artists", "762310PdDnwsDxAQxzQkfX"}},
                {{"id", "3539EbNgIdEDGBKkUf4wno"}, {"title", "Dummy"}, {"type", "album"}, {"release_date", "1994-01-01"}, {"cover", "https://i.scdn.co/image/ab67616d0000b273dc20397b139223620af148f6"}, {"artists", "6liAMWkVf5LH7YR9yfFy1Y"}},
                {{"id", "6cEVfMd0XVocPbRrYkVY5H"}, {"title", "Stadtaffe"}, {"type", "album"}, {"release_date", "2008-09-26"}, {"cover", "https://i.scdn.co/image/ab67616d0000b2739061a4e47413aff8f58a3c9c"}, {"artists", "6rqlONGmPuP2wJVSfliLBI"}},
                {{"id", "30Perjew8HyGkdSmqguYyg"}, {"title", "Blood Sugar Sex Magik"}, {"type", "album"}, {"release_date", "1991-09-24"}, {"cover", "https://i.scdn.co/image/ab67616d0000b273153d79816d853f2694b2cc70"}, {"artists", "0L8ExT028jH3ddEcZwqJJ5"}},
                {{"id", "3x2jF7blR6bFHtk4MccsyJ"}, {"title", "Spice"}, {"type", "album"}, {"release_date", "1996-01-01"}, {"cover", "https://i.scdn.co/image/ab67616d0000b27363facc42e4a35eb3aa182b59"}, {"artists", "0uq5PttqEjj3IH1bzwcrXF"}},
                {{"id", "1fqUZTGqbB0o0hIFhCbAg4"}, {"title", "Pump Up The Jam"}, {"type", "album"}, {"release_date", "1989-11-28"}, {"cover", "https://i.scdn.co/image/ab67616d0000b27391f442ef24b8410ec1e68003"}, {"artists", "2Cd98zHVdZeOCisc6Gi2sB"}},
                {{"id", "4r1WecJyt5FOhglysp9zhN"}, {"title", "Please Hammer Don't Hurt 'Em"}, {"type", "album"}, {"release_date", "1990-02-20"}, {"cover", "https://i.scdn.co/image/ab67616d0000b273f5e5babccf665ef8c912b190"}, {"artists", "2rblp9fJo16ZPTcKDtlmKW"}},
                {{"id", "0z7pVBGOD7HCIB7S8eLkLI"}, {"title", "In The Zone"}, {"type", "album"}, {"release_date", "2003-11-13"}, {"cover", "https://i.scdn.co/image/ab67616d0000b273efc6988972cb04105f002cd4"}, {"artists", "26dSoYclwsYLMAKD3tpOr4"}},
                {{"id", "2UJcKiJxNryhL050F5Z1Fk"}, {"title", "Nevermind"}, {"type", "album"}, {"release_date", "1991-09-26"}, {"cover", "https://i.scdn.co/image/ab67616d0000b273fbc71c99f9c1296c56dd51b6"}, {"artists", "6olE6TJLqED3rqDCT0FyPh"}}
            };

            // Define 30 Tracks
            tracks = {
                {{"id", "5vNRhkKd0yEAg8suGBpjeY"}, {"title", "APT."}, {"album", "2IYQwwgxgOIn7t3iF6ufFD"}, {"cover", "https://i.scdn.co/image/ab67616d0000b27336032cb4acd9df050bc2e197"}, {"duration", 169917}, {"artists", "3eVa5w3URK5duf6eyVDbu9"}},
                {{"id", "0cqRj7pUJDkTCEsJkx8snD"}, {"title", "Shake It Off"}, {"album", "1yGbNOtRIgdIiGHOEBaZWf"}, {"cover", "https://i.scdn.co/image/ab67616d0000b27352b2a3824413eefe9e33817a"}, {"duration", 219200}, {"artists", "06HL4z0CvFAxyc27GXpf02"}},
                {{"id", "32OlwWuMpZ6b0aN2RZOeMS"}, {"title", "Uptown Funk"}, {"album", "3vLaOYCNCzngDf8QdBg2V1"}, {"cover", "https://i.scdn.co/image/ab67616d0000b2739860171ddfee17f77a570cf6"}, {"duration", 269658}, {"artists", "3hv9jJF3adDNsBSIQDqcjp"}},
                {{"id", "1qPbGZqppFwLwcBC1JQ6Vr"}, {"title", "Wonderwall"}, {"album", "2u30gztZTylY4RG7IvfXs8"}, {"cover", "https://i.scdn.co/image/ab67616d0000b2732f2eeee9b405f4d00428d84c"}, {"duration", 258906}, {"artists", "2DaxqgrOhkeH0fpeiQq2f4"}},
                {{"id", "003vvx7Niy0yvhvHt4a68B"}, {"title", "Mr. Brightside"}, {"album", "4piJq7R3gjUOxnYs6lDCTg"}, {"cover", "https://i.scdn.co/image/ab67616d0000b273ccdddd46119a4ff53eaf1f5d"}, {"duration", 222973}, {"artists", "0C0XlULifJtAgn6ZNCW2eu"}},
                {{"id", "6md4w95cnKaW64JyEQ3A0L"}, {"title", "Somebody That I Used To Know"}, {"album", "3Sags1sVK0ynALAsA9gPTQ"}, {"cover", "https://i.scdn.co/image/ab67616d0000b273b17e6fe9a59f8876adb9f90b"}, {"duration", 244893}, {"artists", "2AsusXITU8P25dlRNhcAbG"}},
                {{"id", "69kOkLUCkxIZYexIgSG8rq"}, {"title", "Get Lucky"}, {"album", "4m2880jivSbbyEGAKfITCa"}, {"cover", "https://i.scdn.co/image/ab67616d0000b2739b9b36b0e22870b9f542d937"}, {"duration", 369626}, {"artists", "4tZwfgrHOc3mvqYlEYSvVi"}},
                {{"id", "7qiZfU4dY1lWllzX7mPBI3"}, {"title", "Shape of You"}, {"album", "3T4tUhGYeRNVUGevb0wThu"}, {"cover", "https://i.scdn.co/image/ab67616d0000b273ba5db46f4b838ef6027e6f96"}, {"duration", 233712}, {"artists", "6eUKZXaKkcviH0Ku9w2n3V"}},
                {{"id", "7DSAEUvxU8FajXtRloy8M0"}, {"title", "Flowers"}, {"album", "5DvJgsMLbaR1HmAI6VhfcQ"}, {"cover", "https://i.scdn.co/image/ab67616d0000b27366fd0917f38d472c8576754e"}, {"duration", 200600}, {"artists", "5YGY8feqx7naU7z4HrwZM6"}},
                {{"id", "734dz1YaFITwawPpM25fSt"}, {"title", "Je veux"}, {"album", "6MuoqipFgorIZEYwGWEFAU"}, {"cover", "https://i.scdn.co/image/ab67616d0000b2733b5969aba116e8248a3e6369"}, {"duration", 215933}, {"artists", "1mbgj8ERPs8lWi7t5cYrdy"}},
                {{"id", "6LgJvl0Xdtc73RJ1mmpotq"}, {"title", "Paranoid Android"}, {"album", "6dVIqQ8qmQ5GBnJ9shOYGE"}, {"cover", "https://i.scdn.co/image/ab67616d0000b273c8b444df094279e70d0ed856"}, {"duration", 387213}, {"artists", "4Z8W4fKeB5YxbusRsdQVPb"}},
                {{"id", "3Wrjm47oTz2sjIgck11l5e"}, {"title", "Beggin'"}, {"album", "2qJw6w5XwQO0PQlSWPu7Tw"}, {"cover", "https://i.scdn.co/image/ab67616d0000b273fa0ab3a28b5c52d8a5f97045"}, {"duration", 211560}, {"artists", "0lAWpj5szCSwM4rUMHYmrr"}},
                {{"id", "2T3jgoAMbBXiMMD8pSc6QL"}, {"title", "This Is The Life"}, {"album", "5DaToG3KvHnUgTPqY4cEbq"}, {"cover", "https://i.scdn.co/image/ab67616d0000b273aa2d1f1ecc9aa8f82fd56f7c"}, {"duration", 184413}, {"artists", "1hJuGCUpefX24GFmss9bjH"}},
                {{"id", "6f3Slt0GbA2bPZlz0aIFXN"}, {"title", "The Business"}, {"album", "2adSO4KU3FDjeM1PXCRDZm"}, {"cover", "https://i.scdn.co/image/ab67616d0000b273f461bbc21a9bcec43a926973"}, {"duration", 164000}, {"artists", "2o5jDhtHVPhrJdv3cEQ99Z"}},
                {{"id", "5fwSHlTEWpluwOM0Sxnh5k"}, {"title", "Pepas"}, {"album", "2A5ksnhz7YWbRLvFMjX1j1"}, {"cover", "https://i.scdn.co/image/ab67616d0000b2733e3957dcca26c5f4ecf015ad"}, {"duration", 287120}, {"artists", "329e4yvIujISKGKz1BZZbO"}},
                {{"id", "7uOra32XyDS82JodNLhrto"}, {"title", "I'm Good (Blue)"}, {"album", "4PPyCdPF3JVlmuCqdlGPAu"}, {"cover", "https://i.scdn.co/image/ab67616d0000b2732377894e1a33b519ce36ff48"}, {"duration", 168691}, {"artists", "7eehGkMnqCS6Hp7HJIXH9e"}},
                {{"id", "6qqrTXSdwiJaq8SO0X2lSe"}, {"title", "Ordinary"}, {"album", "6xomx5ekO7qHDvDh57rZ5S"}, {"cover", "https://i.scdn.co/image/ab67616d0000b273fa2bcf3df669bde08b2e7d36"}, {"duration", 186964}, {"artists", "0fTSzq9jAh4c36UVb4V7CB"}},
                {{"id", "6urCAbunOQI4bLhmGpX7iS"}, {"title", "Don't Speak"}, {"album", "3VekjWskUut57hx6W9wqL8"}, {"cover", "https://i.scdn.co/image/ab67616d0000b2736ebd5e789646a833b8f7d4ba"}, {"duration", 263560}, {"artists", "0cQbJU1aAzvbEmTuljWLlF"}},
                {{"id", "0nrRP2bk19rLc0orkWPQk2"}, {"title", "Wake Me Up"}, {"album", "2H6i2CrWgXE1HookLu8Au0"}, {"cover", "https://i.scdn.co/image/ab67616d0000b273e14f11f796cef9f9a82691a7"}, {"duration", 247426}, {"artists", "1vCWHaC5f2uS3yhpwWbIA6"}},
                {{"id", "5ZLUm9eab8y3tqQ1OhQSHI"}, {"title", "Abracadabra"}, {"album", "2I6LyArz82waG94e9V5B9d"}, {"cover", "https://i.scdn.co/image/ab67616d0000b273edd364b4d7ffb5155ccd4ca9"}, {"duration", 223398}, {"artists", "1HY2Jd0NmPuamShAr6KMms"}},
                {{"id", "6EXi6ZqTITKGtVBKqbphjL"}, {"title", "Porcelain"}, {"album", "4KZWx8zo5ym89aopr0dBIb"}, {"cover", "https://i.scdn.co/image/ab67616d0000b273f675ddc7a8c113362f983f8b"}, {"duration", 241160}, {"artists", "3OsRAKCvk37zwYcnzRf5XF"}},
                {{"id", "1JekRMGQ8iN4G1AAdh0SBa"}, {"title", "Enjoy the Silence"}, {"album", "0Tg76MY2wNK4j37iCb6qyH"}, {"cover", "https://i.scdn.co/image/ab67616d0000b273234bbbad4dce31cd2950af3e"}, {"duration", 372826}, {"artists", "762310PdDnwsDxAQxzQkfX"}},
                {{"id", "3Ty7OTBNSigGEpeW2PqcsC"}, {"title", "Glory Box"}, {"album", "3539EbNgIdEDGBKkUf4wno"}, {"cover", "https://i.scdn.co/image/ab67616d0000b273dc20397b139223620af148f6"}, {"duration", 308626}, {"artists", "6liAMWkVf5LH7YR9yfFy1Y"}},
                {{"id", "7A4KdLy1DXOOC5fhIdDuHz"}, {"title", "Haus am See"}, {"album", "6cEVfMd0XVocPbRrYkVY5H"}, {"cover", "https://i.scdn.co/image/ab67616d0000b2739061a4e47413aff8f58a3c9c"}, {"duration", 216000}, {"artists", "6rqlONGmPuP2wJVSfliLBI"}},
                {{"id", "3d9DChrdc6BOeFsbrZ3Is0"}, {"title", "Under the Bridge"}, {"album", "30Perjew8HyGkdSmqguYyg"}, {"cover", "https://i.scdn.co/image/ab67616d0000b273153d79816d853f2694b2cc70"}, {"duration", 264306}, {"artists", "0L8ExT028jH3ddEcZwqJJ5"}},
                {{"id", "1Je1IMUlBXcx1Fz0WE7oPT"}, {"title", "Wannabe"}, {"album", "3x2jF7blR6bFHtk4MccsyJ"}, {"cover", "https://i.scdn.co/image/ab67616d0000b27363facc42e4a35eb3aa182b59"}, {"duration", 173026}, {"artists", "0uq5PttqEjj3IH1bzwcrXF"}},
                {{"id", "21qnJAMtzC6S5SESuqQLEK"}, {"title", "Pump Up The Jam"}, {"album", "1fqUZTGqbB0o0hIFhCbAg4"}, {"cover", "https://i.scdn.co/image/ab67616d0000b27391f442ef24b8410ec1e68003"}, {"duration", 320306}, {"artists", "2Cd98zHVdZeOCisc6Gi2sB"}},
                {{"id", "1B75hgRqe7A4fwee3g3Wmu"}, {"title", "U Can't Touch This"}, {"album", "4r1WecJyt5FOhglysp9zhN"}, {"cover", "https://i.scdn.co/image/ab67616d0000b273f5e5babccf665ef8c912b190"}, {"duration", 257359}, {"artists", "2rblp9fJo16ZPTcKDtlmKW"}},
                {{"id", "6I9VzXrHxO9rA9A5euc8Ak"}, {"title", "Toxic"}, {"album", "0z7pVBGOD7HCIB7S8eLkLI"}, {"cover", "https://i.scdn.co/image/ab67616d0000b273efc6988972cb04105f002cd4"}, {"duration", 198800}, {"artists", "26dSoYclwsYLMAKD3tpOr4"}},
                {{"id", "4CeeEOM32jQcH3eN9Q2dGj"}, {"title", "Smells Like Teen Spirit"}, {"album", "2UJcKiJxNryhL050F5Z1Fk"}, {"cover", "https://i.scdn.co/image/ab67616d0000b273fbc71c99f9c1296c56dd51b6"}, {"duration", 301920}, {"artists", "6olE6TJLqED3rqDCT0FyPh"}}
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
                if (!tracks.empty()) {
                    json fallback = tracks[0];
                    fallback["id"] = ids;
                    fallback["title"] = fallback["title"].get<string>() + " (Fallback)";
                    return fallback;
                }
            } else if (type == "albums") {
                for (const auto &album : albums) {
                    if (album["id"] == ids) {
                        return album;
                    }
                }
                if (!albums.empty()) {
                    json fallback = albums[0];
                    fallback["id"] = ids;
                    fallback["title"] = fallback["title"].get<string>() + " (Fallback)";
                    return fallback;
                }
            } else if (type == "artists") {
                for (const auto &artist : artists) {
                    if (artist["id"] == ids) {
                        return artist;
                    }
                }
                if (!artists.empty()) {
                    json fallback = artists[0];
                    fallback["id"] = ids;
                    fallback["name"] = fallback["name"].get<string>() + " (Fallback)";
                    return fallback;
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
