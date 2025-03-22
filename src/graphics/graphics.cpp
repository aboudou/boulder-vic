#include "graphics.h"

const uint8_t fileNumber = 0;
const uint8_t driveNumber = 8;
const uint8_t sa_ignore_header = 0; // Values other than 0 seems ignored


/// @brief Copy the 64 first characters from the CHARGEN ROM to the end of MAIN RAM
void copyCharRomToRam() {
    for (char* i = &USR_CHARSET_START_ADDRESS; i < &USR_CHARSET_END_ADDRESS; i++) {
        const char* romAddress = &CHAR_ROM_ADDRESS + (i - &USR_CHARSET_START_ADDRESS);
        *i = *romAddress;
    }
}

/// @brief Colorize the level
void colorizeLevel() {
    for (char* i = &SCREEN_RAM_ADDRESS; i <= &SCREEN_RAM_ADDRESS + 505; i++) {
        const ItemColor color = getColorForItem((ItemType)((uint8_t) *i));
        char* colorAdress = i + COLOR_RAM_OFFSET;
        *colorAdress = color;
    }
}

ItemColor getColorForItem(const ItemType item) {
    switch (item) {
        case diamondItem: 
            return diamondColor;

        case wallItem: 
            return wallColor;

        case rockItem: 
            return rockColor;

        case backgroundItem: 
            return backgroundColor;

        case emptyItem: 
            return emptyColor;

        case deadPlayerItem:
            return deadPlayerColor;

        case playerItem:
            return playerColor;

        default:
            return titleTextColor;
    }
}

/// @brief Load a file at a given RAM address.
///          The binary file must begin with two bytes wich will be discarded.
/// @param fileName the filename to load, on device #8
/// @param baseAddress the base RAM address where to load file
void loadFile(const char* fileName, char* baseAddress) {
    cbm_k_setnam(fileName);
    cbm_k_setlfs(fileNumber, driveNumber, sa_ignore_header);
    cbm_k_open();
    cbm_k_load(0, baseAddress);
    cbm_k_close(fileNumber);
}

void loadCharset(const char* fileName) {
    // Useless as we can access to ROM adress space for regular characters
    // copyCharRomToRam();
    loadFile(fileName, &USR_CHARSET_END_ADDRESS - (CHARSET_SIZE * 8) + 1);
}

void switchToCharset(const Charset charset) {
    CHARSET_CFG_ADDRESS = charset;
}

void loadLevel(const char* fileName) {
    loadFile(fileName, &SCREEN_RAM_ADDRESS);
    colorizeLevel();
}