#include <stdio.h>
#include "gameplay.h"
#include "utils.h"

void displayAllCharacters() {
    uint8_t line = 1;
    uint8_t row = 1;
    for (uint8_t charIndex = 0; charIndex < USR_CHARSET_MAX_NB_OF_CHARS; charIndex++) {
        setCharacterAtPosition(line, row, charIndex, COLOR_GREEN);
        row++;
        if (row > 22) {
            row = 1;
            line++;
        }
    }
}

void loadLevel(uint8_t &line, uint8_t &row, uint8_t &diamondCount, uint8_t &currentLevel, bool &displayTitleScreen) {
    if (currentLevel > MAX_LEVEL) {
        currentLevel = 1;
        displayTitleScreen = true;
        return;
    }

    char levelName[] = "level_";
    char levelNumber[6] = "";
    integerToString(currentLevel, levelNumber);
    strcat(levelName, levelNumber);
    strcat(levelName, ".bin");
    loadLevel(levelName);

    diamondCount = countDiamonds();
    getPlayerPosition(line, row);
    displayHeader(diamondCount, currentLevel);
}

int main(void) {
    // Initial display setup
    setScreenColors(COLOR_BLACK, COLOR_BLACK);
    loadCharset((const char*)"charset.bin");
    switchToCharset(userDefChar);

    // displayAllCharacters();
    // return 0;

    // for (uint8_t i = 0; i <= 60; i++) {
    //     setIntegerAtPosition(10,1,i,COLOR_BLUE);
    //     pause(1.0);
    // }

    uint8_t currentLevel = 1;
    uint8_t currentLine = 1;
    uint8_t currentRow = 1;
    uint8_t diamondCount = 0;

    bool displayTitleScreen = true;
    bool playerKilled = false;
    bool playerWon = false;

    // Gameloop
    for (;;) {
        int keyPressed = getKeyPressed();

        if (displayTitleScreen) {
            fillScreenWith(emptyItem, emptyColor);

            loadLevel((const char*)"title.bin");

            setStringAtPosition(5, 6, "boulder  vic", COLOR_CYAN);
            setStringAtPosition(5, 6, "boulder  vic", COLOR_CYAN);

            setStringAtPosition(10, 3, "use arrows to move", COLOR_CYAN);
            setStringAtPosition(11, 3, "press r to restart", COLOR_CYAN);
            setStringAtPosition(12, 4, "get the diamonds", COLOR_CYAN);
            setStringAtPosition(13, 3, "do not get crushed", COLOR_CYAN);

            setStringAtPosition(18, 5, "press space to", COLOR_CYAN);
            setStringAtPosition(19, 9, "begin", COLOR_CYAN);

            for (;;) {
                keyPressed = getKeyPressed();

                if (keyPressed == KEY_SPACE) { 
                    displayTitleScreen = false;
                    loadLevel(currentLine, currentRow, diamondCount, currentLevel, displayTitleScreen);
                    break;
                }
            }
        } else {
            bool scoreUpdated = false;
            if ((keyPressed == KEY_SPACE && playerKilled) || keyPressed == KEY_R) {
                loadLevel(currentLine, currentRow, diamondCount, currentLevel, displayTitleScreen);
                playerKilled = false;
            }
            if (keyPressed == KEY_SPACE && playerWon) {
                currentLevel++;
                loadLevel(currentLine, currentRow, diamondCount, currentLevel, displayTitleScreen);
                playerWon = false;
            }
            if (keyPressed != 0 && !playerKilled) {
                const uint8_t previousLine = currentLine;
                const uint8_t previousRow = currentRow;

                computeNewPlayerPosition(keyPressed, currentLine, currentRow);

                bool updateScore = false;
                const bool validate = validateMove(currentLine, currentRow, updateScore);
                if (updateScore) {
                    diamondCount--;
                    scoreUpdated = true;
                }

                if (validate && (currentLine != previousLine || currentRow != previousRow)) {
                    // Update character position
                    setItemPosition(emptyItem, previousLine, previousRow);
                    setItemPosition(playerItem, currentLine, currentRow);
                    if (updateScore) {
                        playSound(sfxPlayerDiamond);
                    } else {
                        playSound(sfxPlayerWalk);
                    }

                    // Gravity for rocks and diamonds
                    playerKilled = applyGravityFromPositionAndKillPlayer(previousLine, previousRow);

                    if (playerKilled) {
                        setItemPosition(deadPlayerItem, currentLine, currentRow);

                        playSound(sfxPlayerLose);

                        setStringAtPosition(1, 1, "      game over       ", COLOR_RED);
                        setStringAtPosition(2, 1, " press space to retry ", COLOR_RED);

                    }
                } else {
                    // Reset current position
                    currentLine = previousLine;
                    currentRow = previousRow;
                }
            }

            // Display header
            if (scoreUpdated && !playerKilled) {
                if (diamondCount != 0) {
                    displayHeader(diamondCount, currentLevel);
                } else {
                        playerWon = true;
                        setStringAtPosition(1, 1, "        success       ", COLOR_GREEN);
                        setStringAtPosition(2, 1, " press space for next ", COLOR_GREEN);
                        setStringAtPosition(3, 1, "         level        ", COLOR_GREEN);
                        playSound(sfxPlayerWon);
                }
            }
        }
    }

    return 0;
}
