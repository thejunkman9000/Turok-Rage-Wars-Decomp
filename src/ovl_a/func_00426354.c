#include "o04_types.h"
void func_00426354(O04Plr *p) {
    s32 i;
    if (p->unk5D8->unk91 == 1) {
        return;
    }
    if (p->unk5D8->unk78 == 0) {
        return;
    }
    for (i = 0; i < 0x16; i++) {
        if (p->unk5D8->u4C[i] == 1) {
            p->unk602[i].a = p->unk5D8->u4C[i];
            p->unk602[i].b = p->unk5D8->u62[i];
        }
    }
}
