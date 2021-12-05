//
// Created by Hamza El-Kebir on 12/4/21.
//

#ifndef SUZUME_LOCALIZATION_HPP
#define SUZUME_LOCALIZATION_HPP

#include "Languages.hpp"
#include "tiles/TilesEnum.hpp"

#include <string>
#include <map>

#define ADD_LOCALIZATION(LANGUAGE, VALUE, STR) \
template <> \
struct Localization<LANGUAGE, typeof(VALUE), VALUE> { \
    static constexpr const char* str = STR; \
}

#define MAKE_MAP(LANGUAGE, TYPE, CONTENT) \
template <> \
class LocalizationMap<LANGUAGE, TYPE> {   \
public:                                   \
    static const std::map <TYPE, const char *> map; \
    static const char * get(TYPE value)                \
    {                                     \
        try {                             \
            return map.at(value);         \
        } catch (std::out_of_range &e) {  \
            return "N/A";                 \
        };                                \
    }                                     \
private:                                  \
    static std::map<TYPE, const char *> createMap() \
    { \
        std::map<TYPE, const char *> m;   \
        CONTENT                           \
        return m;                         \
    }                                     \
};

#define INIT_LOCALIZATION_MAP(LANGUAGE, TYPE) \
const std::map <TYPE, const char *> LocalizationMap<LANGUAGE, TYPE>::map = LocalizationMap<LANGUAGE, TYPE>::createMap()

#define GET_LOCALIZATION_DYN(LANGUAGE, VALUE) \
LocalizationMap<LANGUAGE, typeof(VALUE)>::get(VALUE)

#define GET_LOCALIZATION(LANGUAGE, VALUE) \
Localization<LANGUAGE, typeof(VALUE), VALUE>::str

#define ADD_MAP_ENTRY(LANGUAGE, VALUE) \
m[VALUE] = GET_LOCALIZATION(LANGUAGE, VALUE);

namespace szm {
    template <Languages TLanguage, typename TType, TType TValue>
    struct Localization;

    template <Languages TLanguage, typename TType>
    class LocalizationMap;

    template <Languages TLanguage, typename TType, TType TValue>
    struct Localization {
        static constexpr const char* str = "N/A";
    };

    template <Languages TLanguage, typename TType>
    class LocalizationMap {
    public:
        static const char * get(TType value)
        {
            return "N/A";
        }
    };


//    template <Languages TLanguage, typename TType, TType TValue>
//    const std::string Localization<TLanguage, TType, TValue>::str = "N/A";


//    template <Languages TLanguage, Tiles TValue>
//    struct Localization<TLanguage, Tiles, TValue> {
//        static constexpr const char* str = "N/A";
//    };

//    template <Languages TLanguage, Tiles TValue>
//    Localization<TLanguage, typeof(TValue), TValue> getLocalization()
//    {
//        return
//    }

    // TILE STATES
    // English
    ADD_LOCALIZATION(Languages::English, TileStates::Open, "open");
    ADD_LOCALIZATION(Languages::English, TileStates::Closed, "closed");
    ADD_LOCALIZATION(Languages::English, TileStates::Wanpai, "dead");
    ADD_LOCALIZATION(Languages::English, TileStates::Dora, "dora");
    ADD_LOCALIZATION(Languages::English, TileStates::UraDora, "hidden dora");
    ADD_LOCALIZATION(Languages::English, TileStates::DoraIndicator, "dora indicator");
    ADD_LOCALIZATION(Languages::English, TileStates::UraDoraIndicator, "hidden dora indicator");

    MAKE_MAP(Languages::English, TileStates,
             ADD_MAP_ENTRY(Languages::English, TileStates::Open)
                     ADD_MAP_ENTRY(Languages::English, TileStates::Closed)
                     ADD_MAP_ENTRY(Languages::English, TileStates::Wanpai)
                     ADD_MAP_ENTRY(Languages::English, TileStates::Dora)
                     ADD_MAP_ENTRY(Languages::English, TileStates::UraDora)
                     ADD_MAP_ENTRY(Languages::English, TileStates::DoraIndicator)
                     ADD_MAP_ENTRY(Languages::English, TileStates::UraDoraIndicator)
    );

