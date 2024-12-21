Boulder VIC
===


Description
---

This game is a Boulder Dash like game for the Commodore VIC-computer. I developped it as an exercice of C programming for old computers.

It does include:

- Not one, not three, but TWO (2) levels
- Colors (multiple !!)
- Sound
- Keyboard gameplay
  - `X`, `C`, `V` and `D` keys to move
  - `R` key to restart a level
- Basic gravity management (rocks and diamonds can fall, don't stay below)


It does not include:

- Crysis like graphics
- Possibility to push rocks
- Multi-screen levels


Requirements
---

A Vic-20 with 3 kB RAM expansion (no less, no more)


How to build
---

- Install Visual Code Studio + [VS64 extension](https://marketplace.visualstudio.com/items?itemName=rosc.vs64)
- Install [LLVM-MOS-SDK](https://github.com/llvm-mos/llvm-mos-sdk)
- Update `llvmPath` setting from `.vscode/c_cpp_properties.json` as needed
- (Optionnal) Install [VICE emulator] (https://vice-emu.sourceforge.io/), and set it's setting as needed. You may want to setup its drive to `Virtual device` with type `Host file system` and set the host directory to the `disk` file in this this repository


Charset
---

This game use a user defined charset with the needed characters for the game. This charset is build using:

- `resources/gencharset.sh` script, which takes all text files (except for `template.txt`) from `resources/chars` directory, and convert if to a binary file named `resources/charset.bin`. An empty template file is provided, and may be used to create new characters. Files MUST be named `char-id_anything-you-want.txt` (with `char-id` between 0 and 63).
- If you change the charset, you may modify `src/include/graphics.h` header file (`CHARSET_SIZE` value and `Charset new characters` section).
- The file `resources/charset.bin` is then copied to the `disk` directory of the repository


Levels
---

You may add new levels using:

- `resources/genlevels.sh` script, which takes all text files from `resources/levels` directory, and convert them to a binary file named `resources/level_<number>.bin`. Files MUST be named `level_<number>.txt`.
- If you add or remove levels, you may modify `src/include/gameplay.h` header file (`MAX_LEVEL` value).
- The files `resources/level_<number>.bin` are then copied to the `disk` directory of the repository

A special `resources/levels/title.txt` (and `resources/title.bin`) file is dedicated to the title screen, and is included in the above process.



Trivia
--- 

- There is no usage of `printf` and `sprintf` functions as they are too costly (about 3kB added when used with strings).
- The memory map is described below (with 3 kB expansion)
  - 0x0401 : Start of user RAM
  - 0x1DC8 : Start of user RAM reserved for custom charset
  - 0x1DFF : End of user RAM

- User RAM size is 6655 bytes
- Max program RAM size is 6599 bytes
- Custom charset size is 56 bytes (7 characters, 8 bytes each)


See on Youtube
---

[![See on youtube](./extras/media/thumbnail.png)](https://www.youtube.com/watch?v=6Qauf9p5-1o "Boulder VIC")

Media
--- 

<p align="center">
  <img src="./extras/media/title_screen.png" alt="" />
</p>

<p align="center">
  <img src="./extras/media/level_1.png" alt="" />
</p>

<p align="center">
  <img src="./extras/media/level_2.png" alt="" />
</p>

<p align="center">
  <img src="./extras/media/dead.png" alt="" />
</p>
