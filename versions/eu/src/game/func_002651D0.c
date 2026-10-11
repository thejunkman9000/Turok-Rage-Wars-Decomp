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
    u8 *p;
    s32 i;
    s32 sh;
    s32 n;
    u8 b3;
    u8 c3;
    hdr = *src++ << 8;
    hdr |= *src++;
    n = count;
    bitpos = ((hdr + 3) / 4) * 6;
    q = src + bitpos / 8;
    D_8011007C = q[0];
    D_8011007C |= q[1] << 8;
    sh = bitpos & 7;
    D_8011007C |= q[2] << 16;
    b3 = q[3];
    D_80110080 = 32 - sh;
    D_80110084 = q + 4;
    D_8011007C |= b3 << 24;
    D_8011007C >>= sh;
    for (i = 0; i < n; i++) {
        p = src;
        D_80110070 = *p++;
        D_80110070 |= *p++ << 8;
        D_80110070 |= *p++ << 16;
        c3 = *p++;
        D_80110074 = 32;
        D_80110070 |= c3 << 24;
        D_80110078 = p;
        func_00264F80(tbl[i], hdr);
    }
    return hdr;
}
