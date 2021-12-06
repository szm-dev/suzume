//
// Created by Hamza El-Kebir on 12/5/21.
//

#ifndef SUZUME_GLOBALFLAGS_HPP
#define SUZUME_GLOBALFLAGS_HPP

#define SZM_RIICHI_TILE_COUNT 136

/// Use ANSI escape characters to colorize debug output.
#define SZM_OUTPUT_COLORS 1

/// Whether or nor Man or Wan is used.
#define SZM_MA_OR_WA マ //　ワ

#define XSTR(s) STR(s)
#define STR(s) #s

#define MAWA XSTR(SZM_MA_OR_WA)

#endif //SUZUME_GLOBALFLAGS_HPP
