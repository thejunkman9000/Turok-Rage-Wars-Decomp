#include "libaudio.h"

void alCopy(u8 *src, u8 *dst, s32 len) {
    s32 i;
    for (i = 0; i < len; i++) {
        *dst++ = *src++;
    }
}
