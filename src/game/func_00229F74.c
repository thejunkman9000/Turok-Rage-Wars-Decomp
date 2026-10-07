#include "b06_types.h"

extern f32 D_800C7DB4;
extern f32 D_800C7DB8;
extern f32 D_800C7DBC;
extern f32 D_800C7DC0;
extern f32 D_800C7DC4;
extern f32 D_800C7DC8;
extern f32 D_800C7DCC;
extern f32 D_800C7DD0;
extern GameB6 D_801468A0[];

void func_00229F74(Plr *a, HitB6 *b) {
    Plr *tgt = NULL;
    Plr *o;
    Plr *o2;
    f32 x;
    f32 y;
    o = b->unk0;
    if (o != NULL) {
        if (o->unk0 != 1) {
            if (o->unk0 == 2) {
                o2 = o->unk12C;
                if (o2 != NULL && o2->unk0 == 1) {
                    if (o2->flags100 & 0x300000) {
                        tgt = o2;
                        if (tgt == a) {
                            b->unk4 = (s32)((f32)b->unk4 * D_800C7DB4 * D_800C7DB8 * D_800C7DBC);
                        }
                    } else if (o2->unkE4 == 0x40C) {
                        tgt = o2->unk1D8;
                    }
                }
            }
        } else if (o->flags100 & 0x300000) {
            tgt = o->unk1D8;
        }
    } else {
        tgt = a;
    }
    if (tgt != NULL) {
        if (tgt->unk1450 != 0) {
            switch (tgt->stats->unk93) {
            case 2:
                break;
            default:
                tgt->stats->unk93 = 0;
            case 0:
                x = (f32)b->unk4 * D_800C7DC0;
                y = D_800C7DC4;
                x = x * y;
                goto common;
            case 1:
                x = (f32)b->unk4 * D_800C7DC8;
                y = D_800C7DCC;
                x = x * y;
common:
                b->unk4 = (s32)(x * D_800C7DD0);
                break;
            }
        }
        if (D_801468A0->unk24 != 0 && ((u8 *)D_801468A0)[-0x5B0] == 0 && (tgt->unk1450 == 0 || a->unk1450 == 0) && a->stats->unk92 == tgt->stats->unk92) {
            b->unk4 = 0;
        }
    }
}
