#include "o06_types.h"
typedef struct { u8 pad[0x10]; s32 unk10; s32 unk14; s32 unk18; } O06A;
extern void func_0025DF54(s32 a);
void func_0043C458(O06A *a) { a->unk10 = 1; a->unk14 = 0; a->unk18 = 1; func_0025DF54(0xE83); }
