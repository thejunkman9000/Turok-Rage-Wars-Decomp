#include "o06_types.h"
typedef struct { u8 pad[0x1C]; s32 unk1C; } O06B;
typedef struct { u8 pad[0x14]; O06B *unk14; } O06A;
s32 func_0044251C(O06A *a) { return a->unk14->unk1C; }
