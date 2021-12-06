//
// Created by Hamza El-Kebir on 12/4/21.
//

#ifndef SUZUME_TILEUTILS_HPP
#define SUZUME_TILEUTILS_HPP

#include "Tile.hpp"

#define CREATE_TILE_INFO(TILE, CAT, NUMBER, SUITS, TERMINAL, RED, WINDS, DRAGONS) \
template <> \
struct TileInfo<TILE> { \
    static const TileCategories cat = CAT; \
    static const int number = NUMBER; \
    static const bool suits = SUITS; \
    static const bool terminal = TERMINAL; \
    static const bool red = RED; \
    static const bool winds = WINDS; \
    static const bool dragons = DRAGONS; \
    static const bool honors = (WINDS || DRAGONS); \
}

#define MAKE_TILE_INFO_MAP(CONTENT) \
class TileInfoMap {   \
public:                                   \
    static const std::map <Tiles, TileInfoDyn> map; \
    static const TileInfoDyn get(Tiles tile)                \
    {                                     \
        try {                             \
            return map.at(tile);         \
        } catch (std::out_of_range &e) {  \
            return {};                 \
        };                                \
    }                               \
    template <Languages TLanguage> \
    static const TileInfoDyn get(const Tile<TLanguage> * tile)                \
    {                                     \
        try {                             \
            return map.at(tile->getTile()); \
        } catch (std::out_of_range &e) {  \
            return {};                 \
        };                                \
    }                                     \
private:                                  \
    static std::map<Tiles, TileInfoDyn> createMap() \
    { \
        std::map<Tiles, TileInfoDyn> m;   \
        CONTENT                           \
        return m;                         \
    }                                     \
};

#define INIT_TILE_INFO_MAP() \
const std::map <Tiles, TileInfoDyn> TileInfoMap::map = TileInfoMap::createMap()

#define ADD_TILE_INFO_MAP_ENTRY(TILE) \
m[TILE] = TileInfoDyn{TileInfo<TILE>::cat, TileInfo<TILE>::number, TileInfo<TILE>::suits, TileInfo<TILE>::terminal, TileInfo<TILE>::red, TileInfo<TILE>::winds, TileInfo<TILE>::dragons, TileInfo<TILE>::honors};

namespace szm {
    template <Tiles tile>
    struct TileInfo;

    struct TileInfoDyn {
        TileInfoDyn() {}

        TileInfoDyn(TileCategories cat_, int number_, bool suits_, bool terminal_, bool red_, bool winds_, bool dragons_, bool honors_) :
        cat(cat_), number(number_), suits(suits_), terminal(terminal_), red(red_), winds(winds_), dragons(dragons_), honors(honors_)
        {
            honors = (winds_ || dragons_);
        }

        TileCategories cat;
        int number;
        bool suits;
        bool terminal;
        bool red;
        bool winds;
        bool dragons;
        bool honors;
    };

    CREATE_TILE_INFO(Tiles::Man1, TileCategories::Manzu, 1, true, true, false, false, false);
    CREATE_TILE_INFO(Tiles::Man2, TileCategories::Manzu, 2, true, false, false, false, false);
    CREATE_TILE_INFO(Tiles::Man3, TileCategories::Manzu, 3, true, false, false, false, false);
    CREATE_TILE_INFO(Tiles::Man4, TileCategories::Manzu, 4, true, false, false, false, false);
    CREATE_TILE_INFO(Tiles::Man5, TileCategories::Manzu, 5, true, false, false, false, false);
    CREATE_TILE_INFO(Tiles::ManR5, TileCategories::Manzu, 5, true, false, true, false, false);
    CREATE_TILE_INFO(Tiles::Man6, TileCategories::Manzu, 6, true, false, false, false, false);
    CREATE_TILE_INFO(Tiles::Man7, TileCategories::Manzu, 7, true, false, false, false, false);
    CREATE_TILE_INFO(Tiles::Man8, TileCategories::Manzu, 8, true, false, false, false, false);
    CREATE_TILE_INFO(Tiles::Man9, TileCategories::Manzu, 9, true, true, false, false, false);

    CREATE_TILE_INFO(Tiles::Pin1, TileCategories::Pinzu, 1, true, true, false, false, false);
    CREATE_TILE_INFO(Tiles::Pin2, TileCategories::Pinzu, 2, true, false, false, false, false);
    CREATE_TILE_INFO(Tiles::Pin3, TileCategories::Pinzu, 3, true, false, false, false, false);
    CREATE_TILE_INFO(Tiles::Pin4, TileCategories::Pinzu, 4, true, false, false, false, false);
    CREATE_TILE_INFO(Tiles::Pin5, TileCategories::Pinzu, 5, true, false, false, false, false);
    CREATE_TILE_INFO(Tiles::PinR5, TileCategories::Pinzu, 5, true, false, true, false, false);
    CREATE_TILE_INFO(Tiles::Pin6, TileCategories::Pinzu, 6, true, false, false, false, false);
    CREATE_TILE_INFO(Tiles::Pin7, TileCategories::Pinzu, 7, true, false, false, false, false);
    CREATE_TILE_INFO(Tiles::Pin8, TileCategories::Pinzu, 8, true, false, false, false, false);
    CREATE_TILE_INFO(Tiles::Pin9, TileCategories::Pinzu, 9, true, true, false, false, false);

