#include "o06_types.h"
typedef struct { s16 unk0; u8 pad[0x22]; } O06I;
typedef struct { O06I *unk0; s16 unk4; } O06B;
typedef struct { u8 pad[0x14]; s16 unk14; } O06A;
static inline s32 O06_ItemSize(s16 *a) { if (*a == 3) return 0x480; return 0; }
extern s32 *func_002533DC();
extern void func_00440F10();
extern void func_00255C58(O06A *a, s32 b);
extern u8 D_800E2518[];
s32 func_0044339C(O06A *a, O06B *b, s32 c, s32 d, s32 e, s32 f) {
    s32 size, i;
    s32 *r;
    s32 s;
    size = b->unk4 * 40 + 0x1D8;
    for (i = 0; i < b->unk4; i++) size += O06_ItemSize(&b->unk0[i].unk0);
    r = func_002533DC(0, size, 0x3B, D_800E2518 + 4);
    if (r == 0) return 0;
    s = *r;
    if (s == 0) return 0;
    func_00440F10(s, r, b, c, d, e, f, a);
    func_00255C58(a, s);
    { s16 t = a->unk14 + 1; a->unk14 = t; if (t >= 4) a->unk14 = 0; }
    return s;
}
