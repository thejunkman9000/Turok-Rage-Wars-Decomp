#include "o06_types.h"
typedef struct { u8 pad[0x4B0]; s32 unk4B0; u8 pad2[0x1C]; } O06P;
typedef struct { O06P base; s32 unk4D0; s32 unk4D4; } O06Q;
extern void func_0029A73C();
extern void func_0025DF54(s32 a);
extern void func_0043B03C(s32 a, s32 b);
extern O06P *D_800E59E0;
s32 func_0043BFD0(s32 a, s32 b, s32 c, s32 d) {
    s32 i; O06P *p;
    func_0029A73C();
    if (d != 1) return 0;
    i = c & 0xFFFF;
    p = &D_800E59E0[i];
    if (((O06Q *)p)->unk4D4 != 2) return 0;
    if (p->unk4B0 != d) return 0;
    func_0025DF54(0xE7B);
    func_0043B03C(i, -1);
    return 0;
}
