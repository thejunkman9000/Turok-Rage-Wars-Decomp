#include "m01_types.h"

typedef struct Blk50 { s32 w[20]; } Blk50;
extern f32 D_800C7258;
extern u8 D_80104030[];
extern M1Actor *D_801041F0;
extern u8 D_80145040[];

s32 func_00214624(M1Actor *a, M1Ctl *c, M1Actor *t);
f32 func_00217224(M1Actor *t, Vec3f pos);
f32 func_00217290(M1Actor *t, Vec3f pos);
M1Actor *func_0022A470(u8 *w, Vec3f pos);
M1Actor *func_0022A4F4(u8 *w, Vec3f pos, M1Actor *o);
s32 func_00244494(M1Actor *a, Vec3f pos, Vec3f target, u8 *out);
s32 func_00245788();
s32 func_00245AFC(void);
f32 func_0024D274(M1Actor *a);
s32 func_0024DE5C(M1Actor *a);
f32 func_0024E560(M1Actor *a);
void func_0024E7CC(M1Actor *a);

M1Actor *func_002149C0(M1Actor *actor, M1Ctl *ctl, s32 arg2, s32 flag) {
    M1Actor *list[128];
    Blk50 saved;
    Vec3f tpos;
    f32 best;
    f32 d;
    f32 fs0, fs0f;
    M1Actor *best_a;
    M1Actor *t;
    M1Actor *c;
    s32 n;
    s32 i;
    s32 ok;
    s32 r;

    if (ctl->unk78 != NULL) {
        if (flag != 0) {
            func_00214624(actor, ctl, ctl->unk78);
        }
        return ctl->unk78;
    }
    n = 0;
    best_a = NULL;
    ok = 1;
    if (func_00245788() != 0) {
        ok = 0;
        if (func_00245AFC() >= 10) {
            ok = func_00245AFC() < 61;
        }
    }
    if (ok) {
        if (flag != 0) {
            c = ctl->unk68;
            if (c != NULL) {
                list[n] = c;
                n++;
            }
        }
        if (!(actor->def->unk4 & 0x400)) {
            if (actor->flags & 0x300000) {
                c = func_0022A4F4(D_80145040, actor->pos, actor->owner);
            } else {
                c = func_0022A470(D_80145040, actor->pos);
            }
            if (c != NULL && c->h5EA != 0 && c->h650 != 1) {
                func_0024E7CC(c);
                if (c != NULL) {
                    list[n] = c;
                    n++;
                }
            }
        }
        best = D_800C7258;
        i = 0;
        best_a = NULL;
        if (n > 0) {
            do {
                t = list[i];
                d = func_00217224(t, actor->pos);
                if (d < best) {
                    if (flag != 0) {
                        if (actor->def->kind == 1 && ctl->b37 == 0) goto next;
                        if (func_0024DE5C(actor) != 0) {
                            fs0f = func_00217290(t, ctl->vB0);
                            fs0 = func_0024E560(actor);
                            fs0 = fs0 * func_0024E560(actor);
                            if (fs0 <= fs0f) goto next;
                        }
                        if (func_00214624(actor, ctl, t) == 0) goto next;
                    }
                    if (arg2 != 0) {
                        saved = *(Blk50 *)actor;
                        actor->pos.y = actor->pos.y + func_0024D274(actor);
                        actor->pos.y = actor->pos.y + t->f70;
                        tpos = t->pos;
                        tpos.y = tpos.y + func_0024D274(t);
                        tpos.y = tpos.y + t->f70;
                        r = func_00244494(actor, actor->pos, tpos, D_80104030);
                        if (D_801041F0 == t) {
                            r = 0;
                        }
                        *(Blk50 *)actor = saved;
                        if (r != 0) goto next;
                    }
                    best = d;
                    best_a = t;
                }
next:
                i++;
            } while (i < n);
        }
    }
    if (flag != 0 && best_a == NULL && func_00214624(actor, ctl, NULL) == 0) {
        ctl->vB0 = actor->pos;
        ctl->unkBC = actor->unk14;
    }
    return best_a;
}
