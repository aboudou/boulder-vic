#include "keyboard.h"

int getKeyPressed() {
    const int kbBuffer1 = KB_BUF_1_ADDRESS;

    if (kbBuffer1 != 0) {
        KB_BUF_1_ADDRESS = 0;
        KB_BUF_SIZE_ADDRESS = 0;
        return kbBuffer1;
    } else {
        return 0;
    }
}