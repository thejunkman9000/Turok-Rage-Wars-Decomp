#include "b19_types.h"
s32 func_0028FD94(s32, s32);
void func_0028FDD8(s32, s32);
void func_00285D80(B19Owner *owner, B19Obj *p, s32 set) {
    s32 idx;
    s32 n, m;
    u8 *bits;
    s32 key;
    B19Info18 *inf;
    B19Obj *tmp;
    if (!(p->flags100 & 0x80000)) {
        u8 *base = owner->base;
        idx = -1;
        if ((u8 *)p >= base && (u8 *)p <= base + (owner->cnt * 0x2E8 - 0x2E8)) {
            idx = (u32)((u8 *)p - base) / 0x2E8;
        }
    } else {
        idx = -1;
    }
    if (idx != -1 && (key = owner->key, owner->mode != 2) &&
        (inf = (B19Info18 *)(tmp = (B19Obj *)(owner->base + idx * 0x2E8))->info, ((u32)(inf->type - 9) < 2) == 0 || !(inf->f4 & 0x200))) {
        n = func_0028FD94(func_0028FD94(func_0028FD94(owner->root, 0), key), 0);
        func_0028FD94(n, 0);
        func_0028FDD8(n, 1);
        bits = (u8 *)func_0028FD94(n, 1);
        m = 1 << (idx & 7);
        if (set != 0) bits[idx / 8] |= m;
        else bits[idx / 8] &= ~m;
    }
}
