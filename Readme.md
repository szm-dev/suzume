# suzume (すずめ)

A lightweight Riichi Mahjong engine written in C++14 (still in pre-alpha stage!).

## Description

An in-depth paragraph about your project and overview of use.

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