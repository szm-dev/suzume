//
// Created by Hamza El-Kebir on 12/4/21.
//

#ifndef SUZUME_TABLE_HPP
#define SUZUME_TABLE_HPP

#include "tiles/Tile.hpp"
#include "tiles/TileUtils.hpp"
#include "settings/Random.hpp"
#include "settings/GlobalFlags.hpp"
#include "player/Player.hpp"

#include <array>
#include <sstream>
#include <iomanip>
#include <algorithm>

namespace szm {
    template <Languages TLanguage = Languages::English, int TTileCount = SZM_RIICHI_TILE_COUNT>
    class Table {
    public:
        Table()
        {
            initTileSet();
        }

        Table(bool useAkaDora) : useAkaDora_(useAkaDora)
        {
            initTileSet();
        }

        typedef Tile<TLanguage> TDTile;
        typedef Player<TLanguage> TDPlayer;

        const TDTile & getTile(int idx) const
        {
            return *tileSet_.at(idx);
        }

        TDTile & getTile(int idx)
        {
            return *tileSet_.at(idx);
        }

        TDTile * getTilePointer(int idx)
        {
            return tileSet_[idx];
        }

        void initTileSet()
        {
            // Initialize all tiles except potential red dora (fives).
            for (int i = 0; i < tileCount; i+=34) {
                tileSet_[i+ 0] = new TDTile{Tiles::Man1, TileStates::Closed};
                tileSet_[i+ 1] = new TDTile{Tiles::Man2, TileStates::Closed};
                tileSet_[i+ 2] = new TDTile{Tiles::Man3, TileStates::Closed};
                tileSet_[i+ 3] = new TDTile{Tiles::Man4, TileStates::Closed};
                tileSet_[i+ 5] = new TDTile{Tiles::Man6, TileStates::Closed};
                tileSet_[i+ 6] = new TDTile{Tiles::Man7, TileStates::Closed};
                tileSet_[i+ 7] = new TDTile{Tiles::Man8, TileStates::Closed};
                tileSet_[i+ 8] = new TDTile{Tiles::Man9, TileStates::Closed};

                tileSet_[i+ 9] = new TDTile{Tiles::Pin1, TileStates::Closed};
                tileSet_[i+10] = new TDTile{Tiles::Pin2, TileStates::Closed};
                tileSet_[i+11] = new TDTile{Tiles::Pin3, TileStates::Closed};
                tileSet_[i+12] = new TDTile{Tiles::Pin4, TileStates::Closed};
                tileSet_[i+14] = new TDTile{Tiles::Pin6, TileStates::Closed};
                tileSet_[i+15] = new TDTile{Tiles::Pin7, TileStates::Closed};
                tileSet_[i+16] = new TDTile{Tiles::Pin8, TileStates::Closed};
                tileSet_[i+17] = new TDTile{Tiles::Pin9, TileStates::Closed};

                tileSet_[i+18] = new TDTile{Tiles::Sou1, TileStates::Closed};
                tileSet_[i+19] = new TDTile{Tiles::Sou2, TileStates::Closed};
                tileSet_[i+20] = new TDTile{Tiles::Sou3, TileStates::Closed};
                tileSet_[i+21] = new TDTile{Tiles::Sou4, TileStates::Closed};
                tileSet_[i+23] = new TDTile{Tiles::Sou6, TileStates::Closed};
                tileSet_[i+24] = new TDTile{Tiles::Sou7, TileStates::Closed};
                tileSet_[i+25] = new TDTile{Tiles::Sou8, TileStates::Closed};
                tileSet_[i+26] = new TDTile{Tiles::Sou9, TileStates::Closed};

                tileSet_[i+27] = new TDTile{Tiles::Ton, TileStates::Closed};
                tileSet_[i+28] = new TDTile{Tiles::Nan, TileStates::Closed};
                tileSet_[i+29] = new TDTile{Tiles::Sha, TileStates::Closed};
                tileSet_[i+30] = new TDTile{Tiles::Pei, TileStates::Closed};

                tileSet_[i+31] = new TDTile{Tiles::Haku, TileStates::Closed};
                tileSet_[i+32] = new TDTile{Tiles::Hatu, TileStates::Closed};
                tileSet_[i+33] = new TDTile{Tiles::Chun, TileStates::Closed};
            }

            if (useAkaDora_) {
                int j = 0;
                for (int i = 0; i < tileCount; i+=34) {
                    if (j < 3) {
                        tileSet_[i + 4] = new TDTile{Tiles::Man5};
                        tileSet_[i + 13] = new TDTile{Tiles::Pin5};
                        tileSet_[i + 22] = new TDTile{Tiles::Sou5};
                    } else {
                        tileSet_[i + 4] = new TDTile{Tiles::ManR5, TileStates::Dora, TileStates::Closed};
                        tileSet_[i + 13] = new TDTile{Tiles::PinR5, TileStates::Dora, TileStates::Closed};
                        tileSet_[i + 22] = new TDTile{Tiles::SouR5, TileStates::Dora, TileStates::Closed};
                    }

                    j++;
                }
            } else {
                for (int i = 0; i < tileCount; i+=34) {
                    tileSet_[i + 4] = new TDTile{Tiles::Man5};
                    tileSet_[i + 13] = new TDTile{Tiles::Pin5};
                    tileSet_[i + 22] = new TDTile{Tiles::Sou5};
                }
            }

            int i = 0;
            for (TDTile* tile: tileSet_) {
                tile->setId(i);
                i++;
            }
        }