    CREATE_TILE_INFO(Tiles::Sou1, TileCategories::Souzu, 1, true, true, false, false, false);
    CREATE_TILE_INFO(Tiles::Sou2, TileCategories::Souzu, 2, true, false, false, false, false);
    CREATE_TILE_INFO(Tiles::Sou3, TileCategories::Souzu, 3, true, false, false, false, false);
    CREATE_TILE_INFO(Tiles::Sou4, TileCategories::Souzu, 4, true, false, false, false, false);
    CREATE_TILE_INFO(Tiles::Sou5, TileCategories::Souzu, 5, true, false, false, false, false);
    CREATE_TILE_INFO(Tiles::SouR5, TileCategories::Souzu, 5, true, false, true, false, false);
    CREATE_TILE_INFO(Tiles::Sou6, TileCategories::Souzu, 6, true, false, false, false, false);
    CREATE_TILE_INFO(Tiles::Sou7, TileCategories::Souzu, 7, true, false, false, false, false);
    CREATE_TILE_INFO(Tiles::Sou8, TileCategories::Souzu, 8, true, false, false, false, false);
    CREATE_TILE_INFO(Tiles::Sou9, TileCategories::Souzu, 9, true, true, false, false, false);

    CREATE_TILE_INFO(Tiles::Ton, TileCategories::Fonpai, 1, false, false, false, true, false);
    CREATE_TILE_INFO(Tiles::Nan, TileCategories::Fonpai, 2, false, false, false, true, false);
    CREATE_TILE_INFO(Tiles::Sha, TileCategories::Fonpai, 3, false, false, false, true, false);
    CREATE_TILE_INFO(Tiles::Pei, TileCategories::Fonpai, 4, false, false, false, true, false);

    CREATE_TILE_INFO(Tiles::Haku, TileCategories::Sangenpai, 1, false, false, false, false, true);
    CREATE_TILE_INFO(Tiles::Hatu, TileCategories::Sangenpai, 2, false, false, false, false, true);
    CREATE_TILE_INFO(Tiles::Chun, TileCategories::Sangenpai, 3, false, false, false, false, true);

    MAKE_TILE_INFO_MAP(
    ADD_TILE_INFO_MAP_ENTRY(Tiles::Man1)
            ADD_TILE_INFO_MAP_ENTRY(Tiles::Man2)
            ADD_TILE_INFO_MAP_ENTRY(Tiles::Man3)
            ADD_TILE_INFO_MAP_ENTRY(Tiles::Man4)
            ADD_TILE_INFO_MAP_ENTRY(Tiles::Man5)
            ADD_TILE_INFO_MAP_ENTRY(Tiles::ManR5)
            ADD_TILE_INFO_MAP_ENTRY(Tiles::Man6)
            ADD_TILE_INFO_MAP_ENTRY(Tiles::Man7)
            ADD_TILE_INFO_MAP_ENTRY(Tiles::Man8)
            ADD_TILE_INFO_MAP_ENTRY(Tiles::Man9)
            ADD_TILE_INFO_MAP_ENTRY(Tiles::Pin1)
            ADD_TILE_INFO_MAP_ENTRY(Tiles::Pin2)
            ADD_TILE_INFO_MAP_ENTRY(Tiles::Pin3)
            ADD_TILE_INFO_MAP_ENTRY(Tiles::Pin4)
            ADD_TILE_INFO_MAP_ENTRY(Tiles::Pin5)
            ADD_TILE_INFO_MAP_ENTRY(Tiles::PinR5)
            ADD_TILE_INFO_MAP_ENTRY(Tiles::Pin6)
            ADD_TILE_INFO_MAP_ENTRY(Tiles::Pin7)
            ADD_TILE_INFO_MAP_ENTRY(Tiles::Pin8)
            ADD_TILE_INFO_MAP_ENTRY(Tiles::Pin9)
            ADD_TILE_INFO_MAP_ENTRY(Tiles::Sou1)
            ADD_TILE_INFO_MAP_ENTRY(Tiles::Sou2)
            ADD_TILE_INFO_MAP_ENTRY(Tiles::Sou3)
            ADD_TILE_INFO_MAP_ENTRY(Tiles::Sou4)
            ADD_TILE_INFO_MAP_ENTRY(Tiles::Sou5)
            ADD_TILE_INFO_MAP_ENTRY(Tiles::SouR5)
            ADD_TILE_INFO_MAP_ENTRY(Tiles::Sou6)
            ADD_TILE_INFO_MAP_ENTRY(Tiles::Sou7)
            ADD_TILE_INFO_MAP_ENTRY(Tiles::Sou8)
            ADD_TILE_INFO_MAP_ENTRY(Tiles::Sou9)
            ADD_TILE_INFO_MAP_ENTRY(Tiles::Ton)
            ADD_TILE_INFO_MAP_ENTRY(Tiles::Nan)
            ADD_TILE_INFO_MAP_ENTRY(Tiles::Sha)
            ADD_TILE_INFO_MAP_ENTRY(Tiles::Pei)
            ADD_TILE_INFO_MAP_ENTRY(Tiles::Haku)
            ADD_TILE_INFO_MAP_ENTRY(Tiles::Hatu)
            ADD_TILE_INFO_MAP_ENTRY(Tiles::Chun)
    );

