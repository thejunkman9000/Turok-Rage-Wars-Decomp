#include "b24_types.h"

void func_002A8170(AnimSlot *s, AnimCtl *c) {
    s->unk4 = (s->unk4 == 0);
    if (s->unk4 != 0) {
        s->unk18 = 5;
        s->unk1C = c->unkE8;
        s->unk20 = s->unk28;
        s->unk24 = s->unk2C;
    } else {
        s->unk18 = -5;
    }
}
