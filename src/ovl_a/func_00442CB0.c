#include "o06_types.h"
typedef struct { u8 pad[0x1C8]; s32 unk1C8; s32 unk1CC; } O06A;
void func_00442CB0(O06A *a) { if (a->unk1CC == 0) { a->unk1CC = 1; a->unk1C8 = 0; } }
