#include "b24_types.h"

typedef struct Sub24 {
    u8 pad0[0x124];
    s16 unk124;
} Sub24;

typedef struct Plr24b {
    u8 pad0[0x5DC];
    Sub24 *unk5DC;
    u8 pad5E0[0x10F4];
    s32 unk16D4;
} Plr24b;

f32 func_002745D4(f32);
void func_0023919C(Sub24 *, s32, s32, s32, s32, s32, s32, s32);

s32 func_002AE1A4(Plr24b *p) {
    Sub24 *q;
    u32 v;
    q = p->unk5DC;
    p->unk16D4 = (p->unk16D4 == 0);
    if (q != NULL) {
        q->unk124 = 0;
        v = (u32)func_002745D4(0.015000001f);
        func_0023919C(p->unk5DC, 0xFF, 0xFF, 0xFF, 0xFF, (u8)v, 1, 0);
    }
    return 1;
}
