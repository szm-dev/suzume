//
// Created by Hamza El-Kebir on 12/4/21.
//

#ifndef SUZUME_LANGUAGES_HPP
#define SUZUME_LANGUAGES_HPP

#include "tiles/TilesEnum.hpp"

namespace szm {
    enum class Languages {
        English,
        Japanese,
        JapaneseKanji,
        JapanesePhonetic,
        JapaneseKana
    };

//    template <Languages TLanguage = Languages::English>
//    static std::string localize(Tiles tile);
//
//    template <>
//    std::string localize(Tiles tile)
//    {
//        switch (tile) {
//            case Tiles::Man1:
//                return "1 characters";
//            case Tiles::Man2:
//                return "2 characters";
//            case Tiles::Man3:
//                return "3 characters";
//            case Tiles::Man4:
//                return "4 characters";
//            case Tiles::Man5:
//                return "5 characters";
//            case Tiles::ManR5:
//                return "red 5 characters";
//            case Tiles::Man6:
//                return "6 characters";
//            case Tiles::Man7:
//                return "7 characters";
//            case Tiles::Man8:
//                return "8 characters";
//            case Tiles::Man9:
//                return "9 characters";
//            case Tiles::Pin1:
//                return "1 dots";
//            case Tiles::Pin2:
//                return "2 dots";
//            case Tiles::Pin3:
//                return "3 dots";
//            case Tiles::Pin4:
//                return "4 dots";
//            case Tiles::Pin5:
//                return "5 dots";
//            case Tiles::PinR5:
//                return "red 5 dots";
//            case Tiles::Pin6:
//                return "6 dots";
//            case Tiles::Pin7:
//                return "7 dots";
//            case Tiles::Pin8:
//                return "8 dots";
//            case Tiles::Pin9:
//                return "9 dots";
//            case Tiles::Sou1:
//                return "1 sticks";
//            case Tiles::Sou2:
//                return "2 sticks";
//            case Tiles::Sou3:
//                return "3 sticks";
//            case Tiles::Sou4:
//                return "4 sticks";
//            case Tiles::Sou5:
//                return "5 sticks";
//            case Tiles::SouR5:
//                return "red 5 sticks";
//            case Tiles::Sou6:
//                return "6 sticks";
//            case Tiles::Sou7:
//                return "7 sticks";
//            case Tiles::Sou8:
//                return "8 sticks";
//            case Tiles::Sou9:
//                return "9 sticks";
//            case Tiles::Ton:
//                return "East";
//            case Tiles::Nan:
//                return "South";
//            case Tiles::Sha:
//                return "West";
//            case Tiles::Pei:
//                return "North";
//            case Tiles::Haku:
//                return "white dragon";
//            case Tiles::Hatsu:
//                return "green dragon";
//            case Tiles::Chun:
//                return "red dragon";
//        }
//    }
}

#endif //SUZUME_LANGUAGES_HPP
