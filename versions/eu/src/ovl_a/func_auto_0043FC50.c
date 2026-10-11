#include "o06_types.h"
typedef struct { u8 pad[0x30]; u32 unk30; } O06B;
typedef struct { u8 pad[0xC]; O06B *unkC; } O06A;
extern f32 D_auto_800EE9E0;
extern f32 D_auto_801527F0[];
void func_auto_0043FC50(O06A *a) { D_auto_801527F0[0] = D_auto_800EE9E0; a->unkC->unk30 &= ~0x4000000; }
