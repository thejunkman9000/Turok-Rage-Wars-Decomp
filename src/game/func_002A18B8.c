#include "b23_types.h"
u32 func_002A18B8(u8 *data, s32 len, u32 crc) {
    u32 table[256];
    u32 i, j, c;
    u8 *end;
    for (i = 0; i < 256; i++) {
        c = i;
        for (j = 0; j < 8; j++) {
            c = (c & 1) ? (c >> 1) ^ 0xEDB88320 : c >> 1;
        }
        table[i] = c;
    }
    end = data + len;
    crc = ~crc;
    for (; data < end; data++) {
        crc = table[(crc ^ *data) & 0xFF] ^ ((crc >> 8) & 0xFFFFFF);
    }
    return ~crc;

}
