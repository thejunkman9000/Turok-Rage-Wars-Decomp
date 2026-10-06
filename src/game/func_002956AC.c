#include "common.h"

extern u8 D_8014AEB0;
extern u32 D_800D2AE0;
extern s32 D_8014AEC8[];
extern s32 D_8014AECC[];
extern s32 D_8014AED8;

void func_002956AC(s32 x, s32 *out) {
    s32 ok;
    if (D_800D2AE0 != 0 && *out != 0 && D_8014AEC8[0] == 0) {
        if (D_8014AEB0 != 0) {
            ok = D_800D2AE0 != 0;
        } else {
            ok = 0;
        }
        if (ok) {
            ok = D_8014AEC8[0x21A0 / 4] % 10 < 3;
        } else {
            ok = 1;
        }
        if (x == D_8014AECC[0]) {
            if (ok) {
                *out = (s32)((u8 *)D_8014AECC + 0x2010);
            } else {
                *out = D_8014AED8;
            }
        }
    }
}
