#include "p4_types.h"
typedef struct { u8 pad0[0x19E]; u16 f19E; } P4EntB;
typedef struct { u8 pad0[0x80]; s32 f80; } P4OwnB;
s32 func_0028FD94(s32 a, s32 b);
void func_0028FDD8(s32 a, s32 b);
void func_0028B874(P4OwnB *o, P4EntB *e, s32 set) {
    s32 bit = e->f19E;
    s32 idx = *(s32 *)((u8 *)o + 0x1B40C);
    s32 n = func_0028FD94(func_0028FD94(func_0028FD94(o->f80, 0), idx), 1);
    func_0028FD94(n, 0);
    func_0028FDD8(n, 1);
    {
        u8 *bits = (u8 *)func_0028FD94(n, 1);
        u8 *p2 = bits;
        s32 m = 1 << (bit & 7);
        if (set != 0) {
            bits[bit / 8] |= m;
        } else {
            p2[bit / 8] &= ~m;
        }
    }
}
