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
        using TilesVecVec = std::vector<TilesVec<TLanguage>>;

//        typedef std::vector<Tiles> TDTilesVec;
//        typedef std::vector<std::vector<Tiles>> TDTilesVecVec;

        template <Languages TLanguage>
        static TilesVecVec<TLanguage> identifyFullRuns(TilesVec<TLanguage> tiles)
        {
            return identifyRuns(tiles, false, true);
        }

        template <Languages TLanguage>
        static TilesVecVec<TLanguage> identifyPartialRuns(TilesVec<TLanguage> tiles)
        {
            return identifyRuns(tiles, true, false);
        }

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
}


#endif //SUZUME_ANALYSIS_HPP
