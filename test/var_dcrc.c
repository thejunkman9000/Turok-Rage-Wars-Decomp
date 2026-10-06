#include "common.h"

/* A: crc <<= 1 form */
u8 a1(u8 *data) {
    s32 i, j, crc = 0, temp;
    for (i = 0; i <= 32; i++, data++) {
        for (j = 7; j >= 0; j--) {
            temp = (crc & 0x80) ? 0x85 : 0;
            crc <<= 1;
            if (i != 32) crc |= (*data >> j) & 1;
            crc ^= temp;
        }
    }
    return crc & 0xFF;
}

/* B: declare i,j last */
u8 b1(u8 *data) {
    s32 crc = 0, temp, i, j;
    for (i = 0; i <= 32; i++, data++) {
        for (j = 7; j >= 0; j--) {
            temp = (crc & 0x80) ? 0x85 : 0;
            crc <<= 1;
            if (i != 32) crc |= (*data >> j) & 1;
            crc ^= temp;
        }
    }
    return crc & 0xFF;
}

/* C: u32 types */
u8 c1(u8 *data) {
    u32 i, j, crc = 0, temp;
    for (i = 0; i <= 32; i++, data++) {
        for (j = 7; (s32)j >= 0; j--) {
            temp = (crc & 0x80) ? 0x85 : 0;
            crc <<= 1;
            if (i != 32) crc |= (*data >> j) & 1;
            crc ^= temp;
        }
    }
    return crc & 0xFF;
}

/* D: if/else temp assignment, data indexed */
u8 d1(u8 *data) {
    s32 i, j, crc = 0, temp;
    for (i = 0; i < 33; i++) {
        for (j = 7; j >= 0; j--) {
            if (crc & 0x80) temp = 0x85; else temp = 0;
            crc <<= 1;
            if (i == 32) { } else if (data[i] & (1 << j)) crc |= 1;
            crc ^= temp;
        }
    }
    return crc & 0xFF;
}

/* E: temp declared first */
u8 e1(u8 *data) {
    s32 temp, crc = 0, i, j;
    for (i = 0; i <= 32; i++) {
        for (j = 7; j >= 0; j--) {
            temp = (crc & 0x80) ? 0x85 : 0;
            crc <<= 1;
            if (i != 32) crc |= (data[i] >> j) & 1;
            crc ^= temp;
        }
    }
    return crc & 0xFF;
}
