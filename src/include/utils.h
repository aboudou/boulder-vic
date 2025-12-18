#include <stdint.h>
#include "addresses.h"

/// @brief pause code execution for a given number of jiffies (1/60 second)
/// @param jiffies the duration of the pause 
void pause(const uint16_t jiffies);