#include "b20_types.h"

s32 *func_0028FD94(s32 *tbl, s32 idx);
void func_0028FDD8(s32 *tbl, s32 idx);

s32 func_0028DC18(Level *lv, s32 sel, s32 c, s32 b, s32 bit) {
    s32 *t;
    s32 *base;
    u8 *bits;
    s32 m;
    if (sel != 0) {
        base = lv->unk80;
    } else {
        base = lv->unk84;
    }
    t = func_0028FD94(func_0028FD94(func_0028FD94(base, 0), b), c);
    func_0028FD94(t, 0);
    func_0028FDD8(t, 1);
    bits = (u8 *)func_0028FD94(t, 1);
    m = 1 << (bit & 7);
    return (bits[bit / 8] & m) != 0;
}
