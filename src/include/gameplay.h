/**
 * Gameplay utilities
 */

#include "display.h"
#include "keyboard.h"
#include "sound.h"

#define MAX_LEVEL 2


/// @brief Display a given item at a given position
/// @param item the item to display
/// @param line the line where to display the item
/// @param row the row where to display the item
void setItemPosition(const ItemType item, const uint8_t line, const uint8_t row);

/// @brief Compute player position after key pressed
/// @param keyCode the keycode of the pressed key
/// @param line the current player line
/// @param row the current player row
void computeNewPlayerPosition(const int keyCode, uint8_t& line, uint8_t& row);


/// @brief Check if the player is able to move to the given position, and update score if needed
/// @param currentLine the destination line
/// @param currentRow the destination row
/// @param updateScore does the score needs to be updated
/// @return true if the player can move, false otherwise
bool validateMove(const uint8_t currentLine, const uint8_t currentRow, bool &updateScore);

/// @brief Apply gravity from above a given position, and tell if it killed the player
/// @param currentLine the line to test
/// @param currentRow the row to test
/// @return true if the player is killed, false otherwise
bool applyGravityFromPositionAndKillPlayer(const uint8_t currentLine, const uint8_t currentRow);

/// @brief Get the position of the player
/// @param line the line of the item
/// @param row the row of the item
void getPlayerPosition(uint8_t &line, uint8_t &row);

/// @brief Count the number of diamonds
/// @param line the line of the item
/// @param row the row of the item
uint8_t countDiamonds();

/// @brief Display header (score + level)
void displayHeader(const uint8_t diamondCount, const uint8_t level);
