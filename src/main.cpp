#include <iostream>

#include "tiles/TilesEnum.hpp"
#include "settings/Localization.hpp"
#include "settings/LocalizationUtils.hpp"

#include "tiles/Tile.hpp"
#include "table/Table.hpp"

int main()
{
    std::cout << szm::localize<szm::Tiles::Chun>() << std::endl;
    std::cout << szm::localize<szm::Languages::Japanese>(szm::Tiles::Chun) << std::endl;
    std::cout << szm::localize<szm::Languages::JapanesePhonetic>(szm::Tiles::Sha) << std::endl;
    std::cout << szm::localize<szm::Languages::JapaneseKanji>(szm::Tiles::Hatu) << std::endl;
    std::cout << szm::localize<szm::Languages::JapanesePhonetic>(szm::Tiles::ManR5) << std::endl;
    std::cout << szm::localize<szm::Languages::Japanese>(szm::Tiles::ManR5) << std::endl;

    std::cout << std::endl;

    auto hatu = szm::Tile<szm::Languages::Japanese>(szm::Tiles::Hatu, szm::TileStates::Open);
    std::cout << hatu << std::endl;

    auto table = szm::Table<szm::Languages::Japanese>{};
//    auto table = szm::Table<szm::Languages::English>{};
    std::cout << table << std::endl;
    std::cout << std::endl;

    table.shuffle();
    table.makeDeadWall();
    table.updateDora();
    table.addPlayers();
    table.dealTiles();

    auto toncha = table.getPlayer(0);
    auto nancha = table.getPlayer(1);
    auto shacha = table.getPlayer(2);
    auto peicha = table.getPlayer(3);

    std::cout << "Yamahai: " << table.countYamahai() << std::endl;
    std::cout << "Wanpai: " << table.countWanpai() << std::endl;
    std::cout << "Kawahai: " << table.countKawahai() << std::endl;
    std::cout << "Tehai: " << table.countTehai() << std::endl;

//    auto tile = table.grabTile(szm::TileOrigins::Toncha);

    toncha->sortHand();

    std::cout << *toncha << std::endl;
    std::cout << *nancha << std::endl;
    std::cout << *shacha << std::endl;
    std::cout << *peicha << std::endl;

    auto t = (*toncha)[0];
    table.discardTile(toncha, t);
    table.updateKawa();

    std::cout << *toncha << std::endl;

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
