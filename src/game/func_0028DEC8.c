#include "b20_types.h"

s32 *func_0028FD94(s32 *tbl, s32 idx);
void func_0028FDD8(s32 *tbl, s32 idx);

s32 func_0028DEC8(Level *lv, s32 a, s32 bit) {
    s32 *t = func_0028FD94(func_0028FD94(func_0028FD94(lv->unk80, 0), a), 2);
    u8 *bits;
    s32 m;
    func_0028FD94(t, 0);
    func_0028FDD8(t, 1);
    bits = (u8 *)func_0028FD94(t, 1);
    m = 1 << (bit & 7);
    return (bits[bit / 8] & m) != 0;
}
