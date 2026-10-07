#include "o06_types.h"
typedef struct { u8 pad[0x5D0]; s32 unk5D0; } O06B;
typedef struct { u8 pad[0x1C]; O06B *unk1C; } O06A;
s32 func_00445FC8(s32 a, O06A *b) {
    O06B *p = b->unk1C;
    if (p == 0) return 0;
    if (p->unk5D0 == 1) p->unk5D0 = 2; else if (p->unk5D0 == 2) p->unk5D0 = 1;
    return 0;
}
