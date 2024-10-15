#include "display.h"

char getTextCodeFromChar(const char lowerChar) {
    switch (lowerChar) {
        case 'a':
            return STD_A_CHAR;
        case 'b':
            return STD_B_CHAR;
        case 'c':
            return STD_C_CHAR;
        case 'd':
            return STD_D_CHAR;
        case 'e':
            return STD_E_CHAR;
        case 'f':
            return STD_F_CHAR;
        case 'g':
            return STD_G_CHAR;
        case 'h':
            return STD_H_CHAR;
        case 'i':
            return STD_I_CHAR;
        case 'j':
            return STD_J_CHAR;
        case 'k':
            return STD_K_CHAR;
        case 'l':
            return STD_L_CHAR;
        case 'm':
            return STD_M_CHAR;
        case 'n':
            return STD_N_CHAR;
        case 'o':
            return STD_O_CHAR;
        case 'p':
            return STD_P_CHAR;
        case 'q':
            return STD_Q_CHAR;
        case 'r':
            return STD_R_CHAR;
        case 's':
            return STD_S_CHAR;
        case 't':
            return STD_T_CHAR;
        case 'u':
            return STD_U_CHAR;
        case 'v':
            return STD_V_CHAR;
        case 'w':
            return STD_W_CHAR;
        case 'x':
            return STD_X_CHAR;
        case 'y':
            return STD_Y_CHAR;
        case 'z':
            return STD_Z_CHAR;
        case '0':
            return ZERO_CHAR;
        case '1':
            return ONE_CHAR;
        case '2':
            return TWO_CHAR;
        case '3':
            return THREE_CHAR;
        case '4':
            return FOUR_CHAR;
        case '5':
            return FIVE_CHAR;
        case '6':
            return SIX_CHAR;
        case '7':
            return SEVEN_CHAR;
        case '8':
            return EIGHT_CHAR;
        case '9':
            return NINE_CHAR;
        default:
            return STD_SPACE_CHAR;
    }
}

void setScreenColors(const uint8_t borderColor, const uint8_t screenColor) {
    SCREEN_COLOR_ADDRESS = (SCREEN_COLOR_ADDRESS & 248) | borderColor;
    SCREEN_COLOR_ADDRESS = (SCREEN_COLOR_ADDRESS & 15) | (screenColor * 16);
}

void setCharacterAtPosition(const uint8_t line, const uint8_t row, const char character, const char color) {
    char* positionAddress = &SCREEN_RAM_ADDRESS + (row - 1) + (22 * (line - 1));
    *positionAddress = character;
    char* colorAdress = positionAddress + COLOR_RAM_OFFSET;
    *colorAdress = color;
}

uint8_t getCharacterAtPosition(const uint8_t line, const uint8_t row) {
    return *(&SCREEN_RAM_ADDRESS + (row - 1) + (22 * (line - 1)));
}

void fillScreenWith(const char character, const char color) {
    for (char* i = &SCREEN_RAM_ADDRESS; i <= &SCREEN_RAM_ADDRESS + 505; i++) {
        *i = character;
        char* colorAdress = i + COLOR_RAM_OFFSET;
        *colorAdress = color;
    }
}

void setStringAtPosition(const uint8_t line, const uint8_t row, const char text[], const char color) {
    uint8_t length = 0;
    for(uint8_t i = 0; text[i]!='\0'; i++) {
        length++;
    }

    for (uint8_t i = 0; i < length; i++) {
        setCharacterAtPosition(line, row + i, getTextCodeFromChar(text[i]), color);
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
    char string[4] = "";
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