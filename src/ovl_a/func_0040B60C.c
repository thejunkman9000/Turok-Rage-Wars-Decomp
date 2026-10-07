#include "o01_types.h"

typedef struct O01Plr {
    /* 0x000 */ u8 pad0[0x5DC];
    /* 0x5DC */ u8 *unk5DC;
} O01Plr;
typedef struct O01Sub3 {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ s8 unk4;
} O01Sub3;
typedef struct O01Own3 {
    /* 0x00 */ u8 pad0[0x1C];
    /* 0x1C */ O01Plr *unk1C;
    /* 0x20 */ O01Sub3 *unk20;
    /* 0x24 */ s32 unk24;
} O01Own3;
extern s32 D_8015375C;
extern s32 D_800E28C8;
extern s32 D_80153784;
extern u8 D_8014561C[];
s32 func_00406178(O01Own3 *o, s32 pad, s32 z);
void func_004426E4(u8 *a, void *b, void *c, void *d, s32 e);

s32 func_0040B60C(O01Item *item, O01Own3 *o) {
    s32 pad;
    u8 *p;
    if (D_8015375C != 0) {
        pad = D_800E28C8;
    } else {
        pad = o->unk20->unk4;
    }
    do {
        D_80153784 = 1;
        if (func_00406178(o, pad, 1) != 0) {
            if (o->unk1C != 0) {
                p = o->unk1C->unk5DC + 0x554;
            } else {
                p = D_8014561C;
            }
            func_004426E4(p, (void *)o->unk24, o->unk1C, o->unk20, 0);
        } else {
            func_004426E4(D_8014561C, (void *)o->unk24, o->unk1C, o->unk20, 0);
        }
        return 1;
    } while (0);
}
