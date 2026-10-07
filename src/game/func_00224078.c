#include "b05_types.h"

typedef struct B05P12 {
    u8 pad0[0x5DC];
    /* 0x5DC */ void* handle;
    u8 pad5E0[0x70];
    /* 0x650 */ s16 state;
    u8 pad652[0x46];
    /* 0x698 */ void* p698;
    u8 pad69C[0x8];
    /* 0x6A4 */ f32 f6A4;
    /* 0x6A8 */ f32 f6A8;
    /* 0x6AC */ u32 flags6AC;
    /* 0x6B0 */ u32 flags6B0;
    u8 pad6B4[0xC];
    /* 0x6C0 */ f32 f6C0;
    /* 0x6C4 */ f32 f6C4;
    u8 pad6C8[0x20];
    /* 0x6E8 */ Vec3f v6E8;
    u8 pad6F4[0x30];
    /* 0x724 */ f32 f724;
    u8 pad728[0x4];
    /* 0x72C */ s32 z72C;
} B05P12;

typedef struct B05A12 {
    u8 pad0[0x8];
    /* 0x008 */ Vec3f pos;
    /* 0x014 */ s32 w14;
    u8 pad18[0x8];
    /* 0x020 */ f32 f20;
    u8 pad24[0x48];
    /* 0x06C */ f32 ang;
} B05A12;

typedef struct B05Sub12 { u8 pad0[0xC6]; s8 bC6; s8 bC7; } B05Sub12;

extern f32 D_800C7A50;
extern const f32 D_800C7A54;
extern f32 D_800C7A58;
extern f32 D_800C7A5C;
extern f32 D_800C7A60;
extern f32 D_800C7A64;
extern f32 D_800C7A68;
extern f32 D_800C7A6C;
extern f32 D_800C7A70;
extern f32 D_800C7A74;
extern f32 D_800C7A78;
extern f32 D_800C7A7C;
extern f32 D_800C7A80;
extern f32 D_800C7A84;
extern const f32 D_800C7A88;
extern const f32 D_800C7A8C;
extern f32 D_800D2988;
extern u8 D_800C7A40[];
extern u8 D_8011FE88[];
extern u8 D_80145088[];

f32 sinf(f32);
f32 cosf(f32);
void func_002227D0(B05P12 *, B05A12 *, s32);
void func_00237E70(u8 *, void *, u8 *);
void func_00271FA4(Vec3f *, Vec3f *, Vec3f *);
void func_0027200C(Vec3f *, Vec3f *, f32);
f32 func_00274710(f32, f32, f32);
f32 func_00274810(f32, f32);
void func_002748E0(void *, f32, f32);
s32 func_002866F8(u8 *, Vec3f *);

void func_00224078(B05P12 *p, B05A12 *a) {
    Vec3f v;
    f32 t;
    f32 w;
    f32 m;
    s32 r;

    if (p->state == 0 && !(p->flags6AC & 0xE000)) {
        p->state = 1;
    }
    p->z72C = 0;
    func_002748E0(&a->ang, a->ang + ((B05Sub12 *)p->p698)->bC6 * D_800C7A50, D_800C7A54);
    func_002748E0(&p->f724, p->f724 + -((B05Sub12 *)p->p698)->bC7 * D_800C7A58, D_800C7A54);
    t = p->f6A8;
    if (t != 0.0f) {
        m = t * D_800C7A5C;
        if (t < 0.0f) {
            w = -t * D_800C7A60;
        } else {
            w = t * D_800C7A64;
        }
        p->f6C0 = func_00274710(p->f6C0, m, w);
    } else {
        p->f6C0 = func_00274810(p->f6C0, D_800C7A68);
    }
    t = p->f6A4;
    if (t != 0.0f) {
        m = t * D_800C7A6C;
        if (t < 0.0f) {
            w = -t * D_800C7A70;
        } else {
            w = t * D_800C7A74;
        }
        p->f6C4 = func_00274710(p->f6C4, m, w);
    } else {
        p->f6C4 = func_00274810(p->f6C4, D_800C7A78);
    }
    if (p->flags6AC & 0x10) {
        a->f20 = func_00274710(a->f20, D_800C7A7C, 71.68f);
    } else if (p->flags6AC & 0x2020) {
        a->f20 = func_00274710(a->f20, D_800C7A80, 71.68f);
    } else {
        a->f20 = func_00274810(a->f20, D_800C7A84);
    }
    v.x = p->f6C0 * sinf(a->ang + D_800C7A88);
    v.y = a->f20;
    v.z = p->f6C0 * cosf(a->ang + D_800C7A88);
    v.x += p->f6C4 * sinf(a->ang - D_800C7A8C);
    v.z += p->f6C4 * cosf(a->ang - D_800C7A8C);
    func_0027200C(&v, &v, D_800D2988);
    func_00271FA4(&p->v6E8, &p->v6E8, &v);
    r = func_002866F8(D_8011FE88, &a->pos);
    if (r != 0) {
        a->w14 = r;
    }
    if (p->state == 1 && (p->flags6AC & 0xE000) == 0xE000 && (p->flags6B0 & 0xE000)) {
        func_002227D0(p, a, 2);
        if (p->handle != NULL) {
            func_00237E70(D_80145088, p->handle, D_800C7A40);
        }
    }
}
