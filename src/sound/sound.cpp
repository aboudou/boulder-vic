#include "sound.h"
#include "utils.h"

void generateSound(const SfxChannels channels) {
    SND_VOLUME_ADDRESS = SND_VOLUME;

    // Base sound
    SND_ALTO_CHANNEL_ADDRESS = channels.sfxAltoFreq;
    SND_TENOR_CHANNEL_ADDRESS = channels.sfxTenorFreq;  
    SND_SOPRANO_CHANNEL_ADDRESS = channels.sfxSopranoFreq;
    SND_NOISE_CHANNEL_ADDRESS = channels.sfxNoiseFreq;
    pause(channels.sfxDuration);

    if (!channels.hardCut) {
        // Lower volume
        for (uint8_t i = 10; i >= 0; i--) {
            SND_VOLUME_ADDRESS = i;
            pause(0.1);
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
            channels = { 128, 0, 0, 128, 0.5, true };
            generateSound(channels);
            break;

        case sfxPlayerDiamond:
            channels = { 0, 0, 220, 0, 0.5, false };
            generateSound(channels);
            break;

        case sfxPlayerWon:
            channels = { 0, 0, 0, 0, 0.5, true };
            generateSound(channels);
            channels = { 0, 200, 0, 0, 1.0, true };
            generateSound(channels);
            channels = { 0, 0, 0, 0, 0.5, true };
            generateSound(channels);
            channels = { 0, 0, 200, 0, 1.0, true };
            generateSound(channels);
            channels = { 0, 0, 0, 0, 0.5, true };
            generateSound(channels);
            channels = { 0, 0, 225, 0, 1.0, false };
            generateSound(channels);
            break;

        case sfxPlayerLose:
            channels = { 128, 0, 0, 128, 1.0, false };
            generateSound(channels);
            break;
    }
}