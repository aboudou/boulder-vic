/**
 * Memory adresses
 */

#define SCREEN_RAM_ADDRESS          *(char*)0x1E00
#define SCREEN_COLOR_ADDRESS        *(char*)0x900F

#define COLOR_RAM_ADDRESS           *(char*)0x9600
#define COLOR_RAM_OFFSET            (unsigned int)(&COLOR_RAM_ADDRESS - &SCREEN_RAM_ADDRESS)

#define CHARSET_OFFSET              0 // 0 for upper case charset; 2048 for offset for lower case charset
#define CHAR_ROM_ADDRESS            *(char*)(0x8000 + CHARSET_OFFSET)
#define CHARSET_CFG_ADDRESS         *(char*)0x9005

#define USR_CHARSET_MAX_NB_OF_CHARS 64
#define USR_CHARSET_START_ADDRESS   *(char*)0x1C00
#define USR_CHARSET_END_ADDRESS     *(char*)(&USR_CHARSET_START_ADDRESS + (USR_CHARSET_MAX_NB_OF_CHARS * 8 - 1))

#define KB_BUF_1_ADDRESS            *(char*)0x0277
#define KB_BUF_SIZE_ADDRESS         *(char*)0x00C6

#define SND_ALTO_CHANNEL_ADDRESS    *(char*)0x900A
#define SND_TENOR_CHANNEL_ADDRESS   *(char*)0x900B
#define SND_SOPRANO_CHANNEL_ADDRESS *(char*)0x900C
#define SND_NOISE_CHANNEL_ADDRESS   *(char*)0x900D
#define SND_VOLUME_ADDRESS          *(char*)0x900E

#define CLOCK_ADDRESS               *(char*)0x00A2
