#include "b18_types.h"
#define MINA(x, y) (((x) <= (y)) ? (x) : (y))
#define MINB(x, y) (((x) < (y)) ? (x) : (y))
#define MINC(x, y) (((x) > (y)) ? (y) : (x))
#define MAXA(x, y) (((x) >= (y)) ? (x) : (y))
#define MAXB(x, y) (((x) > (y)) ? (x) : (y))
#define MAXC(x, y) (((x) < (y)) ? (y) : (x))

typedef struct B18Xf {
    /* 0x00 */ u8 pad0[8];
    /* 0x08 */ Vec3f pos;
    /* 0x14 */ u8 pad14[8];
    /* 0x1C */ Vec3f v1C;
    /* 0x28 */ u8 pad28[0x28];
} B18Xf;

typedef struct B18Cam {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ u8 pad4[8];
    /* 0x0C */ f32 y;
    /* 0x10 */ u8 pad10[0xE0];
    /* 0xF0 */ u8 unkF0[0x10];
} B18Cam;

typedef struct B18Eff {
    /* 0x000 */ u8 pad0[8];
    /* 0x008 */ Vec3f pos;
    /* 0x014 */ u8 pad14[0x104];
    /* 0x118 */ B18CfgB *cfg;
    /* 0x11C */ u8 pad11C[0x24];
    /* 0x140 */ f32 unk140;
    /* 0x144 */ u8 pad144[8];
    /* 0x14C */ s16 unk14C;
    /* 0x14E */ u8 pad14E[0xA];
    /* 0x158 */ f32 unk158;
} B18Eff;

extern u8 D_8011FFB0[];
extern u8 D_80104030[];
extern B18Cam D_801041F0[];
extern DlCmd *D_80110634;
extern f32 D_80115DEC;

f32 sinf(f32);
f32 cosf(f32);
s32 func_00279A30(void *a, s32 b);
void func_00243A80(B18Xf *t, Vec3f v, void *p);
void func_00271888(B18Vec4 *q, void *vec);
void func_00274108(B18Vec4 *out, B18Vec4 *a, B18Vec4 *b);
void func_002742B4(B18Vec4 *q, void *m);
void func_002725BC(Vec3f *v, s32 s);
void func_002734EC(void *m, f32 a, s32 b, f32 c);
void func_002734B8(void *m, Vec3f v);
void func_002702EC(void *m, s32 a);
void func_0026992C(s32 a, s32 b, s32 c);

void func_0027E758(B18Eff *o) {
    u8 mtx[0x40];
    Vec3f v;
    B18Vec4 qc;
    B18Vec4 qb;
    B18Vec4 qa;
    B18Xf t;
    s32 h;
    f32 alpha, lim, s, camy, ang, a, k, tt, m;
    DlCmd *dl;
    h = func_00279A30(D_8011FFB0, 1);
    do {
    if (h == 0) return;
    t = *(B18Xf *)o;
    t.v1C.x = 0;
    t.v1C.y = 0;
    t.v1C.z = 0;
    t.pos.y += 10.24f;
    v.x = t.pos.x;
    v.z = t.pos.z;
    v.y = t.pos.y - 102400.0f;
    func_00243A80(&t, v, D_80104030);
    if (D_801041F0->unk0 == 0) return;
    ang = 0.7853982f;
    func_00271888(&qb, D_801041F0->unkF0);
    qa.x = D_80115DEC = sinf(ang);
    qa.y = 0;
    qa.z = 0;
    qa.w = cosf(ang);
    func_00274108(&qc, &qa, &qb);
    camy = D_801041F0->y;
    k = o->pos.y - camy;
    a = 200.0f - k * 0.30517578125f;
    alpha = MAXC(MINB(255.0f, a), 0.0f);
    s = o->unk158 * 7.68f;
    if (o->cfg->unk14 != 0) s *= 8.0f;
    s *= o->cfg->unk24->unk18;
    tt = k * 0.1f;
    m = s - k * 0.1f;
    if (!(m <= s)) m = s;
    if (m < 0.0f) {
        lim = 0.0f;
    } else {
        lim = s - k * 0.1f;
        if (!(lim <= s)) lim = s;
    }
    s = lim;
    if (o->cfg->flags & 1) {
        f32 d = (f32)o->unk14C;
        if (d > 0.0f) alpha *= (d - o->unk140) / d;
    }
    v.x = o->pos.x;
    v.y = camy;
    } while (0);
    v.z = o->pos.z;
    func_002725BC(&v, 0x469C4000);
    func_002742B4(&qc, mtx);
    func_002734EC(mtx, s, 0x3F800000, s);
    func_002734B8(mtx, v);
    func_002702EC(mtx, h);
    { DlCmd **pp = &D_80110634; DlCmd *q = (*pp)++; q->w0 = 0xE7000000; q->w1 = 0; }
    { DlCmd **pp = &D_80110634; DlCmd *q = (*pp)++; q->w0 = 0xE3000A01; q->w1 = 0x100000; }
    func_0026992C(h, 1, (u32)alpha & 0xFF);
    { DlCmd **pp = &D_80110634; DlCmd *q = (*pp)++; q->w0 = 0xE7000000; q->w1 = 0; }
    { DlCmd **pp = &D_80110634; DlCmd *q = (*pp)++; q->w0 = 0xE3000A01; q->w1 = 0; }
}