        void shuffle()
        {
            std::shuffle(tileSet_.begin(), tileSet_.end(), randomEngine);
        }

        void clearDeadWall()
        {
            if (deadWallTileSet_.empty())
                return;

            // Cleanup tile states.
            for (TDTile *tile: deadWallTileSet_) {
                tile->unsetTileState(TileStates::Wanpai, TileStates::UraDora, TileStates::Dora, TileStates::DoraIndicator, TileStates::UraDoraIndicator);
            }

            deadWallTileSet_.clear();
        }

        void makeDeadWall()
        {
            clearDeadWall();
            int deadWallIdx = (randomEngine() % tileCount);

            int i = 0;
            int j = 0;
            while (i < deadWallTileCount) {
                j = (deadWallIdx + i) % tileCount;
                tileSet_[j]->setTileState(TileStates::Wanpai);

                if (i == 4)
                    tileSet_[j]->setTileState(TileStates::DoraIndicator);
                if (i == 5)
                    tileSet_[j]->setTileState(TileStates::UraDoraIndicator);

//                getTile((deadWallIdx + i) % tileCount).setTileState(TileStates::Wanpai);
                i++;
            }

            // TODO: Add customization of dice throwing and wall splitting
            wallShift_ = (randomEngine() % 12);
            shiftTiles(tileCount - deadWallIdx - deadWallTileCount - wallShift_);
        }

        void shiftTiles(int shift)
        {
            std::array<TDTile*, tileCount> arr;

            int i = 0;
            for (TDTile* tile : tileSet_) {
                arr[(i + shift) % tileCount] = tile;

                i++;
            }

            tileSet_ = std::move(arr);
        }

        void updateDora()
        {
            std::vector<Tiles> dora;
            std::vector<bool> uraDora;

            for (int i = 0; i < tileCount; i++) {
                TDTile * tile = getTilePointer(i);

                tile->unsetTileState(TileStates::Dora, TileStates::UraDora);

                // Mark (ura) dora indicators
                bool ura_dora = tile->hasTileState(TileStates::UraDoraIndicator);
                if (tile->hasTileState(TileStates::DoraIndicator) || ura_dora) {
                    dora.push_back(TileUtils::shiftTile(tile));
                    uraDora.push_back(ura_dora);
                }

                // Aka dora
                if (TileInfoMap::get(tile->getTile()).red)
                    tile->setTileState(TileStates::AkaDora);
            }

            for (int i = 0; i < tileCount; i++) {
                TDTile * tile = getTilePointer(i);

                // Check if tile is dora and mark as such
                if (std::find(dora.begin(), dora.end(), tile->getTile()) != dora.end()) {
                    // TODO: Use find only once.
                    int idx = std::find(dora.begin(), dora.end(), tile->getTile()) - dora.begin();

                    // Mark ura dora separately
                    if (uraDora[idx])
                        tile->setTileState(TileStates::UraDora);
                    else
                        tile->setTileState(TileStates::Dora);




                }
            }
        }

