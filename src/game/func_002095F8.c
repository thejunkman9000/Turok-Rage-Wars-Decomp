#include "b02_types.h"

void func_0022B134(B2Actor *a, Vec3f *out);
f32 func_0029D044(f32 a, f32 b);
extern s32 D_801468F4;

void func_002095F8(B2Ctl *ctl) {
    Vec3f p;
    Vec3f q;
    B2Actor *t;
    f32 h0;
    f32 h1;
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
        do {
            h1 *= 0.9f;
            if (D_801468F4 != 0 && t->stats->unk8F != 0) {
                h1 *= 0.7f;
            }
        } while (0);
        h1 -= h0;
        q = ctl->v258;
        q.x -= p.x;
        q.y -= p.y;
        q.z -= p.z;
        ctl->unk264 = sqrtf(q.x * q.x + q.y * q.y + q.z * q.z);
        /* HACK: empty asm = full scheduling barrier (volatile asm clobbers everything in sched_analyze): keeps
           h1 -= h0 (the sub.s above) in front of the first sqrtf call as in the ROM */
        asm("");
        hv = q.y;
        q.y = 0.0f;
        z = q.y;
        hv += h1;
        horiz = sqrtf(q.x * q.x + q.z * q.z);
        if (horiz == z) {
            if (hv < z) {
                ctl->unk248 = -90.0f;
            } else {
                ctl->unk248 = 90.0f;
            }
        } else {
            ctl->unk248 = func_0029D044(hv, horiz) * 57.295776f;
        }
    } else {
        ctl->unk248 = 0.0f;
    }
    ctl->unk24C = ctl->unk248;
}
