//
// Created by Hamza El-Kebir on 12/4/21.
//

#include "Localization.hpp"

namespace szm {
    INIT_LOCALIZATION_MAP(Languages::English, TileLocations);
    INIT_LOCALIZATION_MAP(Languages::Japanese, TileLocations);
    INIT_LOCALIZATION_MAP(Languages::JapaneseKanji, TileLocations);
    INIT_LOCALIZATION_MAP(Languages::JapanesePhonetic, TileLocations);

    INIT_LOCALIZATION_MAP(Languages::English, TileOrigins);
    INIT_LOCALIZATION_MAP(Languages::Japanese, TileOrigins);
    INIT_LOCALIZATION_MAP(Languages::JapaneseKanji, TileOrigins);
    INIT_LOCALIZATION_MAP(Languages::JapanesePhonetic, TileOrigins);

    INIT_LOCALIZATION_MAP(Languages::English, TileStates);
    INIT_LOCALIZATION_MAP(Languages::Japanese, TileStates);
    INIT_LOCALIZATION_MAP(Languages::JapaneseKanji, TileStates);
    INIT_LOCALIZATION_MAP(Languages::JapanesePhonetic, TileStates);

    INIT_LOCALIZATION_MAP(Languages::English, Tiles);
    INIT_LOCALIZATION_MAP(Languages::Japanese, Tiles);
    INIT_LOCALIZATION_MAP(Languages::JapaneseKanji, Tiles);
    INIT_LOCALIZATION_MAP(Languages::JapanesePhonetic, Tiles);
}