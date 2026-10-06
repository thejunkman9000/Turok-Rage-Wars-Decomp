#include "p4_types.h"
extern u32 D_800D2AE0;
extern s32 D_8014AEC8[];
extern s32 D_8014AECC[];
extern void *D_8014AED4;
extern u8 D_8014AEB0;
void func_002955EC(s32 a, void **out) {
    u32 cnt = D_800D2AE0;
    if (cnt != 0 && *out != NULL && D_8014AEC8[0] == 0) {
        s32 ok;
        if (D_8014AEB0 != 0) {
            ok = cnt != 0;
        } else {
            ok = 0;
        }
        if (ok) {
            ok = (D_8014AEC8[0x21A0 / 4] % 10) < 3;
        } else {
            ok = 1;
        }
        if (a == D_8014AECC[0]) {
            if (ok) {
                *out = &D_8014AECC[4];
            } else {
                *out = D_8014AED4;
            }
        }
    }
}
