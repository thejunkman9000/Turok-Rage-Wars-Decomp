#include "o06_types.h"
typedef struct { u8 pad[0x1C8]; s32 unk1C8; } O06A;
s32 func_00442CF8(O06A *a) { s32 v = a->unk1C8; if (v < 0x18) return v; return 0x2F - v; }
