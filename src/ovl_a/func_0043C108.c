#include "o06_types.h"
typedef struct { u8 pad[0x4B0]; s32 unk4B0; u8 pad2[0x1C]; } O06P;
typedef struct { u8 pad[4]; s32 unk4; u8 pad2[0x1350]; s32 unk1358; s32 unk135C; u8 pad3[8]; s32 unk1368; } O06M;
extern void func_0029A73C();
extern void func_0041B834(s32 a, s32 b, s32 c);
extern void func_0041CE80(void *a, s32 b);
extern void func_0043B2AC(s32 a);
extern O06M *D_800E59E0;
s32 func_0043C108(s32 a, s32 b, s32 c) {
    s32 i;
    O06M *m;
    O06P *p;
    func_0029A73C();
    i = c & 0xFFFF;
    m = D_800E59E0;
    p = (O06P *)m + i;
    switch (p->unk4B0) {
    case 1:
        m->unk1358 = 5;
        m->unk135C = 4;
        m->unk1368 = 7;
        break;
    case 2:
        p->unk4B0 = 0;
        func_0041B834(m->unk4, i, 0);
        func_0041CE80((u8 *)D_800E59E0 + 8 + i * 0x4D0, 1);
        func_0043B2AC(i);
        break;
    }
    return 0;
}
