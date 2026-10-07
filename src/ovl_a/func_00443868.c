#include "o06_types.h"
typedef struct { u8 pad[0x8E]; u8 unk8E; } O06C;
typedef struct { u8 pad[0x5D8]; O06C *unk5D8; } O06B;
typedef struct { u8 pad[0x1C]; O06B *unk1C; } O06A;
s32 func_00443868(s32 a, O06A *b) { b->unk1C->unk5D8->unk8E = 1; return 1; }
