#include "m04_types.h"

typedef struct M04Info {
    /* 0x00 */ u8 pad0[6];
    /* 0x06 */ u16 bits6;
    /* 0x08 */ u8 pad8[2];
    /* 0x0A */ s16 envId;
    /* 0x0C */ u8 padC[4];
    /* 0x10 */ s16 v10;
} M04Info;

extern f32 D_800C8FFC;
extern f32 D_800C9000;
extern f32 D_800C9004;
extern f32 D_800C9008;
extern f32 D_800C900C;
extern f32 D_800D0B2C[];
f32 Trunc16ToF32(u16 x);
u16 F32ToTrunc16(f32 x);
M04Rec12 *func_00258BFC(M04Ctx *c, s16 id);
s32 func_0025E5A4(M04Info *r);
s32 func_0025E5B0(M04Info *r);
f32 func_00274B00(f32 a, f32 b);

void func_00259C7C(M04Emitter *o, M04Info *rec, u32 flags) {
    M04VP *vp = &o->vp;
    M04Rec12 *env = &o->env;
    s32 a;
    s32 b;
    s16 d;
    s32 n;
    s16 k;
    f32 fa;
    f32 fb;
    f32 r;
    f32 x;
    vp->f48 = vp->f4C = 0.0f;
    if (rec->envId != -1) {
        *env = *func_00258BFC(o->ctx, rec->envId);
    } else {
        env->w0 = F32ToTrunc16((f32)rec->v10);
    }
    a = func_0025E5A4(rec);
    b = func_0025E5B0(rec);
    if (func_00274B00((f32)(s16)b, (f32)(s16)a) < 0.0f) {
        r = (f32)(s16)a - func_00274B00((f32)(s16)b, (f32)(s16)a);
    } else {
        r = (f32)(s16)a + func_00274B00((f32)(s16)b, (f32)(s16)a);
    }
    d = (s32)r;
    env->w0 = F32ToTrunc16(Trunc16ToF32(env->w0) + (f32)d);
    if (flags & 0x40) {
        env->w0 = F32ToTrunc16(Trunc16ToF32(env->w0) + D_800C8FFC);
    }
    if (flags & 0x80) {
        env->w0 = F32ToTrunc16(Trunc16ToF32(env->w0) - D_800C9000);
    }
    if (D_800C9004 <= Trunc16ToF32(env->w0)) {
        env->w0 = F32ToTrunc16(D_800C9004);
    }
    if (rec->bits6 & 2) {
        vp->v14.f = Trunc16ToF32(env->w0);
        fa = Trunc16ToF32(env->w1);
        fa -= Trunc16ToF32(env->w2);
        if (env->w3 == 0) {
            o->envSlope0 = 0.0f;
        } else {
            o->envSlope0 = fa / (f32)env->w3;
        }
        o->envA = Trunc16ToF32(env->w1);
    }
    x = (Trunc16ToF32(env->w0) + D_800C9008) * D_800C900C;
    n = (s32)x;
    k = n;
    if ((f32)k != x) {
        r = D_800D0B2C[k] + (x - (f32)k) * (D_800D0B2C[(s16)(n + 1)] - D_800D0B2C[k]);
    } else {
        r = D_800D0B2C[k];
    }
    vp->v14.f = r;
    env->w0 = F32ToTrunc16(r);
}
