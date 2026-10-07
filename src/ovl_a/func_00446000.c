#include "o06_types.h"
typedef struct { u8 pad[0x5D0]; s32 unk5D0; } O06B;
typedef struct { u8 pad[0x14]; void *unk14; u8 pad2[4]; O06B *unk1C; } O06A;
extern u8 D_800E6090[];
extern u8 D_800E60AC[];
s32 func_00446000(O06A *a, O06A *b) {
    if (b->unk1C == 0) return 0;
    if (b->unk1C->unk5D0 == 1) a->unk14 = D_800E6090; else a->unk14 = D_800E60AC;
    return 0;
}
