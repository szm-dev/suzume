//
// Created by Hamza El-Kebir on 12/4/21.
//

#ifndef SUZUME_TILE_HPP
#define SUZUME_TILE_HPP

#include <string>
#include <utility>
#include <sstream>
#include <vector>
#include <tuple>
#include <iomanip>

#include "TilesEnum.hpp"
#include "settings/Languages.hpp"
#include "settings/LocalizationUtils.hpp"
#include "settings/GlobalFlags.hpp"
#if SZM_OUTPUT_COLORS
#include "settings/OutputModifier.hpp"
#endif

namespace szm {
    template<Languages TLanguage = Languages::English>
    class Tile {
    public:
        Tile() = default;

        Tile(Tiles tile) : tile_(tile)
        {}

//        Tile(Tiles tile, TileStates state) : tile_(tile), states_{state}
//        {}

        Tile(Tiles tile, TileStates state) {
            tile_ = tile;
            setTileState(state);
        }

        template <class... TStates>
        Tile(Tiles tile, TileStates state, TStates... remainingStates) {
            tile_ = tile;
            setTileState(state);
            Tile(tile, remainingStates...);
        }

        typedef std::vector<TileStates> TDTileStateVector;

        Tile(Tiles tile, TDTileStateVector states) : tile_(tile), states_{std::move(states)}
        {}

        typedef std::tuple<TileLocations, TileOrigins, TileStates> TDTileLocOrigState;

        std::string toString() const;

        Tiles getTile() const;

        void setTile(const Tiles tile);

        std::string getTileName() const;

        const TDTileStateVector& getTileStates() const;

        bool hasTileState(const TileStates state) const;

        void setTileState(const TileStates state);

        void unsetTileState(const TileStates state) {
            if (!hasTileState(state))
                return;

            states_.erase(std::find(states_.begin(), states_.end(), state));
        }

        template <class... TStates>
        void unsetTileState(TileStates state, TStates... remainingStates) {
            unsetTileState(state);
            unsetTileState(remainingStates...);
        }

        void setTileStates(const TDTileStateVector &states);

        std::string getTileStateName() const;

        TDTileLocOrigState getLocOrigState(int shift = 0) const
        {
            int s = locOrigStates_.size()-1;
            s = ((s + shift) < 0 ? 0 : (s + shift)) % (s+1);

            return locOrigStates_[s];
        }

        TileLocations getLocation(int shift = 0) const
        {
            return std::get<0>(getLocOrigState(shift));
        }

        TileOrigins getOrigin(int shift = 0) const
        {
            return std::get<1>(getLocOrigState(shift));
        }

        std::string getOriginName(int shift = 0) const
        {
            return localize<TLanguage>(getOrigin(shift));
        }

        TileStates getTransitionState(int shift = 0) const
        {
            return std::get<2>(getLocOrigState(shift));
        }

        std::string getTransitionStateName(int shift = 0) const
        {
            return localize<TLanguage>(getTransitionState(shift));
        }

        std::string getLocationName(int shift = 0) const
        {
            return localize<TLanguage>(getLocation(shift));
        }

        void setLocOrigState(TDTileLocOrigState locOrigState)
        {
            locOrigStates_.push_back(std::move(locOrigState));
        }

        void setLocOrigState(TileLocations loc, TileOrigins orig, TileStates state = TileStates::Tsumohai)
        {
            locOrigStates_.emplace_back(loc, orig, state);
        }

        int getId() const;

        void setId(int id = 0, int maxTiles = 136);

        unsigned int count() const
        {
            return 1;
        }

        template <Languages TTLanguage>
        friend bool operator<(Tile<TLanguage> left, Tile<TTLanguage> right) {
            return (left.getTile() < right.getTile());
        }
    protected:
        std::string name_;
        Tiles tile_ = Tiles::Haku;
        TDTileStateVector states_ = {TileStates::Closed};
        int id_ = -1;

        std::vector<TDTileLocOrigState> locOrigStates_ = {{TileLocations::Yama, TileOrigins::Haiyama, TileStates::Yamahai}};
    };

