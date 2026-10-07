#include "o05_types.h"
typedef struct { u8 pad0[0x16]; s16 h16; u8 pad18[2]; s16 h1A; } O05Wd;
typedef struct { u8 pad0[0x44]; O05Wd *f44; } O05Wd0;
typedef struct { O05Wd0 *f0; void *f4; O05Wd *f8; s32 fC; s32 f10; } O05M84;
extern O05M84 *D_800E5784;
s32 func_0041A4F0(void *w);
void func_0029A73C(void);
void func_00299368(s32 a);
void func_0029A8A8(void);

s32 func_004379F0(void) {
    s32 t = func_0041A4F0(D_800E5784->f0);
    switch (t) {
    case 3:
        D_800E5784->fC--;
        if (D_800E5784->fC <= 0) {
            D_800E5784->f8->h16--;
            if (D_800E5784->f8->h16 + D_800E5784->f8->h1A < 0) {
                D_800E5784->f8->h16 = D_800E5784->f0->f44->h1A;
            }
            D_800E5784->fC = t;
        }
        break;
    case 4:
        func_0029A73C();
        if (D_800E5784->f10 == -1) {
            func_0029A8A8();
            return 0;
        }
        func_00299368(D_800E5784->f10);
        break;
    default:
        return 0;
    }
    return 0;
}