    // Japanese
    ADD_LOCALIZATION(Languages::Japanese, TileStates::Open, "明");
    ADD_LOCALIZATION(Languages::Japanese, TileStates::Closed, "暗");
    ADD_LOCALIZATION(Languages::Japanese, TileStates::Wanpai, "王牌");
    ADD_LOCALIZATION(Languages::Japanese, TileStates::Dora, "ドラ");
    ADD_LOCALIZATION(Languages::Japanese, TileStates::UraDora, "裏ドラ");
    ADD_LOCALIZATION(Languages::Japanese, TileStates::DoraIndicator, "ドラ表示");
    ADD_LOCALIZATION(Languages::Japanese, TileStates::UraDoraIndicator, "裏ドラ表示");

    MAKE_MAP(Languages::Japanese, TileStates,
             ADD_MAP_ENTRY(Languages::Japanese, TileStates::Open)
                     ADD_MAP_ENTRY(Languages::Japanese, TileStates::Closed)
                     ADD_MAP_ENTRY(Languages::Japanese, TileStates::Wanpai)
                     ADD_MAP_ENTRY(Languages::Japanese, TileStates::Dora)
                     ADD_MAP_ENTRY(Languages::Japanese, TileStates::UraDora)
                     ADD_MAP_ENTRY(Languages::Japanese, TileStates::DoraIndicator)
                     ADD_MAP_ENTRY(Languages::Japanese, TileStates::UraDoraIndicator)
    );

    // Japanese Kanji
    ADD_LOCALIZATION(Languages::JapaneseKanji, TileStates::Open, "明");
    ADD_LOCALIZATION(Languages::JapaneseKanji, TileStates::Closed, "暗");
    ADD_LOCALIZATION(Languages::JapaneseKanji, TileStates::Wanpai, "王牌");
    ADD_LOCALIZATION(Languages::JapaneseKanji, TileStates::Dora, "ドラ");
    ADD_LOCALIZATION(Languages::JapaneseKanji, TileStates::UraDora, "裏ドラ");
    ADD_LOCALIZATION(Languages::JapaneseKanji, TileStates::DoraIndicator, "ドラ表示");
    ADD_LOCALIZATION(Languages::JapaneseKanji, TileStates::UraDoraIndicator, "裏ドラ表示");