    template<Languages TLanguage>
    std::string Tile<TLanguage>::getTileName() const
    {
        return localize<TLanguage>(tile_);
    }

    template<Languages TLanguage>
    const typename Tile<TLanguage>::TDTileStateVector& Tile<TLanguage>::getTileStates() const
    {
        return states_;
    }

    template<Languages TLanguage>
    bool Tile<TLanguage>::hasTileState(const TileStates state) const
    {
        return (std::find(states_.begin(), states_.end(), state) != states_.end());
    }

    template<Languages TLanguage>
    void Tile<TLanguage>::setTileState(const TileStates state)
    {
        if (!hasTileState(state))
            states_.push_back(state);
    }

    template<Languages TLanguage>
    void Tile<TLanguage>::setTileStates(const Tile::TDTileStateVector &states)
    {
        states_ = states;
    }

    template<Languages TLanguage>
    Tiles Tile<TLanguage>::getTile() const
    {
        return tile_;
    }

    template<Languages TLanguage>
    void Tile<TLanguage>::setTile(const Tiles tile)
    {
        tile_ = tile;
    }

    template<Languages TLanguage>
    std::string Tile<TLanguage>::getTileStateName() const
    {
        std::stringstream ss;
        int i = 0;

        for (auto& state: states_) {
            if (i > 0)
                ss << " | ";

            ss << localize<TLanguage>(state);

            i++;
        }

        return ss.str();
    }

    template<Languages TLanguage>
    std::string Tile<TLanguage>::toString() const
    {
        std::stringstream ss;
        ss << getTileName() << " | " << getTileStateName();
        ss << " | [" << getOriginName() << " @ " << getLocationName() << " | " << getTransitionStateName() << "]";

        ss << " (#" << std::setfill('0') << std::setw(3) << getId() << ")";

        return ss.str();
    }

    template<Languages TLanguage>
    int Tile<TLanguage>::getId() const
    {
        return id_;
    }

    template<Languages TLanguage>
    void Tile<TLanguage>::setId(int id, int maxTiles)
    {
        id = id < 0 ? 0 : id;
        id = id % maxTiles;

        id_ = id;
    }

    template<Languages TLanguage>
    std::ostream& operator << (std::ostream &os, const Tile<TLanguage>& tile)
    {
#if SZM_OUTPUT_COLORS
        os << Modifier(ModifierCode::FG_DEFAULT) << Modifier(ModifierCode::BG_DEFAULT);

        if (tile.hasTileState(TileStates::Wanpai))
            os << Modifier(ModifierCode::BG_YELLOW) << Modifier(ModifierCode::FG_BLACK);
        if (tile.hasTileState(TileStates::Tehai))
            os << Modifier(ModifierCode::BG_GREEN)  << Modifier(ModifierCode::FG_BLACK);
        if (tile.hasTileState(TileStates::Sutehai))
            os << Modifier(ModifierCode::BG_MAGENTA)  << Modifier(ModifierCode::FG_BLACK);
        if (tile.hasTileState(TileStates::UraDora) || tile.hasTileState(TileStates::Dora) || tile.hasTileState(TileStates::AkaDora))
            os << Modifier(ModifierCode::FG_RED);
#endif

        os << tile.toString();

#if SZM_OUTPUT_COLORS
        os << Modifier(ModifierCode::FG_DEFAULT) << Modifier(ModifierCode::BG_DEFAULT);
#endif
        return os;
    }

    template<Languages TLanguage>
    std::ostream& operator << (std::ostream &os, const std::vector<Tile<TLanguage>>& tiles)
    {
        for (Tile<TLanguage>& tile : tiles) {
            os << " = " << tile << std::endl;
        }

        return os;
    }

    template<Languages TLanguage>
    std::ostream& operator << (std::ostream &os, const std::vector<Tile<TLanguage>*>& tiles)
    {
        for (Tile<TLanguage>* tile : tiles) {
            os << " = " << *tile << std::endl;
        }

        return os;
    }
}


#endif //SUZUME_TILE_HPP
