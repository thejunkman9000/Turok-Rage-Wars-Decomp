#include "o06_types.h"
typedef struct { u8 pad[0x7A]; u8 unk; } O06C;
typedef struct { u8 pad[0x5D8]; O06C *unk5D8; } O06B;
typedef struct { u8 pad[0x14]; s32 *unk14; u8 pad2[4]; O06B *unk1C; } O06A;
extern s32 func_auto_00442EE0(O06A *a);
extern void func_00265904(s32 a, void *b, s32 c);
extern u8 D_auto_80152242;
extern u8 D_auto_80150F80[];
extern s32 D_auto_800E2254[];
extern s32 D_auto_800E2264[];
extern u8 D_auto_800EEDD8[];
extern u8 D_auto_800EEDE0[];
s32 func_auto_00445C14(O06A *a, O06A *b) {
    O06C *p = (O06C *)&D_auto_80152242;
    s32 n, s;
    if (b->unk1C) { O06C *q = b->unk1C->unk5D8; if (q) p = q; }
    n = ((s32)p->unk - 0x80) / 8;
    if (n == 0) {
        a->unk14 = D_auto_800E2254;
    } else if (n > 0) {
        a->unk14 = D_auto_800E2264;
        s = a->unk14[D_auto_80150F80[0x1809]];
        func_00265904(s - 4 + func_auto_00442EE0(a), D_auto_800EEDD8, n);
    } else {
        a->unk14 = D_auto_800E2264;
        s = a->unk14[D_auto_80150F80[0x1809]];
        func_00265904(s - 4 + func_auto_00442EE0(a), D_auto_800EEDE0, n);
    }
    return 0;
}
