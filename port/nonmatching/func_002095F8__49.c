#include "b02_types.h"

void func_0022B134(B2Actor *a, Vec3f *out);
f32 func_0029D044(f32 a, f32 b);
extern f32 D_800C6D64;
extern f32 D_800C6D68;
extern f32 D_800C6D6C;
extern f32 D_800C6D70;
extern f32 D_800C6D74;
extern s32 D_801468F4;

void func_002095F8(B2Ctl *ctl) {
    Vec3f p;
    Vec3f q;
    B2Actor *t;
    f32 h0;
    f32 h1;
    f32 qy;
    f32 hv;
    f32 horiz;
    f32 z;

    if (ctl->target != NULL) {
        p = ctl->owner->pos;
        func_0022B134(ctl->owner, &q);
        h0 = q.y - ctl->owner->pos.y;
        t = ctl->target->owner;
        if (t->unk1450 != 0) {
            func_0022B134(t, &q);
            h1 = q.y - t->pos.y;
        } else {
            h1 = t->pawn->f12C - t->pos.y;
        }
        h1 *= D_800C6D64;
        if (D_801468F4 != 0 && t->stats->unk8F != 0) {
            h1 *= D_800C6D68;
        }
        q = ctl->v258;
        q.x -= p.x;
        q.y -= p.y;
        q.z -= p.z;
        h1 -= h0;
        ctl->unk264 = sqrtf(q.x * q.x + q.y * q.y + q.z * q.z);
        qy = q.y;
        q.y = 0.0f;
        z = q.y;
        hv = qy + h1;
        horiz = sqrtf(q.x * q.x + q.z * q.z);
        if (horiz == z) {
            if (hv < z) {
                ctl->unk248 = D_800C6D6C;
            } else {
                ctl->unk248 = D_800C6D70;
            }
        } else {
            ctl->unk248 = func_0029D044(hv, horiz) * D_800C6D74;
        }
    } else {
        ctl->unk248 = 0.0f;
    }
    ctl->unk24C = ctl->unk248;
}
