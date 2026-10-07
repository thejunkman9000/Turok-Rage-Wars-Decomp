#include "o06_types.h"
typedef struct { u8 pad[0x14]; s16 unk14; } O06A;
extern void func_00255C40(O06A *a, s32 b, s32 c);
void func_004426B4(O06A *a) { func_00255C40(a, 0x1D0, 0x1D4); a->unk14 = 0; }