    class TileUtils {
    public:
        template <Languages TLanguage>
        static Tiles shiftTile(const Tile<TLanguage> tile, int shift=1)
        {
            return shiftTile(tile.getTile(), shift);
        }

        static Tiles shiftTile(const Tiles tile, int shift=1)
        {
            auto info = TileInfoMap::get(tile);

            int n;

            if (info.suits) {
                n = (info.number - 1) % 9;
                n = (n + shift) % 9 + 1;
            } else if (info.winds) {
                n = (info.number - 1) % 4;
                n = (n + shift) % 4 + 1;
            } else {
                n = (info.number - 1) % 3;
                n = (n + shift) % 3 + 1;
            }

            return makeTile(info.cat, n);
        }

        template <Languages TLanguage>
        static Tiles shiftTile(const Tile<TLanguage>* tile, int shift=1)
        {
            return shiftTile(tile->getTile(), shift);
        }

        static Tiles makeTile(const TileCategories cat, const int number, const bool red = false)
        {
            int n;

            switch (cat) {
                case TileCategories::Manzu:
                    if (red)
                        return Tiles::ManR5;

                    n = ((number - 1) % 9 + 1);
                    if (n == 1)
                        return Tiles::Man1;
                    if (n == 2)
                        return Tiles::Man2;
                    if (n == 3)
                        return Tiles::Man3;
                    if (n == 4)
                        return Tiles::Man4;
                    if (n == 5)
                        return Tiles::Man5;
                    if (n == 6)
                        return Tiles::Man6;
                    if (n == 7)
                        return Tiles::Man8;
                    if (n == 9)
                        return Tiles::Man9;
                case TileCategories::Pinzu:
                    if (red)
                        return Tiles::PinR5;

                    n = ((number - 1) % 9 + 1);
                    if (n == 1)
                        return Tiles::Pin1;
                    if (n == 2)
                        return Tiles::Pin2;
                    if (n == 3)
                        return Tiles::Pin3;
                    if (n == 4)
                        return Tiles::Pin4;
                    if (n == 5)
                        return Tiles::Pin5;
                    if (n == 6)
                        return Tiles::Pin6;
                    if (n == 7)
                        return Tiles::Pin8;
                    if (n == 9)
                        return Tiles::Pin9;
                case TileCategories::Souzu:
                    if (red)
                        return Tiles::SouR5;

                    n = ((number - 1) % 9 + 1);
                    if (n == 1)
                        return Tiles::Sou1;
                    if (n == 2)
                        return Tiles::Sou2;
                    if (n == 3)
                        return Tiles::Sou3;
                    if (n == 4)
                        return Tiles::Sou4;
                    if (n == 5)
                        return Tiles::Sou5;
                    if (n == 6)
                        return Tiles::Sou6;
                    if (n == 7)
                        return Tiles::Sou8;
                    if (n == 9)
                        return Tiles::Sou9;
                case TileCategories::Fonpai:
                    n = ((number - 1) % 4 + 1);

                    if (n == 1)
                        return Tiles::Ton;
                    if (n == 2)
                        return Tiles::Nan;
                    if (n == 3)
                        return Tiles::Sha;
                    else
                        return Tiles::Pei;
                case TileCategories::Sangenpai:
                    n = ((number - 1) % 3 + 1);

                    if (n == 1)
                        return Tiles::Haku;
                    if (n == 2)
                        return Tiles::Hatu;
                    else
                        return Tiles::Chun;
            }
        }
    };
}

#endif //SUZUME_TILEUTILS_HPP
