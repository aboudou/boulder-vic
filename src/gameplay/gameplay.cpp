#include "gameplay.h"

void setItemPosition(const ItemType item, const uint8_t line, const uint8_t row) {
    setCharacterAtPosition(line, row, item, getColorForItem(item));
}

void computeNewPlayerPosition(const int keyCode, uint8_t& line, uint8_t& row) {
    // Compute new positions+
    if (keyCode == KEY_UP) {
        line--;
    } else if (keyCode == KEY_DOWN) {
        line++;
    } else if (keyCode == KEY_LEFT) {
        row--;
    } else if (keyCode == KEY_RIGHT) {
        row++;
    }

    // Fix potential out of screen bounds
    if (row < MIN_HORI_POSITION) { row = MIN_HORI_POSITION; }
    if (row > MAX_HORI_POSITION) { row = MAX_HORI_POSITION; }
    if (line < MIN_VERT_POSITION) { line = MIN_VERT_POSITION; }
    if (line > MAX_VERT_POSITION) { line = MAX_VERT_POSITION; }
}

bool validateMove(const uint8_t currentLine, const uint8_t currentRow, bool &updateScore) {
    uint8_t charCode = getCharacterAtPosition(currentLine, currentRow);

    if (charCode == ROCK_CHAR || charCode == WALL_CHAR) {
        return false;
    } else if (charCode == DIAMOND_CHAR) {
        updateScore = true;
        return true;
    } else {
        updateScore = false;
        return true;
    }
}

bool applyGravityFromPositionAndKillPlayer(const uint8_t currentLine, const uint8_t currentRow) {
    if (getCharacterAtPosition(currentLine, currentRow) == EMPTY_CHAR) {
        // Check if character above this position is a rock or a diamond
        if (currentLine > MIN_VERT_POSITION) {
            const uint8_t aboveLine = currentLine - 1;
            const uint8_t movingChar = getCharacterAtPosition(aboveLine, currentRow);
            if (movingChar == DIAMOND_CHAR || movingChar == ROCK_CHAR) {
                uint8_t belowLine = currentLine;
                uint8_t belowChar = getCharacterAtPosition(belowLine, currentRow);
                bool fallenItem = false;
                while (belowLine <= MAX_VERT_POSITION && belowChar == EMPTY_CHAR) {
                    setItemPosition(emptyItem, belowLine - 1, currentRow);
                    setItemPosition((ItemType)movingChar, belowLine, currentRow);

                    belowLine++;
                    belowChar = getCharacterAtPosition(belowLine, currentRow);
                    fallenItem = true;
                }

                // Check if player is below a fallenItem
                if (fallenItem) {
                    if (belowChar == PLAYER_CHAR) {
                        return true;
                    }
                }

                // Recursively apply gravity to above items
                applyGravityFromPositionAndKillPlayer(aboveLine, currentRow);
            }
        }
    }

    return false;
}

void getPlayerPosition(uint8_t &line, uint8_t &row) {
    getItemPosition(line, row, playerItem);
}

uint8_t countDiamonds() {
    return countItem(diamondItem);
}

void displayHeader(const uint8_t diamondCount, const uint8_t level) {
    // One black line
    for (uint8_t i = MIN_HORI_POSITION; i <= MAX_HORI_POSITION; i++) {
        setCharacterAtPosition(1, i, EMPTY_CHAR, COLOR_BLACK);
    }

    setCharacterAtPosition(1, 2, diamondItem, diamondColor);
    setIntegerAtPosition(1, 4, diamondCount, COLOR_WHITE);

    setStringAtPosition(1, 14, "level", COLOR_WHITE);
    setIntegerAtPosition(1, 20, level, COLOR_WHITE);
}