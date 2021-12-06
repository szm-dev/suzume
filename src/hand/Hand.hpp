//
// Created by Hamza El-Kebir on 12/5/21.
//

#ifndef SUZUME_HAND_HPP
#define SUZUME_HAND_HPP

#include "tiles/Tile.hpp"
#include <algorithm>

namespace szm {
    template <Languages TLanguage = Languages::English>
    class Hand {
    public:
        typedef Tile<TLanguage> TDTile;

        void addTile(TDTile * tile)
        {
            tiles_.push_back(tile);
        }

        void cutTile(TDTile * tile)
        {
            if (hasExactTile(tile))
                tiles_.erase(std::find(tiles_.begin(), tiles_.end(), tile));
        }

        int tileCount() const
        {
            return tiles_.size();
        }

        bool hasExactTile(TDTile * tile) const
        {
            return (std::find(tiles_.begin(), tiles_.end(), tile) != tiles_.end());
        }

        bool hasTile(Tiles tile) const
        {
            for (const TDTile * t : tiles_) {
                if (t->getTile() == tile)
                    return true;
            }

            return false;
        }

        bool hasTile(TDTile * tile) const
        {
            return hasTile(tile->getTile());
        }

        const std::vector<TDTile*>& getTiles() const
        {
            return tiles_;
        }

        void sortHand()
        {
            std::sort(tiles_.begin(), tiles_.end(), [&](TDTile * a, TDTile * b) {return (*a < *b);});
        }

        TDTile * getTile(int idx = 0)
        {
            return tiles_[(idx < 0) ? 0 : idx % tileCount()];
        }

        const TDTile * getTile(int idx = 0) const
        {
            return tiles_[(idx < 0) ? 0 : idx % tileCount()];
        }

        TDTile * operator [](int idx)
        {
            return tiles_[(idx < 0) ? ((tileCount() + idx) % tileCount() < 0 ? 0 : (tileCount() + idx) % tileCount()) : idx % tileCount()];
        }

        const TDTile * operator [](int idx) const
        {
            return tiles_[(idx < 0) ? ((tileCount() + idx) % tileCount() < 0 ? 0 : (tileCount() + idx) % tileCount()) : idx % tileCount()];
        }


    protected:
        std::vector<TDTile*> tiles_;
    };

    template<Languages TLanguage>
    std::ostream& operator << (std::ostream &os, const Hand<TLanguage>& hand)
    {
        for (Tile<TLanguage> * tile : hand.getTiles()) {
            os << " + " << *tile << std::endl;
        }

        return os;
    }
}

#endif //SUZUME_HAND_HPP
