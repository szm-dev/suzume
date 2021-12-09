#include <iostream>

#include "tiles/TilesEnum.hpp"
#include "settings/Localization.hpp"
#include "settings/LocalizationUtils.hpp"

#include "tiles/Tile.hpp"
#include "table/Table.hpp"
#include "hand/Analysis.hpp"

int main()
{
//    std::cout << szm::localize<szm::Tiles::Chun>() << std::endl;
//    std::cout << szm::localize<szm::Languages::Japanese>(szm::Tiles::Chun) << std::endl;
//    std::cout << szm::localize<szm::Languages::JapanesePhonetic>(szm::Tiles::Sha) << std::endl;
//    std::cout << szm::localize<szm::Languages::JapaneseKanji>(szm::Tiles::Hatu) << std::endl;
//    std::cout << szm::localize<szm::Languages::JapanesePhonetic>(szm::Tiles::ManR5) << std::endl;
//    std::cout << szm::localize<szm::Languages::Japanese>(szm::Tiles::ManR5) << std::endl;
//
//    std::cout << std::endl;
//
//    auto hatu = szm::Tile<szm::Languages::Japanese>(szm::Tiles::Hatu, szm::TileStates::Open);
//    std::cout << hatu << std::endl;

    {
        auto table = szm::Table<szm::Languages::Japanese>{};
        //    auto table = szm::Table<szm::Languages::English>{};
        std::cout << "全牌数: " << szm::Table<szm::Languages::Japanese, 136>::tileCount << std::endl;
        std::cout << table << std::endl;
        std::cout << std::endl;

        table.shuffle();
        table.makeDeadWall();
        table.updateDora();
        table.addPlayers();

        std::cout << "洗牌: " << std::endl;
        std::cout << table << std::endl;
        std::cout << std::endl;

        std::cout << "配牌: " << std::endl;
        table.dealTiles();
        std::cout << table << std::endl;
        std::cout << std::endl;

        auto toncha = table.getPlayer(0);
        auto nancha = table.getPlayer(1);
        auto shacha = table.getPlayer(2);
        auto peicha = table.getPlayer(3);

        std::cout << "山牌: " << table.countYamahai() << std::endl;
        std::cout << "王牌: " << table.countWanpai() << std::endl;
        std::cout << "河牌: " << table.countKawahai() << std::endl;
        std::cout << "手牌: " << table.countTehai() << std::endl;

        toncha->sortHand();
        nancha->sortHand();
        shacha->sortHand();
        peicha->sortHand();

        std::cout << *toncha << std::endl;
        std::cout << *nancha << std::endl;
        std::cout << *shacha << std::endl;
        std::cout << *peicha << std::endl;

        auto t = (*toncha)[0];
        table.discardTile(toncha, t);

        std::cout << *toncha << std::endl;

        nancha->sortHand();
        t = table.grabTile(nancha);

        std::cout << "ツモ牌: " << *t << std::endl;

        std::cout << *nancha << std::endl;

        auto partialRuns = szm::Analysis::identifyPartialRuns(
                nancha->getHand().getTiles());

        if (!partialRuns.empty()) {
            std::cout << "***** 未完成順子 (" << partialRuns.size() << ") *****"
                      << std::endl;
            std::cout << partialRuns << std::endl;
//            for (auto run: partialRuns) {
//                std::cout << run;
//                std::cout << "======" << std::endl;
//            }
        }

        auto fullRuns = szm::Analysis::identifyFullRuns(
                nancha->getHand().getTiles());

        if (!fullRuns.empty()) {
            std::cout << "***** 完成した順子 (" << fullRuns.size() << ") *****"
                      << std::endl;
            std::cout << fullRuns << std::endl;
//            for (auto run: fullRuns) {
//                std::cout << run;
//                std::cout << "======" << std::endl;
//            }
        }

        std::cout << szm::localize<szm::Languages::Japanese>(szm::Tiles::Chars2) << " (#seen): " << table.getNumberSeen(nancha, szm::Tiles::Chars2) << std::endl;
    }

//    {
//        auto table = szm::Table<szm::Languages::English>{};
//        std::cout << "All tiles: " << szm::Table<szm::Languages::English, 136>::tileCount << std::endl;
//        std::cout << table << std::endl;
//        std::cout << std::endl;
//
//        table.shuffle();
//        table.makeDeadWall();
//        table.updateDora();
//        table.addPlayers();
//
//        std::cout << "Shuffling tiles:" << std::endl;
//        std::cout << table << std::endl;
//        std::cout << std::endl;
//
//        table.dealTiles();
//
//        std::cout << "Dealing tiles:" << std::endl;
//        std::cout << table << std::endl;
//        std::cout << std::endl;
//
//        auto toncha = table.getPlayer(0);
//        auto nancha = table.getPlayer(1);
//        auto shacha = table.getPlayer(2);
//        auto peicha = table.getPlayer(3);
//
//        std::cout << "Yamahai (wall tiles): " << table.countYamahai() << std::endl;
//        std::cout << "Wanpai (dead tiles): " << table.countWanpai() << std::endl;
//        std::cout << "Kawahai (discarded tiles): " << table.countKawahai() << std::endl;
//        std::cout << "Tehai (tiles in hand): " << table.countTehai() << std::endl;
//
//        toncha->sortHand();
//        nancha->sortHand();
//        shacha->sortHand();
//        peicha->sortHand();
//
//        std::cout << *toncha << std::endl;
//        std::cout << *nancha << std::endl;
//        std::cout << *shacha << std::endl;
//        std::cout << *peicha << std::endl;
//
//        auto t = (*toncha)[0];
//        table.discardTile(toncha, t);
//
//        std::cout << *toncha << std::endl;
//
//        nancha->sortHand();
//        t = table.grabTile(nancha);
//
//        std::cout << "Current tile: " << *t << std::endl;
//
//        std::cout << *nancha << std::endl;
//
//        auto partialRuns = szm::Analysis::identifyPartialRuns(
//                nancha->getHand().getTiles());
//
//        if (!partialRuns.empty()) {
//            std::cout << "***** Partial runs (" << partialRuns.size() << ") *****"
//                      << std::endl;
//            for (auto run: partialRuns) {
//                std::cout << run;
//                std::cout << "======" << std::endl;
//            }
//        }
//
//        auto fullRuns = szm::Analysis::identifyFullRuns(
//                nancha->getHand().getTiles());
//
//        if (!fullRuns.empty()) {
//            std::cout << "***** Full runs (" << fullRuns.size() << ") *****"
//                      << std::endl;
//            for (auto run: fullRuns) {
//                std::cout << run;
//                std::cout << "======" << std::endl;
//            }
//        }
//    }

//    std::cout << std::endl;
//    std::cout << *t << std::endl;

//    auto tile = table.grabTile(szm::TileOrigins::Toncha);
//    std::cout << table << std::endl;
//    std::cout << std::endl;
//    std::cout << "手牌: " << *tile << std::endl;
//    table.discardTile(tile);
//    std::cout << "捨て牌: " << *tile << std::endl;

    return 0;
}
