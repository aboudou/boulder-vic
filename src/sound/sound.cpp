#include "sound.h"


void generateSound(const SfxChannels channels) {
    CLOCK_ADDRESS = 0;
    SND_VOLUME_ADDRESS = SND_VOLUME;
    int currentTime = CLOCK_ADDRESS;

    // Base sound
    while (currentTime < channels.sfxDuration) {
        currentTime = CLOCK_ADDRESS;
        SND_ALTO_CHANNEL_ADDRESS = channels.sfxAltoFreq;
        SND_TENOR_CHANNEL_ADDRESS = channels.sfxTenorFreq;  
        SND_SOPRANO_CHANNEL_ADDRESS = channels.sfxSopranoFreq;
        SND_NOISE_CHANNEL_ADDRESS = channels.sfxNoiseFreq;
    }

    if (!channels.hardCut) {
        // Lower volume
        for (int i = 10; i >= 0; i--) {
            CLOCK_ADDRESS = 0;
            currentTime = CLOCK_ADDRESS;
            while (currentTime < 1) {
                currentTime = CLOCK_ADDRESS;
                SND_VOLUME_ADDRESS = i;
            }
        }
    }

    // Cut sound
    SND_ALTO_CHANNEL_ADDRESS = 0;
    SND_TENOR_CHANNEL_ADDRESS = 0;  
    SND_SOPRANO_CHANNEL_ADDRESS = 0;
    SND_NOISE_CHANNEL_ADDRESS = 0;
}

void playSound(const SfxType type) {
    SfxChannels channels;
    switch (type) {
        case sfxPlayerWalk:
            channels = { 128, 0, 0, 128, 3, true };
            generateSound(channels);
            break;

        case sfxPlayerDiamond:
            channels = { 0, 0, 220, 0, 1, false };
            generateSound(channels);
            break;

        case sfxPlayerWon:
            channels = { 0, 0, 0, 0, 3, true };
            generateSound(channels);
            channels = { 0, 200, 0, 0, 10, true };
            generateSound(channels);
            channels = { 0, 0, 0, 0, 3, true };
            generateSound(channels);
            channels = { 0, 0, 200, 0, 10, true };
            generateSound(channels);
            channels = { 0, 0, 0, 0, 3, true };
            generateSound(channels);
            channels = { 0, 0, 225, 0, 10, false };
            generateSound(channels);
            break;

        case sfxPlayerLose:
            channels = { 128, 0, 0, 128, 10, false };
            generateSound(channels);
            break;
    }
}