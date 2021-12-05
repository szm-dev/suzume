//
// Created by Hamza El-Kebir on 12/4/21.
//

#ifndef SUZUME_TILE_HPP
#define SUZUME_TILE_HPP

#include <string>
#include <utility>
#include <sstream>
#include <vector>

#include "TilesEnum.hpp"
#include "settings/Languages.hpp"
#include "settings/LocalizationUtils.hpp"

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

        std::string toString() const;

        Tiles getTile() const;

        void setTile(const Tiles tile);

        std::string getTileName() const;

        const TDTileStateVector& getTileStates() const;

        bool hasTileState(const TileStates state);

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

        unsigned int count() const
        {
            return 1;
        }
    protected:
        std::string name_;
        Tiles tile_ = Tiles::Haku;
        TDTileStateVector states_ = {TileStates::Closed};
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
    bool Tile<TLanguage>::hasTileState(const TileStates state)
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

        return ss.str();
    }

    template<Languages TLanguage>
    std::ostream& operator << (std::ostream &os, const Tile<TLanguage>& tile)
    {
        return (os << tile.toString());
    }
}


#endif //SUZUME_TILE_HPP
