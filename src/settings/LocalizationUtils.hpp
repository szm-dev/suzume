//
// Created by Hamza El-Kebir on 12/4/21.
//

#ifndef SUZUME_LOCALIZATIONUTILS_HPP
#define SUZUME_LOCALIZATIONUTILS_HPP

#include "Localization.hpp"

#define DEFINE_LOCALIZATION_FUNCTION(TYPE) \
template <TYPE TValue, Languages TLanguage = Languages::English> \
std::string localize() \
{ \
    return GET_LOCALIZATION(TLanguage, TValue); \
}

namespace szm {
    template <Languages TLanguage = Languages::English, typename TType>
    std::string localize(TType value)
    {
        return GET_LOCALIZATION_DYN(TLanguage, value);
    }

    DEFINE_LOCALIZATION_FUNCTION(Tiles);
    DEFINE_LOCALIZATION_FUNCTION(TileStates);
    DEFINE_LOCALIZATION_FUNCTION(TileOrigins);
    DEFINE_LOCALIZATION_FUNCTION(TileLocations);
}

#endif //SUZUME_LOCALIZATIONUTILS_HPP
