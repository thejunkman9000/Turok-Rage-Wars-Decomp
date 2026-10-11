#include "common.h"

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

static inline s32 clamp16(s32 x) {
    x = x > 0x7FFF ? 0x7FFF : x;
    x = x < -0x8000 ? -0x8000 : x;
    return x;
}
void func_00264F80(s16 *out, s32 n) {
    s32 x1;
    s32 x2;
    s32 cnt;
    s32 acc;
    s32 c1;
    s32 c2;
    s32 d;
    s32 v;
    s32 lo;
    s32 clip;
    s32 idx;
    u32 w;
    u32 f;
    u32 t;
    s32 c;
    s32 shift;
    s32 bA, bB, bC;
    u32 tA, tB, tC;
    s32 cA, cB, cC;
    u8 *pA, *pB, *pC;
    u8 last;
    u8 *p;

    cnt = x2 = x1 = 0;
    last = *((u8 *)&D_8011007C + 3);
    tA = D_8011007C >> 8;
    cA = D_80110080 - 8;
    D_8011007C = tA;
    D_80110080 = cA;
    if (cA < 25) {
        pA = D_80110084;
        bA = *pA;
        D_80110084 = pA + 1;
        D_80110080 = cA + 8;
        D_8011007C = tA | (bA << cA);
    }
    acc = (s8)last << 8;
    while (n-- > 0) {
        if (cnt-- == 0) {
            cnt = 3;
            w = D_80110070;
            tB = w >> 6;
            cB = D_80110074 - 6;
            D_80110070 = tB;
            D_80110074 = cB;
            f = w & 0x3F;
            if (cB < 25) {
                pB = D_80110078;
                bB = *pB;
                D_80110078 = pB + 1;
                D_80110074 = cB + 8;
                D_80110070 = tB | (bB << cB);
            }
            { s32 sv = w & 0xF; __asm__("" : "+r"(sv)); shift = (u8)sv; }
            idx = f >> 4;
            c2 = D_800D0E70[idx];
            c1 = D_800D0E80[idx];
        }
        f = D_8011007E;
        tC = D_8011007C >> 3;
        cC = D_80110080 - 3;
        D_8011007C = tC;
        D_80110080 = cC;
        lo = f & 7;
        if (cC < 25) {
            pC = D_80110084;
        bC = *pC;
        D_80110084 = pC + 1;
            D_80110080 = cC + 8;
            D_8011007C = tC | (bC << cC);
        }
        if (f & 4) {
            d = (s16)(lo | ~7) << shift;
        } else {
            d = lo << shift;
        }
        d = d + ((x1 * c2 + x2 * c1) >> 16);
        __asm__("" : "+r"(d));
        x2 = x1;
        x1 = d;
        acc = acc + x1;
        *out++ = clamp16(acc);
    }
}
