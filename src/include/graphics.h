/**
 * Graphic utilities
 */

#include <cbm.h>
#include <stdint.h>
#include <vic20.h>
#include "addresses.h"

#define CHARSET_SIZE        (uint8_t)17

// Charset standard characters
#define STD_A_CHAR          (uint8_t)1
#define STD_B_CHAR          (uint8_t)2
#define STD_C_CHAR          (uint8_t)3
#define STD_D_CHAR          (uint8_t)4
#define STD_E_CHAR          (uint8_t)5
#define STD_F_CHAR          (uint8_t)6
#define STD_G_CHAR          (uint8_t)7
#define STD_H_CHAR          (uint8_t)8
#define STD_I_CHAR          (uint8_t)9
#define STD_J_CHAR          (uint8_t)10
#define STD_K_CHAR          (uint8_t)11
#define STD_L_CHAR          (uint8_t)12
#define STD_M_CHAR          (uint8_t)13
#define STD_N_CHAR          (uint8_t)14
#define STD_O_CHAR          (uint8_t)15
#define STD_P_CHAR          (uint8_t)16
#define STD_Q_CHAR          (uint8_t)17
#define STD_R_CHAR          (uint8_t)18
#define STD_S_CHAR          (uint8_t)19
#define STD_T_CHAR          (uint8_t)20
#define STD_U_CHAR          (uint8_t)21
#define STD_V_CHAR          (uint8_t)22
#define STD_W_CHAR          (uint8_t)23
#define STD_X_CHAR          (uint8_t)24
#define STD_Y_CHAR          (uint8_t)25
#define STD_Z_CHAR          (uint8_t)26
#define STD_SPACE_CHAR      (uint8_t)32

// Charset new characters
#define ZERO_CHAR           (uint8_t)47
#define ONE_CHAR            (uint8_t)48
#define TWO_CHAR            (uint8_t)49
#define THREE_CHAR          (uint8_t)50
#define FOUR_CHAR           (uint8_t)51
#define FIVE_CHAR           (uint8_t)52
#define SIX_CHAR            (uint8_t)53
#define SEVEN_CHAR          (uint8_t)54
#define EIGHT_CHAR          (uint8_t)55
#define NINE_CHAR           (uint8_t)56
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
    playerColor = COLOR_GREEN
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
