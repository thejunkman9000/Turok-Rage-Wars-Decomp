#include "o05_types.h"

typedef struct { u8 pad0[0x16]; s16 h16; u8 pad18[2]; s16 h1A; } O05Wd;
typedef struct { u8 pad0[0x44]; O05Wd *f44; } O05Wd0;
typedef struct { O05Wd0 *f0; void *f4; O05Wd *f8; s32 fC; s32 f10; s32 f14; } O05M80;
extern O05M80 *D_800E5780;
extern u8 D_80102B7E[];
s32 func_0041A4F0(void *w);
s32 func_00265670(void *p, s32 a);
void func_0029A1D4(s32 a);
void func_0029A73C(void);
void func_00299368(s32 a);

s32 func_auto_00437444(void) {
    s32 t = func_0041A4F0(D_800E5780->f0);
    s32 a;
    switch (t) {
    case 1:
        if (D_800E5780->f14 != 0) {
            return 0;
        }
        D_800E5780->f14 = t;
        if (func_00265670(D_80102B7E, 0) != 0) {
            return 0;
        }
        func_0029A1D4(0x139);
        return 0;
    case 3:
        D_800E5780->fC--;
        if (D_800E5780->fC <= 0) {
            D_800E5780->f8->h16--;
            if (D_800E5780->f8->h16 + D_800E5780->f8->h1A < 0) {
                D_800E5780->f8->h16 = D_800E5780->f0->f44->h1A;
            }
            D_800E5780->fC = t;
        }
        break;
    case 4:
        func_0029A73C();
        a = D_800E5780->f10;
        if (a == -1) {
            a = 3;
        }
        func_00299368(a);
        break;
    default:
        return 0;
    }
    return 0;
}
