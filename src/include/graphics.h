/**
 * Graphic utilities
 */

#include <cbm.h>
#include <stdint.h>
#include <vic20.h>
#include "addresses.h"

#define CHARSET_SIZE        (uint8_t)7

// Charset standard characters
#define STD_SPACE_CHAR      (uint8_t)128+32
#define STD_A_CHAR          (uint8_t)128+1
#define STD_B_CHAR          (uint8_t)128+2
#define STD_C_CHAR          (uint8_t)128+3
#define STD_D_CHAR          (uint8_t)128+4
#define STD_E_CHAR          (uint8_t)128+5
#define STD_F_CHAR          (uint8_t)128+6
#define STD_G_CHAR          (uint8_t)128+7
#define STD_H_CHAR          (uint8_t)128+8
#define STD_I_CHAR          (uint8_t)128+9
#define STD_J_CHAR          (uint8_t)128+10
#define STD_K_CHAR          (uint8_t)128+11
#define STD_L_CHAR          (uint8_t)128+12
#define STD_M_CHAR          (uint8_t)128+13
#define STD_N_CHAR          (uint8_t)128+14
#define STD_O_CHAR          (uint8_t)128+15
#define STD_P_CHAR          (uint8_t)128+16
#define STD_Q_CHAR          (uint8_t)128+17
#define STD_R_CHAR          (uint8_t)128+18
#define STD_S_CHAR          (uint8_t)128+19
#define STD_T_CHAR          (uint8_t)128+20
#define STD_U_CHAR          (uint8_t)128+21
#define STD_V_CHAR          (uint8_t)128+22
#define STD_W_CHAR          (uint8_t)128+23
#define STD_X_CHAR          (uint8_t)128+24
#define STD_Y_CHAR          (uint8_t)128+25
#define STD_Z_CHAR          (uint8_t)128+26
#define ZERO_CHAR           (uint8_t)128+48
#define ONE_CHAR            (uint8_t)128+49
#define TWO_CHAR            (uint8_t)128+50
#define THREE_CHAR          (uint8_t)128+51
#define FOUR_CHAR           (uint8_t)128+52
#define FIVE_CHAR           (uint8_t)128+53
#define SIX_CHAR            (uint8_t)128+54
#define SEVEN_CHAR          (uint8_t)128+55
#define EIGHT_CHAR          (uint8_t)128+56
#define NINE_CHAR           (uint8_t)128+57

// Charset new characters
#define DIAMOND_CHAR        (uint8_t)57
#define WALL_CHAR           (uint8_t)58
#define ROCK_CHAR           (uint8_t)59
#define BACKGROUND_CHAR     (uint8_t)60
#define EMPTY_CHAR          (uint8_t)61
#define DEAD_PLAYER_CHAR    (uint8_t)62
#define PLAYER_CHAR         (uint8_t)63

enum ItemType {
    diamondItem = DIAMOND_CHAR,
    wallItem = WALL_CHAR,
    rockItem = ROCK_CHAR,
    backgroundItem = BACKGROUND_CHAR,
    emptyItem = EMPTY_CHAR,
    deadPlayerItem = DEAD_PLAYER_CHAR,
    playerItem = PLAYER_CHAR
};

enum ItemColor {
    diamondColor = COLOR_CYAN,
    wallColor = COLOR_RED,
    rockColor = COLOR_WHITE,
    backgroundColor = COLOR_YELLOW,
    emptyColor = COLOR_BLACK,
    deadPlayerColor = COLOR_RED,
    playerColor = COLOR_GREEN,
    titleTextColor = COLOR_WHITE
};


enum Charset {
    upperCase = (uint8_t)240,
    upperCaseRvsd = (uint8_t)241,
    lowerCase = (uint8_t)242,
    lowerCaseRvsd = (uint8_t)243,
    userDefChar = (uint8_t)255
};

/// @brief Get the color for a given item
/// @param item the item
/// @return the corresponding color
ItemColor getColorForItem(const ItemType item);

/// @brief Load a user charset. The file is loaded at the end of the dedicated RAM location, replacing
///          the last characters, starting from character number 63 and going backward.
///          The binary file must begin with two bytes wich will be discarded.
/// @param fileName the filename of the charset, on device #8
void loadCharset(const char* fileName);

/// @brief switch to a given charset: upper / lower case (reversed or not) or user defined
/// @param charset the charset to use
void switchToCharset(const Charset charset);

/// @brief Load a level in screen RAM area.
///          The binary file must begin with two bytes wich will be discarded.
/// @param fileName the filename of the charset, on device #8
void loadLevel(const char* fileName);
