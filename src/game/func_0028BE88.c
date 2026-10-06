#include "b20_types.h"
s32 func_00265508(s32 *ents, s32 n, s32 key);
s32 *func_0028FE1C(s32 *tbl, u8 *base, s32 idx, s32 *size);
s32 func_002518DC(s32 a, s32 *b, s32 *c, s32 size, s32 flags, Level *lv, void *fn, void *g, s32 h);
void func_00285130();
void func_0028E480();
void func_0028E5AC();
extern u8 D_800CA2D8[];
s32 func_0028BE88(Level *lv, s32 key, s32 flags, s32 a3) {
    s32 *t;
    s32 idx;
    s32 size;
    s32 *p;
    void (*fn)();
    if (key == 0 || (t = lv->unk9C, idx = func_00265508(t + 2, t[1], key), idx == -1)) {
        return 0;
    }
    switch (key) {
    case 5:
        fn = func_0028E480;
        break;
    case 7:
        fn = func_0028E5AC;
        break;
    default:
        fn = func_00285130;
        break;
    }
    if (key > 0) {
        if (key < 8) {
            goto hi;
        }
        if (key < 0x69) {
            if (key >= 0x64) {
hi:
                flags |= 0x18;
                goto done;
            }
        }
    }
    flags |= 4;
done:
    p = func_0028FE1C(lv->unk5C, lv->unk2C, idx, &size);
    return func_002518DC(0, p, p, size, flags, lv, fn, D_800CA2D8, a3);
}
