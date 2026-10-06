#ifndef B14_TYPES_H
#define B14_TYPES_H
#include "p1_types.h"

/* batch 14 (ROM 0x5FB54-0x66B20): small value types, provisional names */
typedef struct B14Vec3 { f32 x, y, z; } B14Vec3;
typedef struct B14W3 { s32 a, b, c; } B14W3;
typedef struct B14W4 { s32 a, b, c, d; } B14W4;

/* bit-stream reader: byte pointer + bit position */
typedef struct B14BitRd {
    /* 0x00 */ u8 *data;
    /* 0x04 */ s32 pos;
} B14BitRd;

/* input/pad-like object: bit flag words at 0xB4 (also read bytewise) and 0xC0 */
typedef struct B14Pad {
    /* 0x00 */ u8 pad0[0xB4];
    /* 0xB4 */ union { u32 w; u8 b[4]; } fB4;
    /* 0xB8 */ u8 padB8[8];
    /* 0xC0 */ u32 fC0;
} B14Pad;
#endif
