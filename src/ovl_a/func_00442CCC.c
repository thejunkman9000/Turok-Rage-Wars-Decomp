#include "o06_types.h"
typedef struct { u8 pad[0x1C8]; s32 unk1C8; s32 unk1CC; } O06A;
void func_00442CCC(O06A *a) { a->unk1C8 += a->unk1CC; if (a->unk1C8 >= 0x30) { a->unk1C8 = 0; a->unk1CC = 0; } }
