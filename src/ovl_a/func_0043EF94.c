#include "o06_types.h"
typedef struct { u8 pad[0x10]; f32 unk10; } O06G;
extern O06G D_801468A0[];
extern f32 D_800D2988;
s32 func_0043EF94(void) {
    f32 v = D_801468A0->unk10 - D_800D2988;
    D_801468A0->unk10 = v;
    if (v < 0.0f) D_801468A0->unk10 = 0.0f;
    return 0;
}