        TDTile * grabTileImpl(const TileOrigins dest = TileOrigins::Haiyama, const TileLocations loc = TileLocations::Te, const TileStates trns = TileStates::Tsumohai)
        {
            // TODO: Implement ryuukyoku conditions.

            auto tile = getTilePointer(tileOffset_);
            tileOffset_++;

            tile->setTileState(TileStates::Tehai);
//            tile->setTileState(TileStates::Tsumohai);
            tile->setLocOrigState(loc, dest, trns);

            return tile;
        }

        TDPlayer * getPlayer(const TileOrigins origin)
        {
            TDPlayer * player = nullptr;
            switch (origin) {
                default:
                    player = getPlayer(0);
                    break;
                case TileOrigins::Nancha:
                    player = getPlayer(1);
                    break;
                case TileOrigins::Shacha:
                    player = getPlayer(2);
                    break;
                case TileOrigins::Peicha:
                    player = getPlayer(3);
                    break;
            }

            return player;
        }

        TDTile * grabTile(const TileOrigins origin, const TileStates trns = TileStates::Tsumohai)
        {
            return grabTile(getPlayer(origin), trns);
        }

        TDTile * grabTile(TDPlayer * player, const TileStates trns = TileStates::Tsumohai)
        {
            TDTile * tile = grabTileImpl(player->getOrigin(), TileLocations::Te, trns);
            player->addTile(tile);

            return tile;
        }

        void discardTile(const TileOrigins origin, TDTile* tile)
        {
            getPlayer(origin)->cutTile(tile);
            discardTile(tile);
        }

        void discardTile(TDPlayer * player, TDTile* tile)
        {
            player->cutTile(tile);
            discardTile(tile);
        }

        void discardTile(TDTile* tile)
        {
            tile->setLocOrigState(TileLocations::Kawa, tile->getOrigin(), tile->getTransitionState());
            tile->unsetTileState(TileStates::Tehai);
            tile->setTileState(TileStates::Sutehai);
            tile->unsetTileState(TileStates::Closed);
            tile->setTileState(TileStates::Open);
            getPlayer(tile->getOrigin())->cutTile(tile);
            updateKawa();
        }

        std::string tilesToString() {
            std::stringstream ss;

            for (int i = 0; i < tileCount; i++) {
                ss << i << ": " << tileSet_[i]->toString() << std::endl;
            }

            return ss.str();
        }

        int countKawahai() const
        {
            int i = 0;
            for (TDTile * tile : tileSet_) {
                if (tile->getLocation() == TileLocations::Kawa)
                    i++;
            }

            return i;
        }

        int countWanpai() const
        {
            int i = 0;
            for (TDTile * tile : tileSet_) {
                if (tile->hasTileState(TileStates::Wanpai))
                    i++;
            }

            return i;
        }

        int countYamahai() const
        {
            int i = 0;
            for (TDTile * tile : tileSet_) {
                if ((tile->getLocation() == TileLocations::Yama) && (!tile->hasTileState(TileStates::Wanpai)))
                    i++;
            }

            return i;
        }

        int countTehai() const
        {
            int i = 0;
            for (TDTile * tile : tileSet_) {
                if (tile->getLocation() == TileLocations::Te)
                    i++;
            }

            return i;
        }

        void addPlayers()
        {
            players_[0] = new TDPlayer{TileOrigins::Toncha};
            players_[1] = new TDPlayer{TileOrigins::Nancha};
            players_[2] = new TDPlayer{TileOrigins::Shacha};
            players_[3] = new TDPlayer{TileOrigins::Peicha};
        }

