#include "common.h"

#ifdef NON_MATCHING
u8 __osContDataCrc(u8 *data) {
    s32 i;
    s32 j;
    s32 crc = 0;
    s32 temp;
    s32 shifted;

    for (i = 0; i < BLOCKSIZE + 1; i++, data++) {
        for (j = 7; j >= 0; j--) {
            temp = (crc & 0x80) ? 0x85 : 0;
            shifted = crc << 1;
            if (i != BLOCKSIZE) {
                crc = shifted | ((*data >> j) & 1);
            } else {
                crc = shifted;
            }
            crc ^= temp;
        }
    }

    return crc & 0xFF;
}
#else
INCLUDE_ASM("asm/nonmatchings/libultra/__osContDataCrc", __osContDataCrc);
#endif
