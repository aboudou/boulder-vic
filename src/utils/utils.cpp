#include "utils.h"

/// @brief get number of jiffies (60 jiffies per seconds) elapsed since VIC-20 startup
/// @return the number of jiffies
uint32_t getClock() {
    return uint32_t(CLOCK_1_ADDRESS)*65536 + uint32_t(CLOCK_2_ADDRESS)*256 + uint32_t(CLOCK_3_ADDRESS);
}

void pause(uint16_t jiffies) {
    uint32_t endJiffy = getClock() + jiffies;
    while (getClock() < endJiffy) {
        __asm__("nop");
    }
}
