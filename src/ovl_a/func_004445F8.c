#include "o06_types.h"
typedef struct { u8 pad[0x7C]; u8 f; } O06C;
typedef struct { u8 pad[0x5D8]; O06C *unk5D8; } O06B;
typedef struct { u8 pad[0x1C]; O06B *unk1C; } O06A;
extern s32 func_0044252C(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);
extern u8 D_80146302;
s32 func_004445F8(s32 a, O06A *b) {
    O06C *p = (O06C *)&D_80146302;
    if (b->unk1C) { O06C *q = b->unk1C->unk5D8; if (q) p = q; }
    p->f = func_0044252C((s32)b, p->f, 1, 0, 1, 1);
    return 0;
}
