#include "m04_types.h"

extern f32 D_800C9050;
extern f32 D_800C9054;
extern f32 D_800D0B2C[];
f32 Trunc16ToF32(u16 x);
void alSndpSetSound(void *p, s16 id);
void alSndpSetPitch(void *p, f32 pitch);
void func_0025AA4C(M04Emitter *o);

void func_0025ABB4(M04Emitter *o) {
    s32 flag;
    M04VP *vp;
    M04Rec12 *env;
    M04Ctx *c;
    s32 neg;
    s32 n;
    s16 k;
    f32 x;
    f32 fs;
    flag = 0;
    vp = &o->vp;
    env = &o->env;
    if ((o->flags & 0x400) && !(o->ctx->unk104 & 3)) {
        flag = 1;
        func_0025AA4C(o);
    }
    if ((o->flags & 0xA) == 0xA) {
        if (*(s16 *)&env->w4 > 0) {
            env->w4 = env->w4 - 1;
            goto fin;
        }
        neg = 0;
        if (o->envSlope0 < 0.0f) {
            neg = 1;
        }
        if (neg) {
            if (o->envA < Trunc16ToF32(env->w2)) {
                goto blk;
            }
            goto fin;
        }
        if (Trunc16ToF32(env->w2) < o->envA) {
blk:
            o->envA = o->envA - o->envSlope0;
            if (neg) {
                if (Trunc16ToF32(env->w2) < o->envA) {
                    o->envA = Trunc16ToF32(env->w2);
                }
            } else {
                if (o->envA < Trunc16ToF32(env->w2)) {
                    o->envA = Trunc16ToF32(env->w2);
                }
            }
            x = (o->envA + D_800C9050) * D_800C9054;
            n = (s32)x;
            k = n;
            if ((f32)k != x) {
                fs = D_800D0B2C[k] + (x - (f32)k) * (D_800D0B2C[(s16)(n + 1)] - D_800D0B2C[k]);
            } else {
                fs = D_800D0B2C[k];
            }
            vp->v14.f = fs;
            c = o->ctx;
            alSndpSetSound(c->player, c->snd[o->w0]);
            alSndpSetPitch(c->player, fs * vp->f24 * o->unkB8);
            return;
        }
    }
fin:
    if (flag != 0) {
        c = o->ctx;
        fs = vp->v14.f;
        alSndpSetSound(c->player, c->snd[o->w0]);
        alSndpSetPitch(c->player, fs * vp->f24 * o->unkB8);
    }
}
