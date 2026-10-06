#include "b24_types.h"

s32 func_002A7FA8(AnimCtl *c, s32 a1, s32 key, s32 a3, s32 a4, f32 a5, s32 a6, s32 a7, s32 a8) {
    s32 i;
    AnimSlot *s;
    for (i = 0; i < 4; i++) {
        if (c->slot[i].unk0 != 0 && c->slot[i].unkC == (key & 0xFFFF)) {
            break;
        }
    }
    if (i == 4) {
        for (i = 0; i < 4; i++) {
            if (c->slot[i].unk0 == 0) {
                break;
            }
        }
        if (i == 4) {
            return 0;
        }
    }
    s = &c->slot[i];
    c->cur = i;
    s->unk0 = 1;
    s->unk8 = a1;
    s->unkC = key;
    s->unk10 = a3;
    s->unk14 = a4;
    s->unk28 = a5;
    s->unk2C = a6;
    s->unk30 = a7;
    s->unkD += 1;
    s->unk34 = a8;
    return 1;
}
