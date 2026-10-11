#include "common.h"

u8 __osContAddressCrc(u32 addr) {
    u32 temp = 0;
    u32 temp2 = addr;
    u32 crc = 0;
    s32 i;
    u32 xorVal;

    for (i = 0; i < 16; i++) {
        xorVal = (temp & 0x10) ? 0x15 : 0;
        temp <<= 1;
        crc = ((temp & 0xFF) | ((temp2 >> 10) & 1)) ^ xorVal;
        temp2 <<= 1;
        temp = crc;
    }

    return crc & 0x1F;
}
