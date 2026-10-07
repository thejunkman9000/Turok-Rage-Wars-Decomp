#include "o05_types.h"

typedef struct { void *f0; void *f4; } O05M0A4;
extern O05M0A4 *D_800E58A4;
extern u8 D_801462E0[];
s32 func_0041A760(void *w);
void func_0025DF54(s32 a);
s32 func_0025E2E4(void);
void func_0025E2F4(s32 a);

s32 func_004394E8(void) {
    s32 t;
    t = func_0041A760(D_800E58A4->f4);
    if (t != D_801462E0[1]) {
        D_801462E0[1] = t;
        func_0025DF54(0x460);
    }
    t = func_0041A760(D_800E58A4->f0);
    if (t != D_801462E0[0]) {
        D_801462E0[0] = t;
        if ((u8)t >= 5) {
            if (func_0025E2E4() == 0) {
                func_0025E2F4(0x34);
            }
        } else {
            func_0025E2F4(0);
        }
    }
    return 0;
}
