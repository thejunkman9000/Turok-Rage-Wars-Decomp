#include "o01_types.h"

extern s32 D_8015377C;
extern s32 D_80153750;
extern s32 D_8015375C;
extern s32 D_800E28C8;
extern O01Text D_800D7754;
extern O01Text D_800D7758;
extern O01Text D_800D7790;
extern u8 D_800E0DAC[];
s32 func_00442158();
void func_00265904(char *dst, u8 *fmt, s32 a);

s32 func_0040A270(O01Item *item) {
    s32 v;
    char *buf;
    if (D_8015377C != 0) {
        if (D_80153750 != 0) {
            item->unk14 = &D_800D7754;
        } else {
            goto chk;
        }
    } else {
        if (D_80153750 != 0) {
            item->unk14 = &D_800D7758;
        } else {
            goto chk;
        }
    }
    goto done;
chk:
    if (D_8015375C != 0) {
        v = D_800E28C8;
        item->unk14 = &D_800D7790;
        buf = D_800D7790.buf;
        func_00265904(buf + (func_00442158() - 1), D_800E0DAC, v + 1);
    }
done:
    return 0;
}
