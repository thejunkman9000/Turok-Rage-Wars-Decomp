#include "b20_types.h"
s32 *func_0028FD94(s32 *tbl, s32 idx);
void func_0028FDD8(s32 *tbl, s32 idx);
s32 func_0028B59C(Level *lv, s32 bit) {
    s32 *t;
    u8 *bits;
    s32 m;
    s32 idx = lv->unk1B40C;
    t = func_0028FD94(func_0028FD94(func_0028FD94(lv->unk84, 0), idx), 0);
    func_0028FD94(t, 0);
    func_0028FDD8(t, 1);
    bits = (u8 *)func_0028FD94(t, 1);
    m = 1 << (bit & 7);
    return (bits[bit / 8] & m) != 0;
}
