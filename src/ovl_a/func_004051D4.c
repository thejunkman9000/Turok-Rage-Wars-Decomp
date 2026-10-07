#include "o01_types.h"

extern s32 D_801534F0[];
extern s32 D_80153500[];
extern OSPfs D_80153510[];
extern u8 D_8010FBB8;
s32 func_0026451C(s32 flag);
void func_00263760();
void func_0026456C(void);
s32 func_00404018(s32 ch);

s32 func_004051D4(s32 pad) {
    s32 r;
    if (D_801534F0[pad] != 3) {
        return -2;
    }
    func_0026451C(1);
    func_00263760();
    r = D_80153500[pad];
    D_8010FBB8 = 2;
    if (r == -4) {
        r = __osGetId(&D_80153510[pad]);
        if (r != 0) {
            r = -1;
        }
        func_00404018(pad);
    }
    func_0026456C();
    return r;
}
