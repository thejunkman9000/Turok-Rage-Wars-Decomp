#include "b02_types.h"

s32 func_00274544(void);

static inline B2Rec *getRec0(B2Mgr *m, s32 idx) {
    B2Pool *pool = m->pool0;

    return (B2Rec *)&pool->data[idx * pool->elemSize];
}

extern B2Mgr D_8013B364;
extern f32 D_800C6E7C;
extern f32 D_800C6E80;

void func_0020CA10(B2Node *n, s32 idx) {
    B2Rec *r;

    n->id = idx;
    n->unk8 = -1;
    n->unkC = 0;
    n->next = NULL;
    n->unk4 = D_800C6E7C;
    r = getRec0(&D_8013B364, idx);
    if (r->flags & 2) {
        n->unk14 = D_800C6E80;
    }
    n->unk34 = 0;
    n->unk38 = 0;
    n->unk3C = 0;
    n->unk40 = NULL;
    n->v44.x = 0;
    n->v44.y = 0;
    n->v44.z = 0;
    if (r->flags & 0x40) {
        n->unk38 = func_00274544() % 5 + 5;
    }
    if (r->flags & 0x80) {
        n->unk3C = func_00274544() % 5 + 5;
    }
}
