#include "b24_types.h"

static inline void clr(AnimSlot *s) {
    s->unk4 = 0;
    s->unk0 = 0;
    s->unkD = 0;
    s->unk18 = 0;
    s->unk1C = 0;
}

void func_002A7F58(AnimCtl *c) {
    s32 i;
    for (i = 0; i < 4; i++) {
        clr(&c->slot[i]);
    }
    c->unk0 = 0;
    c->unk1 = 0;
    c->cur = 0;
    c->unkE6 = -5;
    c->unkE8 = 0;
}
