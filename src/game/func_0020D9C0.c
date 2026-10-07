#include "b02_types.h"

Vec3f *func_0020C994(B2Mgr *m, s32 idx);
B2Node *func_0020CFE0(B2Mgr *m, s32 key);
extern B2Mgr D_8013B364;
extern f32 D_800C6EA8;

s32 func_0020D9C0(B2Ctl *ctl) {
    B2Mgr *m = &D_8013B364;
    Vec3f sum;
    Vec3f *p;
    B2Node *n;
    f32 k;
    s32 i;
    f32 zero = 0.0f;

    sum.z = zero;
    sum.y = zero;
    sum.x = zero;
    for (i = 0; i < ctl->unk38; i++) {
        sum.x += ctl->v138[i].x;
        sum.y += ctl->v138[i].y;
        sum.z += ctl->v138[i].z;
    }
    if (ctl->unk38 == 0) {
        return 1;
    }
    k = D_800C6EA8 / (f32)ctl->unk38;
    sum.x *= k;
    sum.y *= k;
    sum.z *= k;
    n = func_0020CFE0(m, ctl->nodeId);
    sum.x *= n->unk14;
    sum.y *= n->unk14;
    sum.z *= n->unk14;
    p = func_0020C994(m, ctl->nodeId);
    ctl->dst1B0.x = p->x + sum.x;
    ctl->dst1B0.y = p->y + sum.y;
    ctl->dst1B0.z = p->z + sum.z;
    return 1;
}
