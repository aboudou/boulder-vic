/**
 * Display utilities
 */
#include <stdint.h>
#include <string.h>
#include "addresses.h"
#include "graphics.h"

#define MIN_HORI_POSITION   (uint8_t)1
#define MIN_VERT_POSITION   (uint8_t)2
#define MAX_HORI_POSITION   (uint8_t)22
#define MAX_VERT_POSITION   (uint8_t)23

/// @brief Set border and screen color
/// @param borderColor the border color
/// @param screenColor the screen color
void setScreenColors(const uint8_t borderColor, const uint8_t screenColor);

/// @brief Display a character at a given position
/// @param line the line of the character
/// @param row the row of the character
/// @param character the character code
/// @param color the color of the character
void setCharacterAtPosition(const uint8_t line, const uint8_t row, const char character, const char color);

/// @brief Get character code at a given position
/// @param line the line of the character
/// @param row the row of the character
/// @return the character code
int getCharacterAtPosition(const uint8_t line, const uint8_t row);

/// @brief Fill the screen with given char and color
/// @param character the character code
/// @param color the color of the character
void fillScreenWith(const char character, const char color);

/// @brief Display a string at a given position
/// @param line the line of the string
/// @param row the starting row of the string
/// @param text the string to display
/// @param color the color of the text
void setStringAtPosition(const uint8_t line, uint8_t row, const char text[], const char color);

/// @brief Convert a 16bit integer (max value = 65535) to string
/// @param number the number to convert
/// @return the result string
void integerToString(const uint16_t number, char *string);

/// @brief Display a 16bit integer (max value = 65535) at a given position
/// @param line the line of the number
/// @param row the starting row of the number
/// @param number the number to display
/// @param color the color of the text
void setIntegerAtPosition(const uint8_t line, const uint8_t row, uint16_t number, const char color);

/// @brief Get the position of a given item
/// @param line the line of the item
/// @param row the row of the item
/// @param item the item
void getItemPosition(uint8_t &line, uint8_t &row, const ItemType item);

/// @brief Get the number of a given item
/// @param item the item
int countItem(const ItemType item);
