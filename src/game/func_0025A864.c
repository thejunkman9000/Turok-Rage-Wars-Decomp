

#include "m04_types.h"

f32 Trunc16ToF32(u16 x);
void alSndpSetSound(void *p, s16 id);
void alSndpSetPan(void *p, s32 pan);
s32 func_00258D4C(M04Ctx *c);
s32 func_00259B30(f32 *pos, M04Tgt *t);

void func_0025A864(M04Emitter *o) {
    M04VP *vp;
    s32 neg;
    u8 pan;
    u8 *pl;
    M04Ctx *c;
    vp = &o->vp;
    if (func_00258D4C(o->ctx) == 0) {
        c = o->ctx;
        alSndpSetSound(c->player, c->snd[o->w0]);
        alSndpSetPan(c->player, 0x40);
        return;
    }
    if (o->hasEnv != 0) {
        if (*(s16 *)&o->rec.w4 > 0) {
            o->rec.w4 = o->rec.w4 - 1;
        } else {
            neg = 0;
            if (o->envSlope < 0.0f) {
                neg = 1;
            }
            if (neg) {
                if (o->env0 < Trunc16ToF32(o->rec.w2)) {
                    goto blk;
                }
            } else if (Trunc16ToF32(o->rec.w2) < o->env0) {
blk:
                o->env0 = o->env0 - o->envSlope;
                if (neg) {
                    if (Trunc16ToF32(o->rec.w2) < o->env0) {
                        o->env0 = Trunc16ToF32(o->rec.w2);
                    }
                } else {
                    if (o->env0 < Trunc16ToF32(o->rec.w2)) {
                        o->env0 = Trunc16ToF32(o->rec.w2);
                    }
                }
            }
        }
        vp->pan = (s32)o->env0;
        goto setpan;
    }
    if ((o->flags & 0x400) && o->resetFlag == 0) {
        vp->pan = func_00259B30((f32 *)((u8 *)o + 0x44), o->ctx->tgt);
setpan:
        pan = ((u8 *)&vp->pan)[1];
        pl = o->ctx->player;
        alSndpSetSound(pl, o->ctx->snd[o->w0]);
        alSndpSetPan(pl, pan);
        return;
    }
    vp->pan = 0x40;
}

