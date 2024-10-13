#include "display.h"

#include <ctype.h>

// #define CLRSCR \
//     __asm__("LDA #$93"); \
//     __asm__("JSR $E55F");


char getTextCodeFromChar(const char character) {
    const char lowerChar = tolower(character);
    if (lowerChar == 'a') { 
        return STD_A_CHAR;
    } else if (lowerChar == 'b') {
        return STD_B_CHAR;
    } else if (lowerChar == 'c') {
        return STD_C_CHAR;
    } else if (lowerChar == 'd') {
        return STD_D_CHAR;
    } else if (lowerChar == 'e') {
        return STD_E_CHAR;
    } else if (lowerChar == 'f') {
        return STD_F_CHAR;
    } else if (lowerChar == 'g') {
        return STD_G_CHAR;
    } else if (lowerChar == 'h') {
        return STD_H_CHAR;
    } else if (lowerChar == 'i') {
        return STD_I_CHAR;
    } else if (lowerChar == 'j') {
        return STD_J_CHAR;
    } else if (lowerChar == 'k') {
        return STD_K_CHAR;
    } else if (lowerChar == 'l') {
        return STD_L_CHAR;
    } else if (lowerChar == 'm') {
        return STD_M_CHAR;
    } else if (lowerChar == 'n') {
        return STD_N_CHAR;
    } else if (lowerChar == 'o') {
        return STD_O_CHAR;
    } else if (lowerChar == 'p') {
        return STD_P_CHAR;
    } else if (lowerChar == 'q') {
        return STD_Q_CHAR;
    } else if (lowerChar == 'r') {
        return STD_R_CHAR;
    } else if (lowerChar == 's') {
        return STD_S_CHAR;
    } else if (lowerChar == 't') {
        return STD_T_CHAR;
    } else if (lowerChar == 'u') {
        return STD_U_CHAR;
    } else if (lowerChar == 'v') {
        return STD_V_CHAR;
    } else if (lowerChar == 'w') {
        return STD_W_CHAR;
    } else if (lowerChar == 'x') {
        return STD_X_CHAR;
    } else if (lowerChar == 'y') {
        return STD_Y_CHAR;
    } else if (lowerChar == 'z') {
        return STD_Z_CHAR;
    } else if (lowerChar == '0') {
        return ZERO_CHAR;
    } else if (lowerChar == '1') {
        return ONE_CHAR;
    } else if (lowerChar == '2') {
        return TWO_CHAR;
    } else if (lowerChar == '3') {
        return THREE_CHAR;
    } else if (lowerChar == '4') {
        return FOUR_CHAR;
    } else if (lowerChar == '5') {
        return FIVE_CHAR;
    } else if (lowerChar == '6') {
        return SIX_CHAR;
    } else if (lowerChar == '7') {
        return SEVEN_CHAR;
    } else if (lowerChar == '8') {
        return EIGHT_CHAR;
    } else if (lowerChar == '9') {
        return NINE_CHAR;
    }

    return STD_SPACE_CHAR;
}

void setScreenColors(const uint8_t borderColor, const uint8_t screenColor) {
    uint8_t colors = SCREEN_COLOR_ADDRESS;
    colors = (colors & 248) | borderColor;
    colors = (colors & 15) | (screenColor * 16);
    SCREEN_COLOR_ADDRESS = colors;
}

void setCharacterAtPosition(const uint8_t line, const uint8_t row, const char character, const char color) {
    char* positionAddress = &SCREEN_RAM_ADDRESS + (row - 1) + (22 * (line - 1));
    *positionAddress = character;
    char* colorAdress = positionAddress + COLOR_RAM_OFFSET;
    *colorAdress = color;
}

uint8_t getCharacterAtPosition(const uint8_t line, const uint8_t row) {
    char* positionAddress = &SCREEN_RAM_ADDRESS + (row - 1) + (22 * (line - 1));
    return *positionAddress;
}

void fillScreenWith(const char character, const char color) {
    for (char* i = &SCREEN_RAM_ADDRESS; i <= &SCREEN_RAM_ADDRESS + 505; i++) {
        *i = character;
        char* colorAdress = i + COLOR_RAM_OFFSET;
        *colorAdress = color;
    }
}

void setStringAtPosition(const uint8_t line, const uint8_t row, const char text[], const char color) {
    uint8_t currentRow = row;
    for (uint8_t i = 0; i < strlen(text); i++) {
        setCharacterAtPosition(line, currentRow, getTextCodeFromChar(text[i]), color);
        currentRow++;
    }
}

void integerToString(const uint8_t number, char *string) {
    uint8_t numberToConvert = number;
    if (numberToConvert > 255) { return; }

    uint8_t i = 0;
    if (numberToConvert >= 100) {
        uint8_t extract = numberToConvert / 100;
        string[i] = extract + '0';
        i++;
        numberToConvert = numberToConvert - (extract * 100);
    }
    if (numberToConvert >= 10) {
        uint8_t extract = numberToConvert / 10;
        string[i] = extract + '0';
        i++;
        numberToConvert = numberToConvert - (extract * 10);
    }
    if (numberToConvert >= 0) {
        string[i] = numberToConvert + '0';
        i++;
    }
}

void setIntegerAtPosition(const uint8_t line, const uint8_t row, const uint8_t number, const char color) {
    char string[6] = "";
    integerToString(number, string);

    setStringAtPosition(line, row, string, color);
}

void getItemPosition(uint8_t &line, uint8_t &row, const ItemType item) {
    for (uint8_t i = MIN_VERT_POSITION; i <= MAX_VERT_POSITION; i++) {
        for (uint8_t j = MIN_VERT_POSITION; j <= MAX_VERT_POSITION; j++) {
            if (getCharacterAtPosition(j, i) == item) {
                line = j;
                row = i;
                return;
            }
        }
    }
}

uint8_t countItem(const ItemType item) {
    uint8_t count = 0;
    for (uint8_t i = MIN_VERT_POSITION; i <= MAX_VERT_POSITION; i++) {
        for (uint8_t j = MIN_VERT_POSITION; j <= MAX_VERT_POSITION; j++) {
            if (getCharacterAtPosition(j, i) == item) {
                count++;
            }
        }
    }

    return count;
}