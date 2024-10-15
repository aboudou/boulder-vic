#include "sound.h"
#include "utils.h"
#include "display.h"

void generateSound(const SfxChannels channels[], const uint8_t &channelsCount) {
    for (uint8_t channel = 0; channel < channelsCount; channel++) {
        SND_VOLUME_ADDRESS = SND_VOLUME;

        // Base sound
        SND_ALTO_CHANNEL_ADDRESS = channels[channel].sfxAltoFreq;
        SND_TENOR_CHANNEL_ADDRESS = channels[channel].sfxTenorFreq;  
        SND_SOPRANO_CHANNEL_ADDRESS = channels[channel].sfxSopranoFreq;
        SND_NOISE_CHANNEL_ADDRESS = channels[channel].sfxNoiseFreq;
        pause(channels[channel].sfxDuration);

        if (!channels[channel].hardCut) {
            // Lower volume
            for (int i = 10; i >= 0; i = i - 2) {
                SND_VOLUME_ADDRESS = i;
                pause(0.02);
            }
        }

        // Cut sound
        SND_ALTO_CHANNEL_ADDRESS = 0;
        SND_TENOR_CHANNEL_ADDRESS = 0;  
        SND_SOPRANO_CHANNEL_ADDRESS = 0;
        SND_NOISE_CHANNEL_ADDRESS = 0;
    }
}

void playSound(const SfxType type) {
    SfxChannels channels[3];
    uint8_t channelsCount = 0;
    switch (type) {
        case sfxPlayerWalk:
            channels[0] = { 128, 0, 0, 128, 0.1, true };
            channelsCount = 1;
            break;

        case sfxPlayerDiamond:
            channels[0] = { 0, 0, 220, 0, 0.1, false };
            channelsCount = 1;
            break;

        case sfxPlayerWon:
            channels[0] = { 0, 200, 0, 0, 0.2, true };
            channels[1] = { 0, 0, 200, 0, 0.2, true };
            channels[2] = { 0, 0, 225, 0, 0.2, false };
            channelsCount = 3;
            break;

        case sfxPlayerLose:
            channels[0] = { 128, 0, 0, 128, 0.5, false };
            channelsCount = 1;
            break;
    }

    generateSound(channels, channelsCount);
}