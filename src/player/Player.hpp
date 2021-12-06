//
// Created by Hamza El-Kebir on 12/5/21.
//

#ifndef SUZUME_PLAYER_HPP
#define SUZUME_PLAYER_HPP

#include "tiles/Tile.hpp"
#include "tiles/TilesEnum.hpp"
#include "settings/GlobalFlags.hpp"
//#include "table/Table.hpp"
#include "hand/Hand.hpp"
//#include "settings/Languages.hpp"

namespace szm {
//    template <Languages, int>
//    class Table;

    template <Languages TLanguage = Languages::English>
    class Player {
    public:
        Player() : origin_(TileOrigins::Toncha)
        {}

        Player(TileOrigins origin) : origin_(origin)
        {}

        typedef Tile<TLanguage> TDTile;
//        typedef Table<TLanguage, TTileCount> TDTable;
        typedef Hand<TLanguage> TDHand;

        TileOrigins getOrigin() const
        {
            return origin_;
        }

        void setOrigin(TileOrigins origin)
        {
            origin_ = origin;
        }

        void addTile(TDTile * tile)
        {
            hand_.addTile(tile);
        }

        void cutTile(TDTile * tile)
        {
            hand_.cutTile(tile);
        }

        bool hasExactTile(TDTile * tile) const
        {
            return hand_.hasExactTile(tile);
        }

        bool hasTile(Tiles tile) const
        {
            return hand_.hasTile(tile);
        }

        bool hasTile(TDTile * tile) const
        {
            return hand_.hasTile(tile);
        }

        int tileCount() const
        {
            return hand_.tileCount();
        }

        const TDHand& getHand() const
        {
            return hand_;
        }

        void sortHand()
        {
            hand_.sortHand();
        }

        const TDTile * getTile(int idx) const
        {
            return hand_[idx];
        }

        TDTile * operator [](int idx)
        {
            return hand_[idx];
        }

        const TDTile * operator [](int idx) const
        {
            return hand_[idx];
        }

        const std::vector<TDTile*>& getKawa() const
        {
            return kawa_;
        }

        void clearKawa()
        {
            kawa_.clear();
        }

        void addToKawa(TDTile * tile)
        {
            kawa_.push_back(tile);
        }

        int kawaCount() const
        {
            return kawa_.size();
        }

    protected:
        TileOrigins origin_;
        TDHand hand_{};

        std::vector<TDTile *> kawa_;
    };

    template<Languages TLanguage>
    std::ostream& operator << (std::ostream &os, const Player<TLanguage>& player)
    {
        os << "[[" << localize<TLanguage>(player.getOrigin()) << "]]";
        os << " (" << player.tileCount() << ")" << std::endl;
        os << player.getHand();

        os << "[" << localize<TLanguage>(TileLocations::Kawa) << "]";
        os << " (" << player.kawaCount() << ")" << std::endl;
        for (Tile<TLanguage> * tile : player.getKawa()) {
            os << " - " << *tile << std::endl;
        }

        return os;
    }
}

#endif //SUZUME_PLAYER_HPP
