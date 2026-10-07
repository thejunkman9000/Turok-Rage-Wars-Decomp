


#include "m04_types.h"

typedef struct M04Info {
    /* 0x00 */ u8 pad0[6];
    /* 0x06 */ u16 bits6;
    /* 0x08 */ s16 envId;
    /* 0x0A */ u8 padA[5];
    /* 0x0F */ s8 b0F;
} M04Info;

typedef struct M04Tab {
    f32 key;
    f32 val;
} M04Tab;

extern f32 D_800C9010;
extern f32 D_800C9014;
extern f32 D_800C9018;
extern f32 D_800C901C;
extern f32 D_800C9020;
extern f32 D_800C9024;
extern f32 D_800D0D10;
extern M04Tab D_800D0A30[];
extern u8 D_8010BFA0[];
f32 Trunc16ToF32(u16 x);
u16 F32ToTrunc16(f32 x);
s32 func_00245788();
M04Rec12 *func_00258BE4(M04Ctx *c, s16 id);
f32 func_002745D4(f32 x);

void func_00259F88(M04Emitter *o, M04Info *rec) {
    M04VP *vp = &o->vp;
    M04Rec12 *env;
    u8 *pp;
    s32 i;
    s32 kind;
    s32 n;
    s32 t;
    f32 vf;
    f32 a;
    f32 b;
    f32 f;
    f32 fs;
    M04Vec3 *p;
    M04Vec3 *q;
    pp = o->ctx->tab2B88;
    o->unkC8 = D_800C9010;
    if (o->kind < 0x100) {
        for (i = 0; i < 0x1F; i++) {
            if (o->kind == (s32)D_800D0A30[i].key) {
                o->unkC8 = D_800D0A30[i].val;
                break;
            }
        }
    }
    if (func_00245788() != 0) {
        o->unkC8 = o->unkC8 * D_800C9014;
    }
    env = &o->env2;
    if (rec->envId != -1) {
        *env = *func_00258BE4(o->ctx, rec->envId);
    } else {
        env->w0 = F32ToTrunc16((f32)rec->b0F);
    }
    if (!(rec->bits6 & 0x800) && o->resetFlag != 1 && o->ctx->tgt != 0) {
        a = (f32)pp[0] * D_800C9018;
        b = (f32)pp[1] * D_800C9018;
        if (a == D_800C901C) {
            vf = D_800C901C;
        } else if (b == a) {
            vf = a;
        } else {
            vf = a + func_002745D4(b - a);
        }
        p = &vp->pos;
        q = (M04Vec3 *)&o->ctx->tgt->x;
        {
            f32 d2 = (p->x - q->x) * (p->x - q->x) + (p->y - q->y) * (p->y - q->y) + (p->z - q->z) * (p->z - q->z);
            if (D_800D0D10 <= d2) {
                f = 0.0f;
            } else {
                f = D_800C9020 - d2 / D_800D0D10;
            }
        }
        switch (vp->mode) {
        case 2:
            vp->scale = f;
            break;
        case 0:
            f = f * f;
            f = f * f;
        case 1:
            f = f * f;
            vp->scale = f;
            break;
        default:
            f = 0.0f;
            vp->scale = 0.0f;
            break;
        }
        vp->f20 = f;
    } else {
        vf = D_800C9024;
        vp->scale = vf;
        vp->f20 = vf;
    }
    if (rec->bits6 & 4) {
        vp->vol = (s32)Trunc16ToF32(env->w0);
        fs = Trunc16ToF32(env->w1);
        fs -= Trunc16ToF32(env->w2);
        if (env->w3 == 0) {
            o->env2Slope = 0.0f;
        } else {
            o->env2Slope = fs / (f32)env->w3;
        }
        o->env2A = Trunc16ToF32(env->w1);
        n = (s32)Trunc16ToF32(env->w0);
        if ((f32)n < 0.0f) {
            t = -n * 2;
        } else {
            t = n * 2;
        }
        vp->vol = (s32)((f32)(s32)((f32)*(s16 *)(D_8010BFA0 + t) * o->env2A) * vf);
        if ((f32)n < 0.0f) {
            t = -n * 2;
        } else {
            t = n * 2;
        }
        env->w0 = F32ToTrunc16((f32)*(s16 *)(D_8010BFA0 + t) * vf);
        vp->wC = (s32)Trunc16ToF32(env->w0 & 0xFFFF);
        return;
    }
    n = (s32)Trunc16ToF32(env->w0);
    if ((f32)n < 0.0f) {
        t = -n * 2;
    } else {
        t = n * 2;
    }
    t = (s32)((f32)*(s16 *)(D_8010BFA0 + t) * vf);
    vp->vol = t;
    vp->wC = t;
}



