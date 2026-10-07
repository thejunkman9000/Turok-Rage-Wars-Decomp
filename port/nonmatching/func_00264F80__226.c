#include "b14_types.h"
extern u32 D_80110070;
extern s32 D_80110074;
extern u8 *D_80110078;
extern u32 D_8011007C;
extern u16 D_8011007E;
extern u8 D_8011007F;
extern s32 D_80110080;
extern u8 *D_80110084;
extern s32 D_800D0E70[];
extern s32 D_800D0E80[];
void func_00264F80(s16 *out, s32 n) {
    s32 x1 = 0;
    s32 x2 = 0;
    s32 cnt = 0;
    u8 shift;
    s32 c1, c2;
    s32 d;
    s32 acc;
    s32 v;
    s32 lo;
    u32 w;
    u32 w2;
    u32 t0;
    s32 b2;
    u8 byte;
    u32 f;
    t0 = D_8011007C >> 8;
    b2 = D_80110080 - 8;
    D_8011007C = t0;
    D_80110080 = b2;
    if (b2 < 25) {
        byte = *D_80110084;
        D_80110084 += 1;
        D_80110080 = b2 + 8;
        D_8011007C = t0 | (byte << b2);
    }
    acc = (s8)D_8011007F << 8;
    while (n-- > 0) {
        if (--cnt == 0) {
            u32 t1;
            s32 bb;
            s32 idx;
            cnt = 3;
            w = D_80110070;
            bb = D_80110074;
            t1 = w >> 6;
            D_80110070 = t1;
            D_80110074 = bb - 6;
            f = w & 0x3F;
            if (bb - 6 < 25) {
                byte = *D_80110078;
                D_80110078 += 1;
                D_80110074 = bb + 2;
                D_80110070 = t1 | (byte << (bb - 6));
            }
            shift = w & 0xF;
            idx = f >> 4;
            c2 = D_800D0E70[idx];
            c1 = D_800D0E80[idx];
        }
        f = D_8011007E;
        w2 = D_8011007C >> 3;
        b2 = D_80110080 - 3;
        lo = f & 7;
        D_8011007C = w2;
        D_80110080 = b2;
        if (b2 < 25) {
            byte = *D_80110084;
            D_80110084 += 1;
            D_80110080 = b2 + 8 - 3 + 3;
            D_8011007C = w2 | (byte << b2);
        }
        if (f & 4) {
            d = (s16)(lo | ~7) << shift;
        } else {
            d = lo << shift;
        }
        v = d + ((x1 * c2 + x2 * c1) >> 16);
        x2 = x1;
        x1 = v;
        acc = (s16)(acc + x1);
        if (acc > 0x7FFF) {
            acc = 0x7FFF;
        }
        if (acc < -0x8000) {
            acc = -0x8000;
        }
        *out++ = acc;
    }
}
