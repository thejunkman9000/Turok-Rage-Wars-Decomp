#include "o06_types.h"
typedef struct { u8 pad[0x1C]; s32 unk1C; } O06A;
extern void func_0044A37C(s32 a);
s32 func_00443880(s32 a, O06A *b) { func_0044A37C(b->unk1C); return 1; }
