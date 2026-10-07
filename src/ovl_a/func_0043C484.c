#include "o06_types.h"
typedef struct { u8 pad[0x10]; s32 unk10; s32 unk14; s32 unk18; } O06A;
void func_0043C484(O06A *a) { a->unk14 += a->unk10; if (a->unk14 >= 0xD) { a->unk14 = 0; a->unk10 = 0; a->unk18 = 2; } }