        void addPlayer(TDPlayer * player)
        {
            TileOrigins origin = player->getOrigin();

            switch (origin) {
                default:
                    return;
                case TileOrigins::Toncha:
                    players_[0] = player;
                case TileOrigins::Nancha:
                    players_[1] = player;
                case TileOrigins::Shacha:
                    players_[2] = player;
                case TileOrigins::Peicha:
                    players_[3] = player;
            }
        }

        TDPlayer * getPlayer(int idx)
        {
            return players_[(idx < 0 ? 0 : idx) % 4];
        }

        void dealTiles()
        {
            for (int i = 0; i < 13; i++) {
                grabTile(TileOrigins::Toncha, TileStates::Haipai);
                grabTile(TileOrigins::Nancha, TileStates::Haipai);
                grabTile(TileOrigins::Shacha, TileStates::Haipai);
                grabTile(TileOrigins::Peicha, TileStates::Haipai);
            }

            grabTile(TileOrigins::Toncha, TileStates::Tsumohai);
        }

        std::vector<TDTile*> getIndicatedDora() const
        {
            std::vector<TDTile*> dora;

            for (TDTile * tile : tileSet_) {
                if (tile->hasTileState(TileStates::Dora) && !tile->hasTileState(TileStates::AkaDora))
                    dora.push_back(tile);
            }

            return dora;
        }

        std::vector<TDTile*> getIndicatedUraDora() const
        {
            std::vector<TDTile*> dora;

            for (TDTile * tile : tileSet_) {
                if (tile->hasTileState(TileStates::UraDora))
                    dora.push_back(tile);
            }

            return dora;
        }

        std::vector<TDTile*> getDora() const
        {
            std::vector<TDTile*> dora;

            for (TDTile * tile : tileSet_) {
                if (tile->hasTileState(TileStates::Dora) || tile->hasTileState(TileStates::AkaDora) || tile->hasTileState(TileStates::UraDora))
                    dora.push_back(tile);
            }

            return dora;
        }

        void updateKawa()
        {
            players_[0]->clearKawa();
            players_[1]->clearKawa();
            players_[2]->clearKawa();
            players_[3]->clearKawa();

            for (TDTile * tile : tileSet_) {
                if ((tile->getLocation() == TileLocations::Kawa) && tile->getOrigin() == TileOrigins::Toncha)
                    players_[0]->addToKawa(tile);
                if ((tile->getLocation() == TileLocations::Kawa) && tile->getOrigin() == TileOrigins::Nancha)
                    players_[1]->addToKawa(tile);
                if ((tile->getLocation() == TileLocations::Kawa) && tile->getOrigin() == TileOrigins::Shacha)
                    players_[2]->addToKawa(tile);
                if ((tile->getLocation() == TileLocations::Kawa) && tile->getOrigin() == TileOrigins::Peicha)
                    players_[3]->addToKawa(tile);
            }
        }

//        std::vector<TDTile> checkPon(const TileOrigins origin) const
//        {
//
//        }

        static const int tileCount = TTileCount;
        static const int deadWallTileCount = 2*7;
        static const int numberTileCount = 9*4;
        static const int honorTileCount = 7*4;

    protected:
        bool useAkaDora_ = true; /// Red dora.
        std::array<TDTile*, tileCount> tileSet_;
        std::array<TDTile*, tileCount> orderedTileSet_;
        std::vector<TDTile*> deadWallTileSet_;
        std::array<TDPlayer*, 4> players_;

        int wallShift_ = 0;
        int tileOffset_ = 0;
    };

    template<Languages TLanguage, int TTileCount>
    std::ostream& operator << (std::ostream &os, const Table<TLanguage, TTileCount>& table)
    {
        for (int i = 0; i < table.tileCount; i++) {
            auto tile = table.getTile(i);
            os << std::setfill('0') << std::setw(3) << i << ": " << tile << std::endl;
        }

        return os;
    }
}

#endif //SUZUME_TABLE_HPP
