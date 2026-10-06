#include "p4_types.h"
typedef struct { u8 pad0[0x80]; s32 f80; } P4Tree;
s32 func_0028FD94(s32 a, s32 b);
void func_0028FDD8(s32 a, s32 b);
s32 func_0028DD80(P4Tree *o, s32 i, s32 bit) {
    s32 n = func_0028FD94(func_0028FD94(func_0028FD94(o->f80, 0), i), 0);
    u8 *bits;
    func_0028FD94(n, 0);
    func_0028FDD8(n, 1);
    bits = (u8 *)func_0028FD94(n, 1);
    {
        s32 m = 1 << (bit & 7);
        return (bits[bit / 8] & m) != 0;
    }
}
