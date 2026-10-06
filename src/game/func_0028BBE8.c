#include "b20_types.h"

typedef struct { u8 pad0[0x13]; u8 unk13; } Src;

s32 *func_0028FD94(s32 *tbl, s32 idx);
void func_0028FDD8(s32 *tbl, s32 idx);

s32 func_0028BBE8(Level *lv, Src *s) {
    s32 bit = s->unk13;
    s32 idx = lv->unk1B40C;
    s32 *t = func_0028FD94(func_0028FD94(func_0028FD94(lv->unk80, 0), idx), 2);
    u8 *bits;
    s32 m;
    func_0028FD94(t, 0);
    func_0028FDD8(t, 1);
    bits = (u8 *)func_0028FD94(t, 1);
    m = 1 << (bit & 7);
    return (bits[bit / 8] & m) != 0;
}
