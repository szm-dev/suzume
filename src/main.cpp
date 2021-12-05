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

    auto tile = table.grabTile();

    std::cout << table << std::endl;

    std::cout << std::endl;

    std::cout << "手牌: " << tile << std::endl;

//    std::cout << "\033[1;31mbold red text\033[0m\n";

//    auto tableNoAkaDora = szm::Table<>{false};
//    std::cout << tableNoAkaDora.tilesToString() << std::endl;

    return 0;
}
