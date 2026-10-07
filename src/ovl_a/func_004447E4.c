#include "o06_types.h"
typedef struct { u8 pad[0x7E]; u8 f; } O06C;
typedef struct { u8 pad[0x5D8]; O06C *unk5D8; } O06B;
typedef struct { u8 pad[0x14]; void *unk14; u8 pad2[4]; O06B *unk1C; } O06A;
extern u8 D_80146302;
extern u8 D_800D7600[];
extern u8 D_800D75FC[];
s32 func_004447E4(O06A *a, O06A *b) {
O06C *p = (O06C *)&D_80146302;
if (b->unk1C) { O06C *q = b->unk1C->unk5D8; if (q) p = q; }
 switch (p->f) { case 0: a->unk14 = D_800D7600; break; case 1: a->unk14 = D_800D75FC; break; }
 return 0; }
