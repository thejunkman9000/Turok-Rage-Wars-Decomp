#include "b02_types.h"

s32 func_0020CC0C(B2Mgr *m, s32 x, s32 y);
B2Node *func_0020CFE0(B2Mgr *m, s32 key);
Vec3f *func_0020C994(B2Mgr *m, s32 idx);
extern B2Mgr D_8013B364;
extern f32 D_800C6EA4;

s32 func_0020D6E4(B2Ctl *ctl) {
    B2Mgr *m = &D_8013B364;
    s32 nxt = -1;
    s32 i = 0;
    s32 sel = ctl->unk38;
    Vec3f sum;
    Vec3f *p;
    B2Node *n;
    f32 k;
    f32 zero;
    s32 z;

    z = i;
    for (; i < ctl->unk38; i++) {
        if ((f32)z < ctl->ent[i].w) {
            sel = i;
        }
    }
    if (sel != ctl->unk38) {
        i = 0;
        if (ctl->ent[sel].a < 0) {
            goto fail;
        }
        for (i = 0; i < 3; i++) {
            if (ctl->q[i] == ctl->unk1C0) {
                nxt = ctl->q[i + 1];
                break;
            }
        }
        if (nxt == -1) {
            goto fail;
        }
        if (func_0020CC0C(m, ctl->unk1C0, ctl->ent[sel].a) == -1) {
            goto fail;
        }
        if (func_0020CC0C(m, nxt, ctl->ent[sel].a) == -1) {
            goto fail;
        }
        for (i = 3; i > 0; i--) {
            if (ctl->q[i - 1] == ctl->unk1C0) {
                ctl->q[i] = ctl->ent[sel].a;
                break;
            }
            ctl->q[i] = ctl->q[i - 1];
        }
        zero = 0.0f;
        sum.z = zero;
        sum.y = zero;
        sum.x = zero;
        for (i = 0; i < ctl->unk38; i++) {
            sum.x += ctl->v138[i].x;
            sum.y += ctl->v138[i].y;
            sum.z += ctl->v138[i].z;
        }
        k = D_800C6EA4 / (f32)ctl->unk38;
        sum.x *= k;
        sum.y *= k;
        sum.z *= k;
        n = func_0020CFE0(m, ctl->ent[sel].a);
        sum.x *= n->unk14;
        sum.y *= n->unk14;
        sum.z *= n->unk14;
        p = func_0020C994(m, ctl->ent[sel].a);
        ctl->dst1B0.x = p->x + sum.x;
        ctl->dst1B0.y = p->y + sum.y;
        ctl->dst1B0.z = p->z + sum.z;
        ctl->unk1BC++;
        ctl->nodeId = ctl->ent[sel].a;
        return 0;
    }
fail:
    ctl->unk1C8 = 0;
    ctl->unk1BC += 0x14;
    return 1;
}
