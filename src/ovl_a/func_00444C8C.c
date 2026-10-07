#include "o06_types.h"
typedef struct { u8 pad[0x7A]; u8 unk7A; } O06C;
typedef struct { u8 pad[0x5D8]; O06C *unk5D8; } O06B;
typedef struct { u8 pad[0x14]; void *unk14; u8 pad2[4]; O06B *unk1C; } O06A;
extern s32 func_00442158(O06A *a);
extern void func_00265904(s32 a, void *b, s32 c);
extern u8 D_80146302;
extern s32 D_800D762C[];
extern s32 D_800D7630[];
extern u8 D_800E2788[];
extern u8 D_800E2790[];
s32 func_00444C8C(O06A *a, O06A *b) {
    O06C *p = (O06C *)&D_80146302;
    s32 n, s;
    if (b->unk1C) { O06C *q = b->unk1C->unk5D8; if (q) p = q; }
    n = ((s32)p->unk7A - 0x80) / 8;
    if (n == 0) {
        a->unk14 = D_800D762C;
    } else if (n > 0) {
        s = D_800D7630[0];
        a->unk14 = D_800D7630;
        func_00265904(s - 4 + func_00442158(a), D_800E2788, n);
    } else {
        s = D_800D7630[0];
        a->unk14 = D_800D7630;
        func_00265904(s - 4 + func_00442158(a), D_800E2790, n);
    }
    return 0;
}
