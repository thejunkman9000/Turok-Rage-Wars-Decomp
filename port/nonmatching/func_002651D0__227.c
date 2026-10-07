#include "b14_types.h"
extern u32 D_80110070;
extern s32 D_80110074;
extern u8 *D_80110078;
extern u32 D_8011007C;
extern s32 D_80110080;
extern u8 *D_80110084;
void func_00264F80(s32 a, s32 b);
s32 func_002651D0(s32 *tbl, u8 *src, s32 count) {
    s32 hdr;
    s32 bitpos;
    u8 *q;
    s32 i;
    s32 sh;
    hdr = *src++ << 8;
    hdr |= *src++;
    bitpos = ((hdr + 3) / 4) * 6;
    q = src + bitpos / 8;
    D_8011007C = q[0];
    D_8011007C |= q[1] << 8;
    sh = bitpos & 7;
    D_8011007C |= q[2] << 16;
    D_80110080 = 32 - sh;
    D_80110084 = q + 4;
    D_8011007C |= q[3] << 24;
    D_8011007C >>= sh;
    for (i = 0; i < count; i++) {
        D_80110070 = src[0];
        D_80110070 |= src[1] << 8;
        D_80110070 |= src[2] << 16;
        D_80110074 = 32;
        D_80110078 = src + 4;
        D_80110070 |= src[3] << 24;
        func_00264F80(tbl[i], hdr);
    }
    return hdr;
}
