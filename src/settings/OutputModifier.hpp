//
// Created by Hamza El-Kebir on 12/5/21.
//

#ifndef SUZUME_OUTPUTMODIFIER_HPP
#define SUZUME_OUTPUTMODIFIER_HPP

#include <ostream>

namespace szm {
    // Original code from: https://stackoverflow.com/a/17469726
    enum ModifierCode {
        FG_BLACK    = 30,
        FG_RED      = 31,
        FG_GREEN    = 32,
        FG_YELLOW   = 33,
        FG_BLUE     = 34,
        FG_MAGENTA  = 35,
        FG_CYAN     = 36,
        FG_WHITE    = 37,
        FG_DEFAULT  = 39,
        BG_BLACK    = 40,
        BG_RED      = 41,
        BG_GREEN    = 42,
        BG_YELLOW   = 43,
        BG_BLUE     = 44,
        BG_MAGENTA  = 45,
        BG_CYAN     = 46,
        BG_WHITE    = 47,
        BG_DEFAULT  = 49
    };
    class Modifier {
        ModifierCode code;
    public:
        Modifier() : code{FG_DEFAULT} {}

        Modifier(ModifierCode pCode) : code(pCode) {}
        friend std::ostream&
        operator<<(std::ostream& os, const Modifier& mod) {
            return os << "\033[" << mod.code << "m";
        }
    };
}

#endif //SUZUME_OUTPUTMODIFIER_HPP
