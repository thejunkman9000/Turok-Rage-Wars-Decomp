#include "b20_types.h"

void func_002505CC(s32 *a, s32 flag);
extern f32 D_800D2988;

void func_0028D658(Level *lv) {
    f32 f;
    s32 flag;
    s32 i;
    f = lv->unk1B31C + D_800D2988;
    lv->unk1B31C = f;
    flag = 1;
    if (!(f > 0.0f)) {
        flag = 0;
    }
    if (flag != 0) {
        lv->unk1B31C = f - (f32)((s32)f + 1);
    }
    for (i = 0; i < lv->cntC4C; i++) {
        func_002505CC(lv->arrB4C[i], flag);
    }
}
