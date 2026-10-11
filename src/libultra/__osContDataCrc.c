#include "common.h"

u8 __osContDataCrc(u8 *data) {
    s32 i;
    s32 j;
    u8 crc = 0;
    u8 temp;

    for (i = 0; i < BLOCKSIZE + 1; i++, data++) {
        for (j = 7; j >= 0; j--) {
            temp = (crc & 0x80) ? 0x85 : 0;
            crc <<= 1;
            if (i != BLOCKSIZE) {
                crc |= (*data >> j) & 1;
            }
            crc ^= temp;
        }
    }

    return crc;
}
