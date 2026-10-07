#include "o06_types.h"
typedef struct { u8 pad[0x14]; void *unk14; } O06A;
extern s32 D_800E63BC;
extern u8 D_800E6100[];
extern u8 D_800E611C[];
s32 func_0044610C(O06A *a) { if (D_800E63BC) a->unk14 = D_800E6100; else a->unk14 = D_800E611C; return 0; }
