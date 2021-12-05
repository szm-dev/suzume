cmake_minimum_required(VERSION 3.20)
project(suzume)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(suzume src/main.cpp src/tiles/Tile.cpp src/tiles/Tile.hpp src/settings/Languages.hpp src/tiles/TilesEnum.hpp src/settings/Localization.hpp src/settings/LocalizationUtils.hpp src/settings/Localization.cpp src/table/Table.cpp src/table/Table.hpp src/settings/Random.hpp src/tiles/TileUtils.hpp src/tiles/TileUtils.cpp)
