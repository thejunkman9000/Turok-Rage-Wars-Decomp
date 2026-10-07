#include "o06_types.h"
typedef struct { u8 pad[0x4B0]; s32 unk4B0; u8 pad2[0x1C]; } O06P;
extern O06P *D_800E59E0;
s32 func_0043BC04(void) { s32 i, n = 0; for (i = 0; i < 4; i++) if (D_800E59E0[i].unk4B0 == 1) n++; return n; }
