//
// Created by Hamza El-Kebir on 12/5/21.
//

#ifndef SUZUME_ANALYSIS_HPP
#define SUZUME_ANALYSIS_HPP

#include "tiles/TilesEnum.hpp"
#include "tiles/TileUtils.hpp"
#include <vector>
#include <algorithm>
#include <iostream>

namespace szm {
    class Analysis {
    public:
        template <Languages TLanguage>
        using TilesVec = std::vector<Tile<TLanguage>*>;

        template <Languages TLanguage>
        using TilesVecVec = std::vector<std::vector<Tile<TLanguage>*>>;

        template <Languages TLanguage>
        static std::vector<TileWaits> identifySimpleTileWaits(TilesVecVec<TLanguage> tileSets)
        {
            std::vector<TileWaits> waits;
            waits.reserve(tileSets.size());

            for (const TilesVec<TLanguage>& tiles : tileSets) {
                if (isRyanmen(tiles)) {
                    waits.push_back(TileWaits::Ryanmen);
                    continue;
                } else if (isKanchan(tiles)) {
                    waits.push_back(TileWaits::Kanchan);
                    continue;
                } else if (isPenchan(tiles)) {
                    waits.push_back(TileWaits::Penchan);
                    continue;
                } else if (isShuntsu(tiles)) {
                    waits.push_back(TileWaits::Shuntsu);
                    continue;
                } else if (isKoutsu(tiles)) {
                    waits.push_back(TileWaits::Koutsu);
                    continue;
                } else if (isKantsu(tiles)) {
                    waits.push_back(TileWaits::Kantsu);
                    continue;
                } else
                    waits.push_back(TileWaits::NoWait);
            }

            return waits;
        }

        template <Languages TLanguage>
        static bool isShuntsu(const TilesVec<TLanguage>& tiles_)
        {
            // Check if there are three tiles.
            if (tiles_.size() != 3)
                return false;

            // Check if all tiles are suits.
            if (!(TileInfoMap::get(tiles_[0]).suits && TileInfoMap::get(tiles_[1]).suits && TileInfoMap::get(tiles_[2]).suits))
                return false;

            // Check if all tiles have the same suit.
            if (!((TileInfoMap::get(tiles_[0]).cat ==
                   TileInfoMap::get(tiles_[1]).cat) &&
                  (TileInfoMap::get(tiles_[1]).cat ==
                   TileInfoMap::get(tiles_[2]).cat)))
                return false;

            TilesVec<TLanguage> tiles{tiles_};
            std::sort(tiles.begin(), tiles.end(), [&](auto * a, auto * b) {return (*a < *b);});

            // Check if the triad is a sequence.
            if (((TileInfoMap::get(tiles[2]).number - TileInfoMap::get(tiles[1]).number) == 1) &&
                ((TileInfoMap::get(tiles[1]).number - TileInfoMap::get(tiles[0]).number) == 1))
                return true;

            return false;
        }

        template <Languages TLanguage>
        static bool isKoutsu(const TilesVec<TLanguage>& tiles_)
        {
            // Check if there are three tiles.
            if (tiles_.size() != 3)
                return false;

            // Check if all tiles have the same category.
            if (!((TileInfoMap::get(tiles_[0]).cat ==
                   TileInfoMap::get(tiles_[1]).cat) &&
                  (TileInfoMap::get(tiles_[1]).cat ==
                   TileInfoMap::get(tiles_[2]).cat)))
                return false;

            // Check if tiles are the same.
            if (!((TileInfoMap::get(tiles_[0]).number ==
                   TileInfoMap::get(tiles_[1]).number) &&
                  (TileInfoMap::get(tiles_[1]).number ==
                   TileInfoMap::get(tiles_[2]).number)))
                return false;
            else
                return true;
        }

        template <Languages TLanguage>
        static bool isKantsu(const TilesVec<TLanguage>& tiles_)
        {
            // Check if there are four tiles.
            if (tiles_.size() != 4)
                return false;

            // Check if all tiles have the same category.
            if (!((TileInfoMap::get(tiles_[0]).cat ==
                   TileInfoMap::get(tiles_[1]).cat) &&
                  (TileInfoMap::get(tiles_[1]).cat ==
                   TileInfoMap::get(tiles_[2]).cat) &&
                  (TileInfoMap::get(tiles_[2]).cat ==
                   TileInfoMap::get(tiles_[3]).cat)))
                return false;

            // Check if tiles are the same.
            if (!((TileInfoMap::get(tiles_[0]).number ==
                   TileInfoMap::get(tiles_[1]).number) &&
                  (TileInfoMap::get(tiles_[1]).number ==
                   TileInfoMap::get(tiles_[2]).number) &&
                  (TileInfoMap::get(tiles_[2]).number ==
                   TileInfoMap::get(tiles_[3]).number)))
                return false;
            else
                return true;
        }

