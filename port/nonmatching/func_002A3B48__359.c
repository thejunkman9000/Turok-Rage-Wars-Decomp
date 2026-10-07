#include "p1_types.h"

typedef struct VDef {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ f32 f4;
    /* 0x08 */ f32 f8;
} VDef;

typedef struct VObj {
    /* 0x00 */ u8 pad0[8];
    /* 0x08 */ VDef *def;
    /* 0x0C */ u8 padC[0x18];
    /* 0x24 */ f32 f24;
} VObj;

typedef struct VInfo2 {
    u8 pad0[8];
    f32 f8;
} VInfo2;

typedef struct VEnt {
    u8 a0;
    u8 c0[3];
    u8 a1;
    u8 c1[3];
    u16 i0;
    u16 i1;
} VEnt;

typedef struct VAnim {
    /* 0x00 */ s32 n;
    /* 0x04 */ VEnt *ents;
    /* 0x08 */ u8 *tabA;
    /* 0x0C */ u8 *tabC;
    /* 0x10 */ s32 u10;
    /* 0x14 */ s32 u14;
    /* 0x18 */ f32 f18;
    /* 0x1C */ f32 f1C;
    /* 0x20 */ f32 f20;
} VAnim;

typedef struct V3 { f32 x, y, z; } V3;

float cosf(float);
void func_0027200C(V3 *dst, void *src, s32 arg);
s32 func_0026E340();

void func_002A3B48(VObj *o, VInfo2 *info, s16 *out, f32 scale, VAnim *an) {
    f32 acc;
    V3 a, b;
    f32 t, t2, u;
    s32 n;
    VEnt *e;
    u8 *o8;
    u8 *pc;
    u32 v;

    t = 0.5f - cosf(info->f8 / o->def->f8 * 3.14159274f) * 0.5f;
    if (o->f24 <= o->def->f4) {
        t2 = 0.5f - cosf(o->f24 / o->def->f4 * 3.14159274f) * 0.5f;
        t = t * t2;
    }
    n = an->n;
    e = an->ents;
    n--;
    t = 1.0f - t;
    acc = 0.0f;
    o8 = (u8 *)out;
    for (; n != -1; n--) {
        func_0027200C(&a, an->tabA + e->i0 * 20, an->u10);
        func_0027200C(&b, an->tabC + e->i1 * 20, an->u14);
        out[0] = (s32)(a.x + t * (b.x - a.x));
        out[1] = (s32)(a.y + t * (b.y - a.y));
        out[2] = (s32)(a.z + t * (b.z - a.z));
        out[4] = (s32)(an->f18 * scale);
        out[5] = (s32)(an->f1C * acc);
        if (func_0026E340() != 0) {
            v = (u32)((f32)(e->c0[0] + e->c0[1] + e->c0[2]) + t * (f32)((e->c1[0] - e->c0[0]) + (e->c1[1] - e->c0[1]) + (e->c1[2] - e->c0[2])));
            o8[0xC] = 0;
            o8[0xD] = 0;
            o8[0xE] = v / 3;
            o8[0xF] = (u32)((f32)e->a0 + t * (f32)(e->a1 - e->a0));
        } else {
            o8[0xC] = (u32)((f32)e->c0[0] + t * (f32)(e->c1[0] - e->c0[0]));
            o8[0xD] = (u32)((f32)e->c0[1] + t * (f32)(e->c1[1] - e->c0[1]));
            o8[0xE] = (u32)((f32)e->c0[2] + t * (f32)(e->c1[2] - e->c0[2]));
            o8[0xF] = (u32)((f32)e->a0 + t * (f32)(e->a1 - e->a0));
        }
        e++;
        o8 += 0x10;
        out += 8;
        acc += an->f20;
    }
}
