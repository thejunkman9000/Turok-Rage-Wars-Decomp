#include "o06_types.h"
typedef struct { u8 pad[0x14]; void *unk14; } O06A;
extern s32 D_800D0EBC;
extern u8 D_800E60E4[];
extern u8 D_800E60C8[];
s32 func_00446090(O06A *a) { if (D_800D0EBC) a->unk14 = D_800E60E4; else a->unk14 = D_800E60C8; return 0; }
