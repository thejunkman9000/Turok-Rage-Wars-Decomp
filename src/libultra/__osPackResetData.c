#include "common.h"

void __osPackResetData(void) {
    u8 *ptr;
    s32 i;

    ptr = (u8 *)__osContPifRam.ramarray;
    __osContPifRam.pifstatus = 1;

    for (i = 0; i < 4; i++) {
        *ptr++ = 0xFD;
    }

    *ptr = 0xFE;
}
