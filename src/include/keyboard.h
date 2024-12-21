/**
 * Keyboard utilities
 */
#include "addresses.h"

#define KEY_UP      (int)68     // D key
#define KEY_DOWN    (int)67     // C key
#define KEY_LEFT    (int)88     // X key
#define KEY_RIGHT   (int)86     // V key

#define KEY_SPACE   (int)32
#define KEY_R       (int)82

/// @brief get keycode from pressed key
/// @return the keycode
int getKeyPressed();