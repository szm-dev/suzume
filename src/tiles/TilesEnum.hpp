//
// Created by Hamza El-Kebir on 12/4/21.
//

#ifndef SUZUME_TILESENUM_HPP
#define SUZUME_TILESENUM_HPP

#include <type_traits>

namespace szm {
    enum class Tiles {
        // Characters
        Man1,
        Man2,
        Man3,
        Man4,
        Man5,
        ManR5,
        Man6,
        Man7,
        Man8,
        Man9,
        // Dots
        Pin1,
        Pin2,
        Pin3,
        Pin4,
        Pin5,
        PinR5,
        Pin6,
        Pin7,
        Pin8,
        Pin9,
        // Sticks
        Sou1,
        Sou2,
        Sou3,
        Sou4,
        Sou5,
        SouR5,
        Sou6,
        Sou7,
        Sou8,
        Sou9,
        // HONOR TILES
        // Winds
        Ton, /// East
        Nan, /// South
        Sha, /// West
        Pei, /// North
        // Dragons
        Haku, /// White dragon
        Hatu, /// Green dragon
        Chun, /// Red dragon

        // English aliases
        // Characters
        Chars1 = Man1,
        Chars2 = Man2,
        Chars3 = Man3,
        Chars4 = Man4,
        Chars5 = Man5,
        CharsR5 = ManR5,
        Chars6 = Man6,
        Chars7 = Man7,
        Chars8 = Man8,
        Chars9 = Man9,
        // Dots
        Dots1 = Pin1,
        Dots2 = Pin2,
        Dots3 = Pin3,
        Dots4 = Pin4,
        Dots5 = Pin5,
        DotsR5 = PinR5,
        Dots6 = Pin6,
        Dots7 = Pin7,
        Dots8 = Pin8,
        Dots9 = Pin9,
        // Sticks
        Sticks1 = Sou1,
        Sticks2 = Sou2,
        Sticks3 = Sou3,
        Sticks4 = Sou4,
        Sticks5 = Sou5,
        SticksR5 = SouR5,
        Sticks6 = Sou6,
        Sticks7 = Sou7,
        Sticks8 = Sou8,
        Sticks9 = Sou9,
        // HONOR TILES
        // Winds
        East = Ton,
        South = Nan,
        West = Sha,
        North = Pei,
        // Dragons
        White = Haku, /// White dragon
        Green = Hatu, /// Green dragon
        Red = Chun /// Red dragon
    };



    enum class TileCategories {
        Manzu, /// Characters
        Pinzu, /// Dots
        Souzu, /// Sticks
        Fonpai, /// Winds
        Sangenpai, /// Dragons
        // English aliases
        Chars = Manzu,
        Dots = Pinzu,
        Sticks = Souzu,
        Winds = Fonpai,
        Dragons = Sangenpai
    };

    enum class TileStates {
        Closed,
        Open,
        Wanpai, /// Dead wall
        Dora,
        UraDora,
        AkaDora,
        DoraIndicator,
        UraDoraIndicator,
        Tehai, /// Tile in hand
        Sutehai, /// Discarded tile
        Kanpai, /// Tile called with Kan
        Ponpai, /// Tile called with Pon
        Ronpai, /// Tile called with Ron
        Tsumohai, /// Tile naturally drawn
        Chiipai, /// Tile called with Chii
        Yamahai, /// Tile in wall
        Haipai, /// Dealt tile
        // English aliases
        Hand = Tehai,
        Discard = Sutehai
    };

    enum class TileLocations {
        Yama, /// Wall
        Kawa, /// Discarded
        Te, /// Hand
        // English aliases
        Wall = Yama,
        Discards = Kawa,
        Hand = Te,
    };

    enum class TileOrigins {
        Haiyama, /// Undealts
        Toncha, /// East player
        Nancha, /// South player
        Shacha, /// West player
        Peicha, /// North player
        // English aliases
        Undealts = Haiyama,
        EastP = Toncha,
        SouthP = Nancha,
        WestP = Shacha,
        NorthP = Peicha
    };

    enum class TileWaits {
        NoWait,
        Shuntsu, // Run
        Koutsu, // Triplet
        Kantsu, // Quad
        Toitsu, // Duo
        Ryanmen, /// Waiting for one of tile on either side of an incomplete run
        Kanchan, /// Waiting for the center tile of an incomplete run
        Penchan, /// Waiting for one side of an incomplete run
        Shanpon, /// Waiting for one of two pons
        Tanki /// Waiting to complete pair through a ron
    };

    // Template comparison
    template <typename T, typename N=std::enable_if_t<std::is_enum<T>::value>>
    inline bool operator<(T left, T right) {
        return static_cast<std::underlying_type_t<T>>(left) < static_cast<std::underlying_type_t<T>>(right);
    }
}

#endif //SUZUME_TILESENUM_HPP
