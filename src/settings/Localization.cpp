//
// Created by Hamza El-Kebir on 12/4/21.
//

#include "Localization.hpp"

namespace szm {
    INIT_LOCALIZATION_MAP(Languages::English, TileStates);
    INIT_LOCALIZATION_MAP(Languages::Japanese, TileStates);
    INIT_LOCALIZATION_MAP(Languages::JapaneseKanji, TileStates);
    INIT_LOCALIZATION_MAP(Languages::JapanesePhonetic, TileStates);

    INIT_LOCALIZATION_MAP(Languages::English, Tiles);
    INIT_LOCALIZATION_MAP(Languages::Japanese, Tiles);
    INIT_LOCALIZATION_MAP(Languages::JapaneseKanji, Tiles);
    INIT_LOCALIZATION_MAP(Languages::JapanesePhonetic, Tiles);
}