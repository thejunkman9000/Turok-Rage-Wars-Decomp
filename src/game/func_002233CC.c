#include "b05_types.h"

typedef struct B05P15 {
    u8 pad0[0x66C];
    /* 0x66C */ f32 f66C;
    u8 pad670[0x34];
    /* 0x6A4 */ f32 f6A4;
    /* 0x6A8 */ f32 f6A8;
    u8 pad6AC[0x4];
    /* 0x6B0 */ u32 flags6B0;
    u8 pad6B4[0x4];
    /* 0x6B8 */ u32 flags6B8;
    u8 pad6BC[0x4];
    /* 0x6C0 */ f32 f6C0;
    /* 0x6C4 */ f32 f6C4;
    u8 pad6C8[0xC];
    /* 0x6D4 */ f32 f6D4;
    /* 0x6D8 */ f32 f6D8;
    /* 0x6DC */ f32 f6DC;
    u8 pad6E0[0x8];
    /* 0x6E8 */ Vec3f v6E8;
    u8 pad6F4[0xF4];
    /* 0x7E8 */ s32 unk7E8;
    u8 pad7EC[0x9CC];
    /* 0x11B8 */ s32 unk11B8;
} B05P15;

typedef struct B05A15 {
    u8 pad0[0x8];
    /* 0x008 */ Vec3f pos;
    u8 pad14[0x58];
    /* 0x06C */ f32 ang;
} B05A15;

typedef struct B05In15 {
    /* 0x000 */ f32 f0;
    /* 0x004 */ f32 f4;
    /* 0x008 */ f32 f8;
    /* 0x00C */ f32 fC;
    /* 0x010 */ f32 f10;
    /* 0x014 */ f32 f14;
    /* 0x018 */ f32 f18;
    /* 0x01C */ f32 f1C;
    u8 pad20[0x2];
    /* 0x022 */ s16 s22;
} B05In15;

extern f32 D_800C79A4;
extern const f32 D_800C79A8;
extern f32 D_800C79AC;
extern const f32 D_800C79B0;
extern f32 D_800C79B4;
extern const f32 D_800C79B8;
extern f32 D_800C79BC;
extern f32 D_800C79C0;
extern f32 D_800C79C4;
extern const f32 D_800C79C8;
extern f32 D_800C79CC;
extern f32 D_800D2988;

f32 sinf(f32);
f32 cosf(f32);
s32 func_00245774();
void func_0025DE74(s16, f32, f32, f32, s32, s32);
void func_00271FA4(Vec3f *, Vec3f *, Vec3f *);
void func_0027200C(Vec3f *, Vec3f *, f32);
void func_002727B8(Vec3f *, f32);
f32 func_00274710(f32, f32, f32);
f32 func_00274810(f32, f32);

void func_002233CC(B05P15 *p, B05A15 *a, B05In15 *in) {
    Vec3f v;
    f32 t0;
    f32 t1;
    f32 t2;
    f32 t3;
    f32 t4;
    f32 t5;
    f32 lim1;
    f32 lim2;
    f32 lim3;
    f32 m1;
    f32 m2;
    f32 fa1;
    f32 fa1b;
    f32 fv0;
    f32 fv0b;
    f32 a1;
    f32 fv3;
    f32 fv4;
    s32 s3;
    s32 s4;

    if (func_00245774() != 0) {
        return;
    }
    if (p->unk11B8 != 0) {
        return;
    }
    s3 = 0;
    s4 = 1;
    t0 = p->f6DC;
    if (!(t0 <= 0.0f)) {
        s4 = 0;
        p->f6DC = t0 - D_800D2988;
    }
    t1 = p->f6C0;
    lim1 = in->f4;
    if (lim1 < (t1 < 0.0f ? -t1 : t1)) {
        p->f6C0 = func_00274810(p->f6C0, in->f8 * D_800C79A4);
    } else if ((t2 = p->f6A8) != 0.0f && p->unk7E8 != 2) {
        m1 = t2 * in->f0;
        fv0 = (t2 < 0.0f ? -t2 : t2) * in->f4;
        p->f6C0 = func_00274710(p->f6C0, m1, fv0);
    } else {
        p->f6C0 = func_00274810(p->f6C0, in->f8);
    }
    v.x = p->f6C0 * sinf(a->ang + D_800C79A8);
    v.y = 0;
    v.z = p->f6C0 * cosf(a->ang + D_800C79A8);
    t3 = p->f6C4;
    lim3 = in->f10;
    if (lim3 < (t3 < 0.0f ? -t3 : t3)) {
        p->f6C4 = func_00274810(p->f6C4, in->f14 * D_800C79AC);
    } else if ((t4 = p->f6A4) != 0.0f) {
        m2 = t4 * in->fC;
        fv0b = (t4 < 0.0f ? -t4 : t4) * in->f10;
        p->f6C4 = func_00274710(p->f6C4, m2, fv0b);
    } else {
        p->f6C4 = func_00274810(p->f6C4, in->f14);
    }
    v.x += p->f6C4 * sinf(a->ang - D_800C79B0);
    v.z += p->f6C4 * cosf(a->ang - D_800C79B0);
    t5 = p->f6C4;
    if (t5 < 0.0f) {
        t5 = -t5;
    }
    t1 = p->f6C0;
    if (t1 < 0.0f) {
        if (-t1 < t5) goto b35;
        goto b36;
    }
    if (t1 < t5) {
b35:
        func_002727B8(&v, in->f10);
    } else {
b36:
        func_002727B8(&v, in->f4);
    }
    if (s4 != 0) {
        if (p->flags6B0 & 8) {
            fv3 = in->f18;
            s3 = 1;
        } else if (p->flags6B0 & 4) {
            fv3 = -in->f18 * D_800C79B4;
            s3 = 1;
        } else {
            goto b42;
        }
    } else {
b42:
        fv3 = func_00274810(p->f6D4, in->f1C);
    }
    p->f6D4 = fv3;
    v.x += p->f6D4 * sinf(a->ang + D_800C79B8);
    v.z += p->f6D4 * cosf(a->ang + D_800C79B8);
    if (s4 != 0) {
        if (p->flags6B8 & 1) {
            p->f6D8 = in->f18 * D_800C79BC;
            s3 = 1;
        } else if (p->flags6B8 & 2) {
            p->f6D8 = -in->f18 * D_800C79C0;
            s3 = 1;
        } else {
            goto b48;
        }
    } else {
b48:
        p->f6D8 = func_00274810(p->f6D8, in->f1C * D_800C79C4);
    }
    v.x += p->f6D8 * sinf(a->ang - D_800C79C8);
    v.z += p->f6D8 * cosf(a->ang - D_800C79C8);
    func_0027200C(&v, &v, p->f66C);
    func_00271FA4(&p->v6E8, &p->v6E8, &v);
    if (s3 != 0) {
        p->f6DC = p->f6DC + D_800C79CC;
        func_0025DE74(in->s22, a->pos.x, a->pos.y, a->pos.z, 0, -1);
    }
}
