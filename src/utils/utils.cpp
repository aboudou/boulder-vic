#include "utils.h"
#include "display.h"

/// @brief get number of jiffies (60 jiffies per seconds) elapsed since VIC-20 startup
/// @return the number of jiffies
uint32_t getClock() {
    return uint32_t(CLOCK_1_ADDRESS)*65536 + uint32_t(CLOCK_2_ADDRESS)*256 + uint32_t(CLOCK_3_ADDRESS);
}

void pause(const float seconds) {
    //return ;
    const float jiffyFreq = 60.0f;
    const float jiffiesToAdd = seconds * jiffyFreq;
    volatile uint8_t toto = CLOCK_3_ADDRESS;
    const uint32_t endJiffy = getClock() + uint32_t(jiffiesToAdd);
    while (getClock() < endJiffy) {
        // Fake operation to bypass compiler optimizations
        //setCharacterAtPosition(1, 1, '\0', COLOR_BLACK);
        toto = CLOCK_3_ADDRESS;
        //asm volatile ("");
    }
//    CLOCK_3_ADDRESS = toto;
}