    MAKE_MAP(Languages::JapaneseKanji, TileStates,
             ADD_MAP_ENTRY(Languages::JapaneseKanji, TileStates::Open)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, TileStates::Closed)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, TileStates::Wanpai)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, TileStates::Dora)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, TileStates::UraDora)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, TileStates::DoraIndicator)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, TileStates::UraDoraIndicator)
    );

    // Japanese Phonetic
    ADD_LOCALIZATION(Languages::JapanesePhonetic, TileStates::Open, "ミン");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, TileStates::Closed, "アン");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, TileStates::Wanpai, "ワンパイ");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, TileStates::Dora, "ドラ");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, TileStates::UraDora, "ウラドラ");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, TileStates::DoraIndicator, "ドラヒョウジ");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, TileStates::UraDoraIndicator, "ウラドラヒョウジ");

    MAKE_MAP(Languages::JapanesePhonetic, TileStates,
             ADD_MAP_ENTRY(Languages::JapanesePhonetic, TileStates::Open)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, TileStates::Closed)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, TileStates::Wanpai)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, TileStates::Dora)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, TileStates::UraDora)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, TileStates::DoraIndicator)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, TileStates::UraDoraIndicator)
    );

    // TILES
    // English

    ADD_LOCALIZATION(Languages::English, Tiles::Man1, "1 characters");
    ADD_LOCALIZATION(Languages::English, Tiles::Man2, "2 characters");
    ADD_LOCALIZATION(Languages::English, Tiles::Man3, "3 characters");
    ADD_LOCALIZATION(Languages::English, Tiles::Man4, "4 characters");
    ADD_LOCALIZATION(Languages::English, Tiles::Man5, "5 characters");
    ADD_LOCALIZATION(Languages::English, Tiles::ManR5, "red 5 characters");
    ADD_LOCALIZATION(Languages::English, Tiles::Man6, "6 characters");
    ADD_LOCALIZATION(Languages::English, Tiles::Man7, "7 characters");
    ADD_LOCALIZATION(Languages::English, Tiles::Man8, "8 characters");
    ADD_LOCALIZATION(Languages::English, Tiles::Man9, "9 characters");

    ADD_LOCALIZATION(Languages::English, Tiles::Pin1, "1 dots");
    ADD_LOCALIZATION(Languages::English, Tiles::Pin2, "2 dots");
    ADD_LOCALIZATION(Languages::English, Tiles::Pin3, "3 dots");
    ADD_LOCALIZATION(Languages::English, Tiles::Pin4, "4 dots");
    ADD_LOCALIZATION(Languages::English, Tiles::Pin5, "5 dots");
    ADD_LOCALIZATION(Languages::English, Tiles::PinR5, "red 5 dots");
    ADD_LOCALIZATION(Languages::English, Tiles::Pin6, "6 dots");
    ADD_LOCALIZATION(Languages::English, Tiles::Pin7, "7 dots");
    ADD_LOCALIZATION(Languages::English, Tiles::Pin8, "8 dots");
    ADD_LOCALIZATION(Languages::English, Tiles::Pin9, "9 dots");

    ADD_LOCALIZATION(Languages::English, Tiles::Sou1, "1 sticks");
    ADD_LOCALIZATION(Languages::English, Tiles::Sou2, "2 sticks");
    ADD_LOCALIZATION(Languages::English, Tiles::Sou3, "3 sticks");
    ADD_LOCALIZATION(Languages::English, Tiles::Sou4, "4 sticks");
    ADD_LOCALIZATION(Languages::English, Tiles::Sou5, "5 sticks");
    ADD_LOCALIZATION(Languages::English, Tiles::SouR5, "red 5 sticks");
    ADD_LOCALIZATION(Languages::English, Tiles::Sou6, "6 sticks");
    ADD_LOCALIZATION(Languages::English, Tiles::Sou7, "7 sticks");
    ADD_LOCALIZATION(Languages::English, Tiles::Sou8, "8 sticks");
    ADD_LOCALIZATION(Languages::English, Tiles::Sou9, "9 sticks");

    ADD_LOCALIZATION(Languages::English, Tiles::Ton, "East");
    ADD_LOCALIZATION(Languages::English, Tiles::Nan, "South");
    ADD_LOCALIZATION(Languages::English, Tiles::Sha, "West");
    ADD_LOCALIZATION(Languages::English, Tiles::Pei, "North");

    ADD_LOCALIZATION(Languages::English, Tiles::Haku, "white dragon");
    ADD_LOCALIZATION(Languages::English, Tiles::Hatu, "green dragon");
    ADD_LOCALIZATION(Languages::English, Tiles::Chun, "red dragon");

    MAKE_MAP(Languages::English, Tiles,
             ADD_MAP_ENTRY(Languages::English, Tiles::Man1)
                     ADD_MAP_ENTRY(Languages::English, Tiles::Man2)
                     ADD_MAP_ENTRY(Languages::English, Tiles::Man3)
                     ADD_MAP_ENTRY(Languages::English, Tiles::Man4)
                     ADD_MAP_ENTRY(Languages::English, Tiles::Man5)
                     ADD_MAP_ENTRY(Languages::English, Tiles::ManR5)
                     ADD_MAP_ENTRY(Languages::English, Tiles::Man6)
                     ADD_MAP_ENTRY(Languages::English, Tiles::Man7)
                     ADD_MAP_ENTRY(Languages::English, Tiles::Man8)
                     ADD_MAP_ENTRY(Languages::English, Tiles::Man9)
                     ADD_MAP_ENTRY(Languages::English, Tiles::Pin1)
                     ADD_MAP_ENTRY(Languages::English, Tiles::Pin2)
                     ADD_MAP_ENTRY(Languages::English, Tiles::Pin3)
                     ADD_MAP_ENTRY(Languages::English, Tiles::Pin4)
                     ADD_MAP_ENTRY(Languages::English, Tiles::Pin5)
                     ADD_MAP_ENTRY(Languages::English, Tiles::PinR5)
                     ADD_MAP_ENTRY(Languages::English, Tiles::Pin6)
                     ADD_MAP_ENTRY(Languages::English, Tiles::Pin7)
                     ADD_MAP_ENTRY(Languages::English, Tiles::Pin8)
                     ADD_MAP_ENTRY(Languages::English, Tiles::Pin9)
                     ADD_MAP_ENTRY(Languages::English, Tiles::Sou1)
                     ADD_MAP_ENTRY(Languages::English, Tiles::Sou2)
                     ADD_MAP_ENTRY(Languages::English, Tiles::Sou3)
                     ADD_MAP_ENTRY(Languages::English, Tiles::Sou4)
                     ADD_MAP_ENTRY(Languages::English, Tiles::Sou5)
                     ADD_MAP_ENTRY(Languages::English, Tiles::SouR5)
                     ADD_MAP_ENTRY(Languages::English, Tiles::Sou6)
                     ADD_MAP_ENTRY(Languages::English, Tiles::Sou7)
                     ADD_MAP_ENTRY(Languages::English, Tiles::Sou8)
                     ADD_MAP_ENTRY(Languages::English, Tiles::Sou9)
                     ADD_MAP_ENTRY(Languages::English, Tiles::Ton)
                     ADD_MAP_ENTRY(Languages::English, Tiles::Nan)
                     ADD_MAP_ENTRY(Languages::English, Tiles::Sha)
                     ADD_MAP_ENTRY(Languages::English, Tiles::Pei)
                     ADD_MAP_ENTRY(Languages::English, Tiles::Haku)
                     ADD_MAP_ENTRY(Languages::English, Tiles::Hatu)
                     ADD_MAP_ENTRY(Languages::English, Tiles::Chun)
    );

    // Japanese

    ADD_LOCALIZATION(Languages::Japanese, Tiles::Man1, "一マン");
    ADD_LOCALIZATION(Languages::Japanese, Tiles::Man2, "二マン");
    ADD_LOCALIZATION(Languages::Japanese, Tiles::Man3, "三マン");
    ADD_LOCALIZATION(Languages::Japanese, Tiles::Man4, "四マン");
    ADD_LOCALIZATION(Languages::Japanese, Tiles::Man5, "五マン");
    ADD_LOCALIZATION(Languages::Japanese, Tiles::ManR5, "赤五マン");
    ADD_LOCALIZATION(Languages::Japanese, Tiles::Man6, "六マン");
    ADD_LOCALIZATION(Languages::Japanese, Tiles::Man7, "七マン");
    ADD_LOCALIZATION(Languages::Japanese, Tiles::Man8, "八マン");
    ADD_LOCALIZATION(Languages::Japanese, Tiles::Man9, "九マン");

    ADD_LOCALIZATION(Languages::Japanese, Tiles::Pin1, "一ピン");
    ADD_LOCALIZATION(Languages::Japanese, Tiles::Pin2, "二ピン");
    ADD_LOCALIZATION(Languages::Japanese, Tiles::Pin3, "三ピン");
    ADD_LOCALIZATION(Languages::Japanese, Tiles::Pin4, "四ピン");
    ADD_LOCALIZATION(Languages::Japanese, Tiles::Pin5, "五ピン");
    ADD_LOCALIZATION(Languages::Japanese, Tiles::PinR5, "赤五ピン");
    ADD_LOCALIZATION(Languages::Japanese, Tiles::Pin6, "六ピン");
    ADD_LOCALIZATION(Languages::Japanese, Tiles::Pin7, "七ピン");
    ADD_LOCALIZATION(Languages::Japanese, Tiles::Pin8, "八ピン");
    ADD_LOCALIZATION(Languages::Japanese, Tiles::Pin9, "九ピン");

    ADD_LOCALIZATION(Languages::Japanese, Tiles::Sou1, "一ソウ");
    ADD_LOCALIZATION(Languages::Japanese, Tiles::Sou2, "二ソウ");
    ADD_LOCALIZATION(Languages::Japanese, Tiles::Sou3, "三ソウ");
    ADD_LOCALIZATION(Languages::Japanese, Tiles::Sou4, "四ソウ");
    ADD_LOCALIZATION(Languages::Japanese, Tiles::Sou5, "五ソウ");
    ADD_LOCALIZATION(Languages::Japanese, Tiles::SouR5, "赤五ソウ");
    ADD_LOCALIZATION(Languages::Japanese, Tiles::Sou6, "六ソウ");
    ADD_LOCALIZATION(Languages::Japanese, Tiles::Sou7, "七ソウ");
    ADD_LOCALIZATION(Languages::Japanese, Tiles::Sou8, "八ソウ");
    ADD_LOCALIZATION(Languages::Japanese, Tiles::Sou9, "九ソウ");

    ADD_LOCALIZATION(Languages::Japanese, Tiles::Ton, "東");
    ADD_LOCALIZATION(Languages::Japanese, Tiles::Nan, "南");
    ADD_LOCALIZATION(Languages::Japanese, Tiles::Sha, "西");
    ADD_LOCALIZATION(Languages::Japanese, Tiles::Pei, "北");

    ADD_LOCALIZATION(Languages::Japanese, Tiles::Haku, "白");
    ADD_LOCALIZATION(Languages::Japanese, Tiles::Hatu, "發");
    ADD_LOCALIZATION(Languages::Japanese, Tiles::Chun, "中");

    MAKE_MAP(Languages::Japanese, Tiles,
             ADD_MAP_ENTRY(Languages::Japanese, Tiles::Man1)
                     ADD_MAP_ENTRY(Languages::Japanese, Tiles::Man2)
                     ADD_MAP_ENTRY(Languages::Japanese, Tiles::Man3)
                     ADD_MAP_ENTRY(Languages::Japanese, Tiles::Man4)
                     ADD_MAP_ENTRY(Languages::Japanese, Tiles::Man5)
                     ADD_MAP_ENTRY(Languages::Japanese, Tiles::ManR5)
                     ADD_MAP_ENTRY(Languages::Japanese, Tiles::Man6)
                     ADD_MAP_ENTRY(Languages::Japanese, Tiles::Man7)
                     ADD_MAP_ENTRY(Languages::Japanese, Tiles::Man8)
                     ADD_MAP_ENTRY(Languages::Japanese, Tiles::Man9)
                     ADD_MAP_ENTRY(Languages::Japanese, Tiles::Pin1)
                     ADD_MAP_ENTRY(Languages::Japanese, Tiles::Pin2)
                     ADD_MAP_ENTRY(Languages::Japanese, Tiles::Pin3)
                     ADD_MAP_ENTRY(Languages::Japanese, Tiles::Pin4)
                     ADD_MAP_ENTRY(Languages::Japanese, Tiles::Pin5)
                     ADD_MAP_ENTRY(Languages::Japanese, Tiles::PinR5)
                     ADD_MAP_ENTRY(Languages::Japanese, Tiles::Pin6)
                     ADD_MAP_ENTRY(Languages::Japanese, Tiles::Pin7)
                     ADD_MAP_ENTRY(Languages::Japanese, Tiles::Pin8)
                     ADD_MAP_ENTRY(Languages::Japanese, Tiles::Pin9)
                     ADD_MAP_ENTRY(Languages::Japanese, Tiles::Sou1)
                     ADD_MAP_ENTRY(Languages::Japanese, Tiles::Sou2)
                     ADD_MAP_ENTRY(Languages::Japanese, Tiles::Sou3)
                     ADD_MAP_ENTRY(Languages::Japanese, Tiles::Sou4)
                     ADD_MAP_ENTRY(Languages::Japanese, Tiles::Sou5)
                     ADD_MAP_ENTRY(Languages::Japanese, Tiles::SouR5)
                     ADD_MAP_ENTRY(Languages::Japanese, Tiles::Sou6)
                     ADD_MAP_ENTRY(Languages::Japanese, Tiles::Sou7)
                     ADD_MAP_ENTRY(Languages::Japanese, Tiles::Sou8)
                     ADD_MAP_ENTRY(Languages::Japanese, Tiles::Sou9)
                     ADD_MAP_ENTRY(Languages::Japanese, Tiles::Ton)
                     ADD_MAP_ENTRY(Languages::Japanese, Tiles::Nan)
                     ADD_MAP_ENTRY(Languages::Japanese, Tiles::Sha)
                     ADD_MAP_ENTRY(Languages::Japanese, Tiles::Pei)
                     ADD_MAP_ENTRY(Languages::Japanese, Tiles::Haku)
                     ADD_MAP_ENTRY(Languages::Japanese, Tiles::Hatu)
                     ADD_MAP_ENTRY(Languages::Japanese, Tiles::Chun)
    );

    // Japanese　Kanji

    ADD_LOCALIZATION(Languages::JapaneseKanji, Tiles::Man1, "一萬");
    ADD_LOCALIZATION(Languages::JapaneseKanji, Tiles::Man2, "二萬");
    ADD_LOCALIZATION(Languages::JapaneseKanji, Tiles::Man3, "三萬");
    ADD_LOCALIZATION(Languages::JapaneseKanji, Tiles::Man4, "四萬");
    ADD_LOCALIZATION(Languages::JapaneseKanji, Tiles::Man5, "五萬");
    ADD_LOCALIZATION(Languages::JapaneseKanji, Tiles::ManR5, "赤五萬");
    ADD_LOCALIZATION(Languages::JapaneseKanji, Tiles::Man6, "六萬");
    ADD_LOCALIZATION(Languages::JapaneseKanji, Tiles::Man7, "七萬");
    ADD_LOCALIZATION(Languages::JapaneseKanji, Tiles::Man8, "八萬");
    ADD_LOCALIZATION(Languages::JapaneseKanji, Tiles::Man9, "九萬");

    ADD_LOCALIZATION(Languages::JapaneseKanji, Tiles::Pin1, "一筒");
    ADD_LOCALIZATION(Languages::JapaneseKanji, Tiles::Pin2, "二筒");
    ADD_LOCALIZATION(Languages::JapaneseKanji, Tiles::Pin3, "三筒");
    ADD_LOCALIZATION(Languages::JapaneseKanji, Tiles::Pin4, "四筒");
    ADD_LOCALIZATION(Languages::JapaneseKanji, Tiles::Pin5, "五筒");
    ADD_LOCALIZATION(Languages::JapaneseKanji, Tiles::PinR5, "赤五筒");
    ADD_LOCALIZATION(Languages::JapaneseKanji, Tiles::Pin6, "六筒");
    ADD_LOCALIZATION(Languages::JapaneseKanji, Tiles::Pin7, "七筒");
    ADD_LOCALIZATION(Languages::JapaneseKanji, Tiles::Pin8, "八筒");
    ADD_LOCALIZATION(Languages::JapaneseKanji, Tiles::Pin9, "九筒");

    ADD_LOCALIZATION(Languages::JapaneseKanji, Tiles::Sou1, "一索");
    ADD_LOCALIZATION(Languages::JapaneseKanji, Tiles::Sou2, "二索");
    ADD_LOCALIZATION(Languages::JapaneseKanji, Tiles::Sou3, "三索");
    ADD_LOCALIZATION(Languages::JapaneseKanji, Tiles::Sou4, "四索");
    ADD_LOCALIZATION(Languages::JapaneseKanji, Tiles::Sou5, "五索");
    ADD_LOCALIZATION(Languages::JapaneseKanji, Tiles::SouR5, "赤五索");
    ADD_LOCALIZATION(Languages::JapaneseKanji, Tiles::Sou6, "六索");
    ADD_LOCALIZATION(Languages::JapaneseKanji, Tiles::Sou7, "七索");
    ADD_LOCALIZATION(Languages::JapaneseKanji, Tiles::Sou8, "八索");
    ADD_LOCALIZATION(Languages::JapaneseKanji, Tiles::Sou9, "九索");

    ADD_LOCALIZATION(Languages::JapaneseKanji, Tiles::Ton, "東");
    ADD_LOCALIZATION(Languages::JapaneseKanji, Tiles::Nan, "南");
    ADD_LOCALIZATION(Languages::JapaneseKanji, Tiles::Sha, "西");
    ADD_LOCALIZATION(Languages::JapaneseKanji, Tiles::Pei, "北");

    ADD_LOCALIZATION(Languages::JapaneseKanji, Tiles::Haku, "白");
    ADD_LOCALIZATION(Languages::JapaneseKanji, Tiles::Hatu, "發");
    ADD_LOCALIZATION(Languages::JapaneseKanji, Tiles::Chun, "中");

    MAKE_MAP(Languages::JapaneseKanji, Tiles,
             ADD_MAP_ENTRY(Languages::JapaneseKanji, Tiles::Man1)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, Tiles::Man2)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, Tiles::Man3)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, Tiles::Man4)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, Tiles::Man5)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, Tiles::ManR5)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, Tiles::Man6)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, Tiles::Man7)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, Tiles::Man8)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, Tiles::Man9)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, Tiles::Pin1)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, Tiles::Pin2)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, Tiles::Pin3)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, Tiles::Pin4)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, Tiles::Pin5)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, Tiles::PinR5)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, Tiles::Pin6)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, Tiles::Pin7)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, Tiles::Pin8)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, Tiles::Pin9)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, Tiles::Sou1)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, Tiles::Sou2)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, Tiles::Sou3)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, Tiles::Sou4)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, Tiles::Sou5)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, Tiles::SouR5)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, Tiles::Sou6)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, Tiles::Sou7)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, Tiles::Sou8)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, Tiles::Sou9)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, Tiles::Ton)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, Tiles::Nan)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, Tiles::Sha)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, Tiles::Pei)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, Tiles::Haku)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, Tiles::Hatu)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, Tiles::Chun)
    );

    // Japanese Phonetic

    ADD_LOCALIZATION(Languages::JapanesePhonetic, Tiles::Man1, "イーマン");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, Tiles::Man2, "リャンマン");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, Tiles::Man3, "サンマン");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, Tiles::Man4, "スーマン");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, Tiles::Man5, "ウーマン");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, Tiles::ManR5, "アカウーマン");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, Tiles::Man6, "ローマン");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, Tiles::Man7, "チーマン");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, Tiles::Man8, "パーマン");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, Tiles::Man9, "キュウマン");

    ADD_LOCALIZATION(Languages::JapanesePhonetic, Tiles::Pin1, "イーピン");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, Tiles::Pin2, "リャンピン");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, Tiles::Pin3, "サンピン");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, Tiles::Pin4, "スーピン");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, Tiles::Pin5, "ウーピン");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, Tiles::PinR5, "アカウーピン");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, Tiles::Pin6, "ローピン");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, Tiles::Pin7, "チーピン");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, Tiles::Pin8, "パーピン");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, Tiles::Pin9, "キュウピン");

    ADD_LOCALIZATION(Languages::JapanesePhonetic, Tiles::Sou1, "イーソウ");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, Tiles::Sou2, "リャンソウ");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, Tiles::Sou3, "サンソウ");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, Tiles::Sou4, "スーソウ");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, Tiles::Sou5, "ウーソウ");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, Tiles::SouR5, "アカウーソウ");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, Tiles::Sou6, "ローソウ");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, Tiles::Sou7, "チーソウ");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, Tiles::Sou8, "パーソウ");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, Tiles::Sou9, "キュウソウ");

    ADD_LOCALIZATION(Languages::JapanesePhonetic, Tiles::Ton, "トン");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, Tiles::Nan, "ナン");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, Tiles::Sha, "シャー");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, Tiles::Pei, "ペイ");

    ADD_LOCALIZATION(Languages::JapanesePhonetic, Tiles::Haku, "ハク");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, Tiles::Hatu, "ハツ");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, Tiles::Chun, "チュン");

    MAKE_MAP(Languages::JapanesePhonetic, Tiles,
             ADD_MAP_ENTRY(Languages::JapanesePhonetic, Tiles::Man1)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, Tiles::Man2)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, Tiles::Man3)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, Tiles::Man4)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, Tiles::Man5)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, Tiles::ManR5)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, Tiles::Man6)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, Tiles::Man7)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, Tiles::Man8)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, Tiles::Man9)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, Tiles::Pin1)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, Tiles::Pin2)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, Tiles::Pin3)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, Tiles::Pin4)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, Tiles::Pin5)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, Tiles::PinR5)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, Tiles::Pin6)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, Tiles::Pin7)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, Tiles::Pin8)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, Tiles::Pin9)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, Tiles::Sou1)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, Tiles::Sou2)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, Tiles::Sou3)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, Tiles::Sou4)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, Tiles::Sou5)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, Tiles::SouR5)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, Tiles::Sou6)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, Tiles::Sou7)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, Tiles::Sou8)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, Tiles::Sou9)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, Tiles::Ton)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, Tiles::Nan)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, Tiles::Sha)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, Tiles::Pei)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, Tiles::Haku)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, Tiles::Hatu)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, Tiles::Chun)
    );
}

#endif //SUZUME_LOCALIZATION_HPP
