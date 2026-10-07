#include "o06_types.h"
typedef struct { u8 pad[0x82]; u8 unk82; } O06C;
typedef struct { u8 pad[0x5D8]; O06C *unk5D8; } O06B;
typedef struct { u8 pad[0x1C]; O06B *unk1C; } O06A;
extern u8 D_80146302;
s32 func_00444DA4(s32 a, O06A *b) {
    O06C *p = (O06C *)&D_80146302;
    if (b->unk1C) p = (O06C *)b->unk1C->unk5D8;
    if (p->unk82 == 1) p->unk82 = 0; else p->unk82 = 1;
    return 0;
}
