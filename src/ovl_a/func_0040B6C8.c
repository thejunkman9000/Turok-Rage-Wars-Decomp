#include "o01_types.h"

typedef struct O01Plr {
    /* 0x000 */ u8 pad0[0x5DC];
    /* 0x5DC */ u8 *unk5DC;
} O01Plr;
typedef struct O01Own2 {
    /* 0x00 */ u8 pad0[0x1C];
    /* 0x1C */ O01Plr *unk1C;
    /* 0x20 */ void *unk20;
    /* 0x24 */ s32 unk24;
} O01Own2;
extern s32 D_8015375C;
extern s32 D_800E28C0;
extern s32 D_80153710;
extern s32 D_8014ADA0;
extern u8 D_8014561C[];
void func_004426E4(u8 *a, s32 b, void *c, void *d, s32 e);

s32 func_0040B6C8(O01Item *item, O01Own2 *own) {
    u8 *p;
    D_800E28C0 = 1;
    D_80153710 = 0;
    if (D_8015375C != 0) {
        D_8014ADA0 = 1;
    } else {
        if (own->unk1C != 0) {
            p = own->unk1C->unk5DC + 0x554;
        } else {
            p = D_8014561C;
        }
        func_004426E4(p, own->unk24, own->unk1C, own->unk20, 0);
    }
    return 1;
}
