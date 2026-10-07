#include "o06_types.h"
typedef struct { u8 pad[0x14]; void *unk14; } O06A;
extern s32 D_800E63AC;
extern u8 D_800E62DC[];
extern u8 D_800E62F0[];
s32 func_004453E0(O06A *a) { if (D_800E63AC) a->unk14 = D_800E62DC; else a->unk14 = D_800E62F0; return 0; }