        template <Languages TLanguage>
        static bool isRyanmen(const TilesVec<TLanguage>& tiles)
        {
            // Check if there are two tiles.
            if (tiles.size() != 2)
                return false;

            // Check if both tiles are suits.
            if (!(TileInfoMap::get(tiles[0]).suits && TileInfoMap::get(tiles[1]).suits))
                return false;

            // Check if both tiles have the same suit.
            if (TileInfoMap::get(tiles[0]).cat != TileInfoMap::get(tiles[1]).cat)
                return false;

            // Check if either tile is a terminal.
            if (TileInfoMap::get(tiles[0]).terminal || TileInfoMap::get(tiles[1]).terminal)
                return false;

            // Check if tiles are consecutive.
            if ((TileInfoMap::get(tiles[1]).number - TileInfoMap::get(tiles[0]).number) == 1 ||
                (TileInfoMap::get(tiles[0]).number - TileInfoMap::get(tiles[1]).number) == 1)
                return true;

            return false;
        }

        template <Languages TLanguage>
        static bool isKanchan(const TilesVec<TLanguage>& tiles)
        {
            // Check if there are two tiles.
            if (tiles.size() != 2)
                return false;

            // Check if both tiles are suits.
            if (!(TileInfoMap::get(tiles[0]).suits && TileInfoMap::get(tiles[1]).suits))
                return false;

            // Check if both tiles have the same suit.
            if (TileInfoMap::get(tiles[0]).cat != TileInfoMap::get(tiles[1]).cat)
                return false;

            // Check if tiles have a gap of one.
            if ((TileInfoMap::get(tiles[1]).number - TileInfoMap::get(tiles[0]).number) == 2 ||
                (TileInfoMap::get(tiles[0]).number - TileInfoMap::get(tiles[1]).number) == 2)
                return true;

            return false;
        }

        template <Languages TLanguage>
        static bool isPenchan(const TilesVec<TLanguage>& tiles)
        {
            // Check if there are two tiles.
            if (tiles.size() != 2)
                return false;

            // Check if both tiles are suits.
            if (!(TileInfoMap::get(tiles[0]).suits && TileInfoMap::get(tiles[1]).suits))
                return false;

            // Check if both tiles have the same suit.
            if (TileInfoMap::get(tiles[0]).cat != TileInfoMap::get(tiles[1]).cat)
                return false;

            // Check if either tile is a terminal.
            if (!(TileInfoMap::get(tiles[0]).terminal || TileInfoMap::get(tiles[1]).terminal))
                return false;

            // Check if tiles are consecutive.
            if ((TileInfoMap::get(tiles[1]).number - TileInfoMap::get(tiles[0]).number) == 1 ||
                (TileInfoMap::get(tiles[0]).number - TileInfoMap::get(tiles[1]).number) == 1)
                return true;

            return false;
        }

        /**
         * Identifies full runs from a set of tiles.
         *
         * @sa ::identifyRuns
         *
         * @tparam TLanguage Language enum.
         * @param tiles Vector of tiles.
         * @return Vector of subvectors of unique full runs.
         */
        template <Languages TLanguage>
        static TilesVecVec<TLanguage> identifyFullRuns(TilesVec<TLanguage> tiles)
        {
            return identifyRuns(tiles, false, true);
        }

        /**
         * Identifies partial runs from a set of tiles.
         *
         * @sa ::identifyRuns
         *
         * @tparam TLanguage Language enum.
         * @param tiles Vector of tiles.
         * @return Vector of subvectors of unique partial runs.
         */
        template <Languages TLanguage>
        static TilesVecVec<TLanguage> identifyPartialRuns(TilesVec<TLanguage> tiles)
        {
            return identifyRuns(tiles, true, false);
        }

