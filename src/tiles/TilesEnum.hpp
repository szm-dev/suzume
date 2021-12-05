//
// Created by Hamza El-Kebir on 12/4/21.
//

#ifndef SUZUME_TILESENUM_HPP
#define SUZUME_TILESENUM_HPP

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
        Chun /// Red dragon
    };

    enum class TileCategories {
        Manzu, /// Characters
        Pinzu, /// Dots
        Souzu, /// Sticks
        Fonpai, /// Winds
        Sangenpai, /// Three dragons
    };

    enum class TileStates {
        Closed,
        Open,
        Wanpai, // Dead wall
        Dora,
        UraDora,
        DoraIndicator,
        UraDoraIndicator
    };
}

#endif //SUZUME_TILESENUM_HPP
