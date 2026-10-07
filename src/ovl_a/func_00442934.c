#include "o06_types.h"
typedef struct { s16 unk0; u8 pad[0x22]; } O06I;
typedef struct { O06I *unk0; s16 unk4; } O06B;
typedef struct { u8 pad[0x14]; s16 unk14; } O06A;
typedef struct { u8 pad[0x14]; s32 unk14; s32 unk18; s32 unk1C; s32 unk20; s32 unk24; } O06C;
static inline s32 O06_ItemSize(s16 *a) { if (*a == 3) return 0x480; return 0; }
extern s32 *func_002533DC();
extern void func_00440F10();
extern void func_00255C58(O06A *a, s32 b);
extern u8 D_800E2518[];
s32 func_00442934(O06A *a, O06C *c, O06B *b) {
    s32 size, i;
    s32 *r;
    s32 s;
    s32 p1 = c->unk14, p2 = c->unk1C, p3 = c->unk20, p4 = c->unk24;
    size = b->unk4 * 40 + 0x1D8;
    for (i = 0; i < b->unk4; i++) size += O06_ItemSize(&b->unk0[i].unk0);
    r = func_002533DC(0, size, 0x3B, D_800E2518 + 4);
    if (r == 0) return 0;
    s = *r;
    if (s == 0) return 0;
    func_00440F10(s, r, b, p1, p2, p3, p4, a);
    func_00255C58(a, s);
    { s16 t = a->unk14 + 1; a->unk14 = t; if (t >= 4) a->unk14 = 0; }
    return s;
}
