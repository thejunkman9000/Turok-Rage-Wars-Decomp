#include "b22_types.h"
extern SndAux *D_8014D0B0;
s32 func_0029A958(void);
s32 func_0029A5D4(s32, s32, s32, s32, s32);
static inline s32 TestBit(u16 ch, s16 bit)
{
    s32 b = bit;
    s32 q, r, one, cx;
    q = b / 8;
    r = b % 8;
    one = 1;
    cx = (s16)ch * 4;
    return *((s8 *)D_8014D0B0 + (q + cx) + 3076) & (one << r);
}
static inline void PutBit(u16 ch, s16 bit, s8 on)
{
    s32 bi = bit;
    s32 cx;
    s32 mask = 1 << (bi % 8);
    if (on == 1) {
        cx = (s16)ch * 4;
        *((u8 *)D_8014D0B0 + (bi / 8 + cx) + 3076) |= mask;
    } else {
        cx = (s16)ch * 4;
        *((u8 *)D_8014D0B0 + (bi / 8 + cx) + 3076) &= ~mask;
    }
}
void func_0029AE80(SndMsg *m)
{
    s32 id = func_0029A958();
    s32 key = ((u16)m->type << 16) | m->a;
    s32 c = m->c;
    s8 flag = m->e == 1;
    if (c == -1) {
        return;
    }
    switch (c) {
    case 11:
        if (flag) {
            if (!TestBit(m->a, c)) {
                func_0029A5D4(id, 1, key, c, 0);
            }
        }
        break;
    case 12:
        if (flag) {
            if (!TestBit(m->a, c)) {
                func_0029A5D4(id, 2, key, c, 0);
            }
        }
        break;
    case 4:
        if (flag) {
            if (!TestBit(m->a, c)) {
                func_0029A5D4(id, 5, key, 1, 10000);
            }
            func_0029A5D4(id, 5, key, 0, 10000);
        }
        break;
    case 5:
        if (flag) {
            if (!TestBit(m->a, c)) {
                func_0029A5D4(id, 6, key, 1, 10000);
            }
            func_0029A5D4(id, 6, key, 0, 10000);
        }
        break;
    case 6:
        if (flag) {
            if (!TestBit(m->a, c)) {
                func_0029A5D4(id, 7, key, 1, 10000);
            }
            func_0029A5D4(id, 7, key, 0, 10000);
        }
        break;
    case 7:
        if (flag) {
            if (!TestBit(m->a, c)) {
                func_0029A5D4(id, 8, key, 1, 10000);
            }
            func_0029A5D4(id, 8, key, 0, 10000);
        }
        break;
    }
    if (flag == 1) {
        if (!TestBit(m->a, c)) {
            func_0029A5D4(id, 0xA, key, c, 0);
        }
        func_0029A5D4(id, 9, key, c, 0);
    } else {
        func_0029A5D4(id, 0xB, key, c, 0);
    }
    PutBit(m->a, c, flag);
}
