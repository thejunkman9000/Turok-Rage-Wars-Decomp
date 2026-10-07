#include "o06_types.h"
typedef struct { u8 pad[0xB0]; u32 unkB0; } O06B;
typedef struct { u8 pad[0x20]; O06B *unk20; } O06A;
extern s32 D_800E63B8;
extern void func_0025E2F4(s32 a);
s32 func_00445E28(s32 a, O06A *b) {
    s32 v = D_800E63B8;
    if (b->unk20->unkB0 & 0x20202) {
        v--;
        if (v < 0) v = 0x16; else if (v == 0xE) v = 0xB;
    }
    if (b->unk20->unkB0 & 0x4D101) {
        v++;
        if (v >= 0x17) v = 0; else if (v == 0xC) v = 0xF;
    }
    D_800E63B8 = v;
    func_0025E2F4(v);
    return 0;
}
