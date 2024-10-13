#include "addresses.h"

#include <stdint.h>

#define SND_VOLUME 10

struct SfxChannels {
    uint8_t sfxAltoFreq;    // Bass-ish
    uint8_t sfxTenorFreq;   // Medium-ish
    uint8_t sfxSopranoFreq; // Treble-ish
    uint8_t sfxNoiseFreq;   
    float sfxDuration;      // In seconds
    bool hardCut;           // cut sound after duration or progressively lower volume
};

enum SfxType {
    sfxPlayerWalk,
    sfxPlayerDiamond,
    sfxPlayerLose,
    sfxPlayerWon 
};


/// @brief Play a sound
/// @param type the sound to play
void playSound(const SfxType type);