#include "b20_types.h"
s32 func_00265508(s32 *ents, s32 n, s32 key);
s32 *func_0028FE1C(s32 *tbl, u8 *base, s32 idx, s32 *size);
s32 func_002518DC(s32 a, s32 *b, s32 *c, s32 size, s32 d, s32 e, void *fn, void *g, s32 h);
void func_00285130();
extern u8 D_800CA2C8[];
s32 func_0028BDE4(Level *lv, s32 key, s32 a2, s32 a3) {
    s32 *t = lv->unk98;
    s32 idx = func_00265508(t + 2, t[1], key);
    s32 size;
    s32 *p;
    if (idx != -1) {
        p = func_0028FE1C(lv->unk58, lv->unk28, idx, &size);
        return func_002518DC(0, p, p, size, a2, 0, func_00285130, D_800CA2C8, a3);
    }
    return 0;
}
