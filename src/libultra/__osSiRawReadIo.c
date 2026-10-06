#include "common.h"

/* The ROM keeps one stray linker-padding byte (E0) after the file-name string. */
extern const char SIRAWREAD_FILE[16];

s32 __osSiRawReadIo(u32 devAddr, u32 *data) {
    if (devAddr & 3) {
        __assert("EX", SIRAWREAD_FILE, 51);
    }
    if (data == NULL) {
        __assert("EX", SIRAWREAD_FILE, 52);
    }

    if (__osSiDeviceBusy()) {
        return -1;
    }

    *data = HW_REG(devAddr, u32);
    return 0;
}

const char SIRAWREAD_FILE[16] = "io/sirawread.c\0\340";
