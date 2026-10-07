#include "o06_types.h"
typedef struct { u8 pad[0x5D0]; s32 unk5D0; } O06B;
typedef struct { u8 pad[0x1C]; O06B *unk1C; } O06A;
extern s32 D_80145070;
extern u8 D_8011FAC0[];
extern void func_0044E9A0(void *a);
s32 func_0043DCE4(s32 a, O06A *b) {
    if (D_80145070 == 1) func_0044E9A0(D_8011FAC0); else b->unk1C->unk5D0 = 0;
    return 1;
}
