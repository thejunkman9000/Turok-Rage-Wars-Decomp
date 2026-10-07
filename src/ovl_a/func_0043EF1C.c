/* # real entry at 0x43EF20 (first word 0x43EF1C is stray padding); chk verified at ROM 0x1ACF20; global D_801468B0 must be declared as array to keep load order */
#include "o06_types.h"
typedef struct { u8 pad[0x30]; u32 unk30; } O06B;
typedef struct { u8 pad[0xC]; O06B *unkC; } O06A;
extern f32 D_800E2390;
extern f32 D_801468B0[];
void func_0043EF1C(O06A *a) { D_801468B0[0] = D_800E2390; a->unkC->unk30 &= ~0x4000000; }
