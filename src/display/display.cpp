#include "display.h"

char getTextCodeFromChar(const char lowerChar) {
    if (lowerChar >= 'a' && lowerChar <= 'z')
        return (char)(STD_A_CHAR + (lowerChar - 'a'));
    if (lowerChar >= '0' && lowerChar <= '9')
        return (char)(ZERO_CHAR + (lowerChar - '0'));
    return STD_SPACE_CHAR;
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

void integerToString(uint8_t number, char *string) {
    char *p = string;

    // --- Hundreds (100-200) ---
    // Only process if the number is large enough.
    // This keeps the code fast for small numbers.
    if (number >= 100) {
        char digit = '0';
        do {
            number -= 100;
            digit++;
        } while (number >= 100);
        *p++ = digit;
    }

    // --- Tens (10-90) ---
    // Output a digit if the number is >= 10, OR if we have already
    // written a hundreds digit (e.g., for 105, we must write the '0').
    // Checking (p != string) is efficient (pointer comparison).
    if (number >= 10 || p != string) {
        char digit = '0';
        while (number >= 10) {
            number -= 10;
            digit++;
        }
        *p++ = digit;
    }

    // --- Units (0-9) ---
    // Whatever remains in 'number' is less than 10.
    *p++ = number + '0';
    
    // Null terminator
    *p = 0;
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