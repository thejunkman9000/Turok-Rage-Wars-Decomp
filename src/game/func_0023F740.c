#include "r04_types.h"

typedef struct R4Def {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ s8 b4;
    /* 0x05 */ s8 b5;
    /* 0x06 */ u8 pad6[0xA];
    /* 0x10 */ f32 f10;
} R4Def;

typedef struct R4Tgt {
    /* 0x00 */ u8 pad0[0x18];
    /* 0x18 */ s32 *p18;
    /* 0x1C */ u8 pad1C[0x1BC];
    /* 0x1D8 */ void *p1D8;
} R4Tgt;

typedef struct R4Own {
    /* 0x000 */ u8 kind;
    /* 0x001 */ u8 pad1[3];
    /* 0x004 */ u16 id;
    /* 0x006 */ u8 pad6[2];
    /* 0x008 */ Vec3f pos;
    /* 0x014 */ u8 pad14[8];
    /* 0x01C */ f32 f1C;
    /* 0x020 */ f32 f20;
    /* 0x024 */ f32 f24;
    /* 0x028 */ u8 pad28[0x104];
    /* 0x12C */ R4Tgt *p12C;
    /* 0x130 */ u8 pad130[4];
    /* 0x134 */ s32 w134;
    /* 0x138 */ u8 pad138[4];
    /* 0x13C */ R4Tgt *p13C;
    /* 0x140 */ u8 pad140[0xC];
    /* 0x14C */ u16 h14C;
} R4Own;

typedef struct R4Blk70 { s32 w[28]; } R4Blk70;

typedef struct R4Q {
    /* 0x00 */ s32 type;
    /* 0x04 */ f32 f4;
    /* 0x08 */ s32 f8;
    /* 0x0C */ s32 fC;
    /* 0x10 */ s32 f10;
    /* 0x14 */ s32 kind;
    /* 0x18 */ Vec3f v[4];
    /* 0x48 */ Vec3f n;
    /* 0x54 */ R4Tgt *f54;
    /* 0x58 */ s32 f58;
    /* 0x5C */ R4Blk70 blk;
    /* 0xCC */ f32 t;
    /* 0xD0 */ Vec3f hit;
} R4Q;

typedef struct R4Hm {
    /* 0x00 */ R4Own *owner;
    /* 0x04 */ u8 pad4[0x3C];
    /* 0x40 */ R4Def *def;
    /* 0x44 */ Vec3f v44;
    /* 0x50 */ Vec3f v50;
    /* 0x5C */ Vec3f v5C;
    /* 0x68 */ u8 pad68[0x48];
    /* 0xB0 */ R4Q q;
} R4Hm;

typedef struct R4Box { Vec3f p[8]; } R4Box;

typedef struct R4Rec8 {
    s16 a;
    u16 b;
    u8 c;
    u8 d;
    u8 e;
    u8 f;
} __attribute__((aligned(4))) R4Rec8;

s32 func_0023E8C4(R4Hm *m, R4Q *q, s32 copy);
void func_00271FD8(Vec3f *a, Vec3f *b, Vec3f *c);
void func_00272038(Vec3f *dst, f32 t, Vec3f *a, Vec3f *b);
s32 func_0024E2B4(R4Tgt *t);
void func_0022B720(R4Tgt *t, f32 a);
s32 func_002833A4(R4Own *o);
void func_44ACCC(void *p);
void func_00265E30(R4Tgt *a, R4Own *b, s32 c, s32 d, Vec3f e, R4Rec8 f);

