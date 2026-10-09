#include "b05_types.h"

typedef struct B05P17 {
    u8 pad0[0x650];
    /* 0x650 */ s16 state;
    u8 pad652[0x1A];
    /* 0x66C */ f32 f66C;
    u8 pad670[0x2C];
    /* 0x69C */ f32 f69C;
    u8 pad6A0[0x4];
    /* 0x6A4 */ f32 f6A4;
    /* 0x6A8 */ f32 f6A8;
    /* 0x6AC */ u32 flags6AC;
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
    u8 pad6F4[0x38];
    /* 0x72C */ f32 f72C;
    u8 pad730[0xC84];
    /* 0x13B4 */ void* tab13B4;
} B05P17;

typedef struct B05A17 {
    u8 pad0[0x8];
    /* 0x008 */ Vec3f pos;
    u8 pad14[0xC];
    /* 0x020 */ f32 f20;
} B05A17;

typedef struct B05In17 {
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
} B05In17;

typedef struct B05StEnt17 { u8 pad0[8]; struct { u8 pad0[8]; f32 f8; } *p8; u8 pad0C[0xC]; } B05StEnt17;

extern f32 D_800C79D0;
extern f32 D_800C79D4;
extern f32 D_800C79D8;
extern f32 D_800C79DC;
extern f32 D_800C79E0;
extern f32 D_800C79E4;
extern f32 D_800C79E8;
extern f32 D_800C79EC;
extern f32 D_800C79F0;
extern f32 D_800C79F4;
extern f32 D_800C79F8;
extern f32 D_800C79FC;
extern f32 D_800C7A00;
extern f32 D_800D2988;

f32 b05_sqrtf(f32) __asm__("sqrtf");
void func_0024795C(f32 *, B05A17 *);
void func_0025DE74(s16, f32, f32, f32, s32, s32);
void func_00271FA4(Vec3f *, Vec3f *, Vec3f *);
void func_00272908(f32 *, Vec3f *, Vec3f *);
void func_002742B4(f32 *, f32 *);
f32 func_00274710(f32, f32, f32);
f32 func_00274810(f32, f32);
void func_002748E0(void *, f32, f32);

void func_002238BC(B05P17 *p, B05A17 *a, B05In17 *in) {
    Vec3f v18;
    Vec3f v28;
    Vec3f v38;
    Vec3f v48;
    Vec3f v58;
    f32 m68[16];
    f32 mA8[4];
    f32 t1;
    f32 t2;
    f32 t3;
    f32 t4;
    f32 t5;
    f32 t6;
    f32 lim1;
    f32 lim2;
    f32 m1;
    f32 m2;
    f32 fv0;
    f32 fv0b;
    f32 fa;
    s32 s0;
    s32 s5;

    s5 = 0;
    s0 = 1;
    t1 = p->f6DC;
    if (!(t1 <= 0.0f)) {
        s0 = 0;
        p->f6DC = t1 - D_800D2988;
    }
    t2 = p->f6C0;
    lim1 = in->f4;
    if (lim1 < (t2 < 0.0f ? -t2 : t2)) {
        p->f6C0 = func_00274810(p->f6C0, in->f8 * D_800C79D0);
    } else if ((t3 = p->f6A8) != 0.0f) {
        m1 = t3 * in->f0;
        fv0 = (t3 < 0.0f ? -t3 : t3) * in->f4;
        p->f6C0 = func_00274710(p->f6C0, m1, fv0);
    } else {
        p->f6C0 = func_00274810(p->f6C0, in->f8);
    }
    t6 = p->f6C4;
    if (in->f4 < (t6 < 0.0f ? -t6 : t6)) {
        p->f6C4 = func_00274810(p->f6C4, in->f8 * D_800C79D4);
    } else if ((t4 = p->f6A4) != 0.0f) {
        m2 = t4 * in->f0;
        lim2 = in->f4;
        if (t4 < 0.0f) {
            fv0b = -t4 * lim2 * D_800C79D8;
        } else {
            fv0b = (t4 * lim2) * D_800C79DC;
        }
        p->f6C4 = func_00274710(p->f6C4, m2, fv0b);
    } else {
        p->f6C4 = func_00274810(p->f6C4, in->f8);
    }
    if (s0 != 0) {
        if (p->flags6B0 & 8) {
            p->f6D4 = in->fC;
            s5 = 1;
        } else if (p->flags6B0 & 4) {
            p->f6D4 = -in->fC * D_800C79E0;
            s5 = 1;
        } else {
            goto b31;
        }
    } else {
b31:
        p->f6D4 = func_00274810(p->f6D4, in->f10);
    }
    if (s0 != 0) {
        if (p->flags6B8 & 1) {
            p->f6D8 = in->fC * D_800C79E4;
            s5 = 1;
        } else if (p->flags6B8 & 2) {
            p->f6D8 = -in->fC * D_800C79E8;
            s5 = 1;
        } else {
            goto b37;
        }
    } else {
b37:
        p->f6D8 = func_00274810(p->f6D8, in->f10 * D_800C79EC);
    }
    if (s0 != 0 && (p->flags6B0 & 0x10)) {
        s5 = 1;
        a->f20 = a->f20 + in->f1C;
    }
    if (p->flags6AC & 0x10) {
        t5 = a->f20;
        if (t5 < in->f18) {
            a->f20 = func_00274710(t5, in->f14, in->f18);
        }
    }
    v18.x = 0.0f;
    v18.y = 0.0f;
    v18.z = p->f6C0 + p->f6D4;
    v28.x = p->f6C4 + p->f6D8;
    v28.y = 0.0f;
    v28.z = 0.0f;
    func_0024795C(mA8, a);
    func_002742B4(mA8, m68);
    func_00272908(m68, &v18, &v38);
    func_00272908(m68, &v28, &v48);
    p->v6E8.x = p->v6E8.x + (v38.x + v48.x) * p->f66C;
    p->v6E8.y = p->v6E8.y + (v38.y + v48.y) * p->f66C;
    p->v6E8.z = p->v6E8.z + (v38.z + v48.z) * p->f66C;
    if (a->f20 < 0.0f) {
        func_00271FA4(&v58, &v38, &v48);
        a->f20 = a->f20 - ((B05StEnt17 *)p->tab13B4)[p->state].p8->f8 *
                          (b05_sqrtf(v58.x * v58.x + v58.y * v58.y + v58.z * v58.z) / (in->f4 * D_800C79F0)) * p->f66C;
    }
    func_002748E0(&p->f72C, (p->f6C4 * D_800C79F4 + p->f69C * D_800C79F8) * D_800C79FC, 0.04f);
    if (s5 != 0) {
        p->f6DC = p->f6DC + D_800C7A00;
        func_0025DE74(in->s22, a->pos.x, a->pos.y, a->pos.z, 0, -1);
    }
}
