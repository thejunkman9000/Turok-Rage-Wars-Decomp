#include "b02_types.h"

extern f32 D_800C6E88;
extern f32 D_800C6E8C;

void func_0020D014(B2Mgr *m) {
    B2Node *n;

    for (n = m->head; n != NULL; n = n->next) {
        n->unk4 = D_800C6E88;
        n->unk8 = -1;
        n->unk18 = 0;
        n->unk1C = 0;
        n->unk20 = 0;
        n->unk24 = 0;
        n->unk28 = 0;
        n->unk2C = 0;
        n->link30 = NULL;
    }
    m->unk1C = D_800C6E8C;
    m->unk20 = -1;
}