s32 func_0023F740(R4Hm *m, s32 unused, R4Tgt *t, Vec3f *pt, R4Box *b, R4Blk70 *blk, s32 arg7) {
    Vec3f *c[4];
    Vec3f n;
    Vec3f w;
    Vec3f P;
    Vec3f e;
    Vec3f v;
    R4Q ev;
    Vec3f hp;
    R4Rec8 rec;
    s32 ret;
    s32 face;
    s32 i;
    s32 ok;
    Vec3f *q;
    f32 den;
    f32 dd;
    f32 tt;
    f32 zero;

    zero = 0.0f;
    ret = 0;
    for (face = 0; face < 6; face++) {
        switch (face) {
        case 0:
            c[0] = &b->p[7];
            c[1] = &b->p[6];
            c[2] = &b->p[5];
            c[3] = &b->p[4];
            func_00271FD8(&n, &b->p[4], &b->p[0]);
            break;
        case 1:
            c[0] = &b->p[4];
            c[1] = &b->p[5];
            c[2] = &b->p[1];
            c[3] = &b->p[0];
            func_00271FD8(&n, &b->p[0], &b->p[3]);
            break;
        case 2:
            c[0] = &b->p[7];
            c[1] = &b->p[4];
            c[2] = &b->p[0];
            c[3] = &b->p[3];
            func_00271FD8(&n, &b->p[3], &b->p[2]);
            break;
        case 3:
            c[0] = &b->p[6];
            c[1] = &b->p[7];
            c[2] = &b->p[3];
            c[3] = &b->p[2];
            func_00271FD8(&n, &b->p[2], &b->p[1]);
            break;
        case 4:
            c[0] = &b->p[5];
            c[1] = &b->p[6];
            c[2] = &b->p[2];
            c[3] = &b->p[1];
            func_00271FD8(&n, &b->p[1], &b->p[0]);
            break;
        case 5:
            c[0] = &b->p[0];
            c[1] = &b->p[1];
            c[2] = &b->p[2];
            c[3] = &b->p[3];
            func_00271FD8(&n, &b->p[3], &b->p[7]);
            break;
        }
        den = n.x * m->v5C.x + n.y * m->v5C.y + n.z * m->v5C.z;
        if (den == zero) {
            continue;
        }
        func_00271FD8(&w, pt, c[0]);
        dd = w.x * n.x + w.y * n.y + w.z * n.z;
        if (dd == zero) {
            continue;
        }
        tt = -dd / den;
        if (!(tt < m->q.t)) {
            continue;
        }
        P.x = pt->x + tt * m->v5C.x;
        P.y = pt->y + tt * m->v5C.y;
        P.z = pt->z + tt * m->v5C.z;
        ok = 1;
        for (i = 0; i < 4; i++) {
            s32 nx = (i == 3) ? 0 : i + 1;
            q = c[i];
            func_00271FD8(&e, c[nx], q);
            func_00271FD8(&v, &P, q);
            if (e.x * v.x + e.y * v.y + e.z * v.z < zero) {
                ok = 0;
                break;
            }
        }
        if (ok == 0) {
            continue;
        }
        if (func_0024E2B4(t)) {
            ev.f8 = m->def->b5;
        } else {
            ev.f8 = m->def->b4;
        }
        ev.type = 8;
        ev.f4 = m->def->f10;
        ev.fC = 0;
        ev.f10 = 0;
        ev.n = n;
        ev.kind = 1;
        ev.v[0] = *c[0];
        if (func_0023E8C4(m, &ev, 1) == 0) {
            continue;
        }
        m->q.f54 = t;
        m->q.f58 = arg7;
        if (blk != 0) {
            m->q.blk = *blk;
        }
        ret = 1;
        if (m->owner->kind != 2) {
            continue;
        }
        if (m->owner->id != 0x414) {
            if (m->owner->id != 0x42D) {
                continue;
            }
        }
        if (m->owner->p12C == t) {
            func_44ACCC(t->p1D8);
            m->owner->h14C = ret;
            return 0;
        }
        if (m->owner->p13C == t) {
            continue;
        }
        m->owner->p13C = t;
        m->owner->w134 = 0;
        func_00272038(&hp, m->q.t, &m->owner->pos, &m->v50);
        rec.a = 5;
        rec.b = 0x2300;
        rec.c = 5;
        rec.d = (s32)m->owner->f1C;
        rec.e = (s32)m->owner->f20;
        rec.f = (s32)m->owner->f24;
        func_00265E30(t, m->owner, 2, -1, hp, rec);
        if (*t->p18 != 0xB) {
            continue;
        }
        if (m->owner->id != 0x42D) {
            continue;
        }
        func_002833A4(m->owner);
        func_0022B720(t, 2.0f);
    }
    return ret;
}
