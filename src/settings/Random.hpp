//
// Created by Hamza El-Kebir on 12/4/21.
//

#ifndef SUZUME_RANDOM_HPP
#define SUZUME_RANDOM_HPP

#include <random>
#include <chrono>

namespace szm {
    static unsigned generateSeed()
    {
        return std::chrono::system_clock::now().time_since_epoch().count();
    }

    static unsigned seed = generateSeed();
    static auto randomEngine = std::default_random_engine(seed);
}

#endif //SUZUME_RANDOM_HPP
