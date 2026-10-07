#include "o05_types.h"

typedef struct { void *f0; u8 pad4[4]; void *f8; void *fC; u8 pad10[4]; s32 f14; } O05M0A;
extern O05M0A *D_800E58A0;
extern u8 D_801462E0[];
s32 func_0041A4F0(void *w);
s32 func_0041A760(void *w);
void func_0029A73C(void);
void func_00299368(s32 a);
void func_0029A8A8(void);
void func_0025DF54(s32 a);
s32 func_0025E2E4(void);
void func_0025E2F4(s32 a);

s32 func_004391F8(void) {
    s32 t;
    switch (func_0041A4F0(D_800E58A0->f0)) {
    case 3:
        break;
    case 4:
        func_0029A73C();
        if (D_800E58A0->f14 != -1) {
            func_00299368(D_800E58A0->f14);
            return 0;
        }
        func_0029A8A8();
        return 0;
    }
    t = func_0041A760(D_800E58A0->fC);
    if (t != D_801462E0[1]) {
        D_801462E0[1] = t;
        func_0025DF54(0x460);
    }
    t = func_0041A760(D_800E58A0->f8);
    if (t != D_801462E0[0]) {
        D_801462E0[0] = t;
        if ((u8)t >= 5) {
            if (func_0025E2E4() != 0) {
                return 0;
            }
            func_0025E2F4(0x34);
        } else {
            func_0025E2F4(0);
        }
    }
    return 0;
}