        /**
         * Identifies runs from a set of tiles.
         *
         * @details Runs can only occur in tiles from the same suit. Honor tiles
         * (three dragons, winds) cannot form runs. A run is a set of three
         * ascending number tiles of the same suite, e.g.:
         * \code{.unparsed}
         *     | 3 * | 4 * | 5 * |
         * \endcode
         * where \c * is either characters, dots, or sticks.
         *
         * Partial runs come in the following classes:
         *
         * <ol>
         * <li> \c Ryanmen (two-sided):</li>
         *      | 4 | 5 | (waiting for 2 or 6)
         * <li> \c Knachan (center):</li>
         *      | 7 | 9 | (waiting for 8)
         * <li> \c Penchan (sides):</li>
         *      | 1 | 2 | (waiting for 3) <br>
         *      | 8 | 9 | (waiting for 7)
         * </ol>
         *
         * In the implementation of the algorithm, ryanmen and penchan are
         * functionally equivalent. Since the order is immaterial, tiles
         * ordered in ascending order are returned.
         *
         * @tparam TLanguage Language enum.
         * @param tiles Vector of tiles.
         * @param partial If true, partial runs will be recorded.
         * @param full If true, full runs will be recorded
         *
         * @return A vector of subvectors of tiles, each subvector being a
         * (partial) run.
         */
        template <Languages TLanguage>
        static TilesVecVec<TLanguage> identifyRuns(TilesVec<TLanguage> tiles, bool partial=true, bool full=true)
        {
            std::sort(tiles.begin(), tiles.end(), [&](auto * a, auto * b) {return (*a < *b);});

            TilesVecVec<TLanguage> runs;
            TilesVec<TLanguage> tmp;

            auto expandRun = [&] (int idx, TilesVec<TLanguage> &tmpVec, bool stop2 = false) {
                Tile<TLanguage> * t1 = tiles[idx];

                if (TileInfoMap::get(t1).honors)
                    return;

                tmpVec.push_back(t1);

                int no1 = TileInfoMap::get(t1).number;
                auto cat1 = TileInfoMap::get(t1).cat;


                int i = idx;
                int count = 1;
                bool kanchan = false;
                while (i < tiles.size()) {
                    if (kanchan)
                        break;

                    if (count == 3)
                        break;

                    Tile<TLanguage> * t2 = tiles[i];

                    if (!TileInfoMap::get(t2).suits) {
                        i++;
                        continue;
                    }

                    auto cat2 = TileInfoMap::get(t2).cat;

                    if (cat2 != cat1) {
                        i++;
                        continue;
                    }

                    no1 = TileInfoMap::get(tmpVec.back()).number;
                    int no2 = TileInfoMap::get(t2).number;

                    if (no1 == no2) {
                        i++;
                        continue;
                    }

                    if ((no2 - no1) == 1) {
                        if (stop2 && count == 2) {
                            count++;
                            break;
                        } else {
                            tmpVec.push_back(t2);
                            count++;
                        }
                    } else if (((no2 - no1) == 2) && (count < 2)) {
                        tmpVec.push_back(t2);
                        kanchan = true;
                        count++;
                    }

                    i++;
                }
            };

            auto criterion = [&](int l) {
                if (partial && !full)
                    return l == 2;
                else if (!partial && full)
                    return l == 3;

                return l >= 2;
            };

            int i = 0;
            for (auto tile : tiles) {
                tmp.clear();
                expandRun(i, tmp);

                // Discard partial run if only one element is recorded.
                if (criterion(tmp.size())) {
                    // Check if run was previously recorded.
                    bool isSame = false;
                    for (auto run: runs) {
                        if ((run.size() == tmp.size()) && equal(run, tmp)) {
                            isSame = true;
                            break;
                        }
                    }

                    if (!isSame)
                        runs.push_back(tmp);
                }

                if (partial) {
                    // Limit to 2 elements
                    tmp.clear();
                    expandRun(i, tmp, true);

                    // Discard partial run if only one element is recorded.
                    if (criterion(tmp.size())) {
                        // Check if run was previously recorded.
                        bool isSame = false;
                        for (auto run: runs) {
                            if ((run.size() == tmp.size()) && equal(run, tmp)) {
                                isSame = true;
                                break;
                            }
                        }

                        if (!isSame)
                            runs.push_back(tmp);
                    }
                }

                i++;

            }

            return runs;
        }

//        template <typename TType>
//        static bool contains(const std::vector<TType>& vec, const TType& val)
//        {
//            return std::find(vec.begin(), vec.end(), val);
//        }

        template <Languages TLanguage>
        static bool contains(const TilesVec<TLanguage>& vec, const Tile<TLanguage>* val)
        {
            for (auto v : vec) {
                if (v->getTile() == val->getTile())
                    return true;
            }

            return false;
        }

        template <Languages TLanguage>
        static bool equal(const TilesVec<TLanguage>& vec1, const TilesVec<TLanguage>& vec2)
        {
            auto comparator = [] (const Tile<TLanguage>* a, const Tile<TLanguage>* b) {
                return (a->getTile() == b->getTile());
            };

            return std::equal(vec1.begin(), vec1.end(), vec2.begin(), comparator);
        }
    };

    template<Languages TLanguage>
    std::ostream& operator << (std::ostream &os, const std::vector<std::vector<Tile<TLanguage>*>>& tileSets)
    {
        auto waits = Analysis::identifySimpleTileWaits(tileSets);
        int i = 0;
        for (const std::vector<Tile<TLanguage>*> & tiles : tileSets) {
            os << tiles << " > " << localize<TLanguage>(waits[i]) << std::endl;
            os << "===" << std::endl;
            i++;
        }

        return os;
    }
}


#endif //SUZUME_ANALYSIS_HPP
