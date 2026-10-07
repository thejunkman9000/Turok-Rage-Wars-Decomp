#include "o06_types.h"
typedef struct { u8 pad[0x82]; u8 unk82; } O06C;
typedef struct { u8 pad[0x5D8]; O06C *unk5D8; } O06B;
typedef struct { u8 pad[0x14]; void *unk14; u8 pad2[4]; O06B *unk1C; } O06A;
extern u8 D_80146302;
extern u8 D_800D7634[];
extern u8 D_800D7638[];
s32 func_00444D58(O06A *a, O06A *b) {
 O06B *q = b->unk1C;
 O06C *p;
 if (q) p = q->unk5D8; else p = (O06C *)&D_80146302;
 if (p->unk82 == 1) a->unk14 = D_800D7634; else a->unk14 = D_800D7638;
 return 0;
}
