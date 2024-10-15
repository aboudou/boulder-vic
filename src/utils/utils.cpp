#include "utils.h"

/// @brief get number of jiffies (60 jiffies per seconds) elapsed since VIC-20 startup
/// @return the number of jiffies
uint32_t getClock() {
    return uint32_t(CLOCK_1_ADDRESS)*65536 + uint32_t(CLOCK_2_ADDRESS)*256 + uint32_t(CLOCK_3_ADDRESS);
}

void pause(const float seconds) {
    const float jiffyFreq = 60.0f;
    const float jiffiesToAdd = seconds * jiffyFreq;
    const uint32_t endJiffy = getClock() + uint32_t(jiffiesToAdd);
    volatile uint8_t dummyVar = 0;
    while (getClock() < endJiffy) {
        // Updating a volatile var bypass compiler optimization disabling the loop
        dummyVar += 1; 
    }
}
