#include "veu3n10_types.h"

extern VeuCheatBuf D_800E5CA0;   /* 0x800F22C0 */
extern f32 D_800D2988;           /* 0x800CE318: frame time */
extern s32 func_002643A8(s32 pad);
extern s32 func_002643C0(s32 pad);

/* cursor movement + blink timer of the code entry line */
s32 func_auto_0043DA10(s32 unused, VeuMenuObj *a) {
    D_800E5CA0.timer += D_800D2988;
    if (D_800E5CA0.timer >= 15.0f) D_800E5CA0.timer -= 15.0f;
    if (a->state == 2) {
        if (func_002643A8(a->pad) && D_800E5CA0.pos > 0) {
            D_800E5CA0.pos--;
            D_800E5CA0.timer = 0;
        } else if (func_002643C0(a->pad)) {
            if (D_800E5CA0.pos < D_800E5CA0.len) {
                D_800E5CA0.pos++;
                D_800E5CA0.timer = 0;
            }
        }
    }
    return 0;
}
