# suzume (すずめ)

A lightweight Riichi Mahjong engine written in C++14 (still in pre-alpha stage!).

## Description

`suzume` aims to be a fast, bloat-free Mahjong engine, on which servers and game clients, AI testbeds, and more can be built eventually.
`suzume` only depends on a C++14 compliant compiler, and has no external dependencies.
Localization has been a top priority in this project, with extensive support for Japanese and English terminology (more languages can easily be added!).

Currently, the core game flow is being developed, after which the following items will be worked on:

- _Shanten_/_tenpai_ (向聴・聴牌) calculations;
- _Furiten_ (振り聴) checking;
- _Ryuukyoku_ (流局) condition checking;
- _Agari/yaku_ (和了・役) checking and score calculation;
- Automatic grouping of _koutsu_, _shuntsu_, _toitsu_ (刻・順・対子);
- Automatic ranking of tile favorability (based on _yakuhai_ (役牌), game's/own wind (場・自風), state of the field (河)).

### Features

The following features are (or will soon be) implemented:

- [x] Localized terminology (English & Japanese).
- [x] Detailed tracking of present and past tile states:
  - [x] Closed/open tracking (暗・明);
  - [x] Player possession history;
  - [x] Tile location and how it was obtained.
- [x] _Shuntsu_ (run, 順子) and partial _shuntsu_ identification.
- [ ] _Koutsu_ (set, 刻子) and _toitsu_ (対子) identification.
- [ ] Waits (待ち) classification.
- [ ] Hand ranking based on waits and discards.
- [ ] Furiten (振り聴) checking.
- [ ] Shanten (向聴) computation.

## Getting Started

### Dependencies

* CMake
* A C++14 compliant compiler (really, that's all).

### Installing

```
git clone https://github.com/helkebir/suzume
cd suzume
mkdir build && cd build
cmake ..
make
```

### You First Round

*To be completed.*
```
./suzume
```

## Help

Please open an issue (wiki pages and documentation will be added in the near future).
Pull request are always welcome!

## Authors

- [Hamza El-Kebir](https://github.com/helkebir)

## Version History

*Still not quite at the stage of releasing anything...*

## License

This project is licensed under the BSD 3-Clause License. See [`LICENSE`](LICENSE) for details.

## Acknowledgments

Initial inspiration was drawn from Alexey Lisikhin's [`mahjong`](https://github.com/MahjongRepository/mahjong).

## FAQ

Q: _Where does the name come from?_<br>
A: In Japanese, Mahjong is written as 麻雀, where the second character means 'sparrow' (pronounced as 'suzume').
Since we're aiming for a nimble and moddable Mahjong engine, a sparrow seems to be the perfect symbol.

Q: _Where is this project headed?_<br>
A: The main goal is to develop a lightweight AI and to eventually experiment with bot battles (à la [FFT Battleground](https://fftbg.com/)).
As spin-offs to this main goal, we hope to develop an accessible cross-platform Mahjong client to play Mahjong on the go,
besides coming up with analysis tools to study past matches and train AI models.
An extension of this would be to allow online peer-to-peer multiplayer matches. 