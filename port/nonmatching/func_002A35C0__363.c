
#include "b23_types.h"

typedef struct Ent35C0 Ent35C0;
typedef struct Slot35C0 Slot35C0;

struct Ent35C0 {
    /* 0x00 */ Ent35C0 *prev;
    /* 0x04 */ Ent35C0 *next;
    /* 0x08 */ f32 unk8;
    /* 0x0C */ u8 padC[4];
    /* 0x10 */ u8 m10[0xC];
    /* 0x1C */ u8 m1C[0xC];
    /* 0x28 */ u8 m28[0x40];
    /* 0x68 */ u8 m68[0x40];
    /* 0xA8 */ f32 unkA8;
    /* 0xAC */ f32 unkAC;
    /* 0xB0 */ s32 unkB0;
};

typedef struct Shape35C0 {
    /* 0x00 */ u8 pad0[8];
    /* 0x08 */ f32 unk8;
    /* 0x0C */ u8 padC[0x10];
    /* 0x1C */ u8 unk1C;
} Shape35C0;

struct Slot35C0 {
    /* 0x00 */ u8 pad0[8];
    /* 0x08 */ Shape35C0 *shape;
    /* 0x0C */ u8 padC[0x1C];
    /* 0x28 */ f32 unk28;
    /* 0x2C */ u8 pad2C[0x10];
    /* 0x3C */ u32 flags;
    /* 0x40 */ Ent35C0 *list;
    /* 0x44 */ u8 pad44[8];
    /* 0x4C */ f32 unk4C;
    /* 0x50 */ s32 unk50;
};

extern f32 D_800CAF50;

Ent35C0 *func_002A6724(void *o, Slot35C0 *s);
void func_00273340(void *src, void *dst);
void func_0027335C(void *src, void *dst);
void func_002702EC(void *src, void *dst);
void func_00271FD8(Vec3f *out, void *a, void *b);

Ent35C0 *func_002A35C0(void *o, Slot35C0 *s, void *m) {
    Ent35C0 *e, *p, *n;
    Vec3f v;
    f32 d, acc;

    e = func_002A6724(o, s);
    if (e != 0) {
        n = e;
        s->unk50 = 0;
        e->unkB0 = 0;
        e->unk8 = s->shape->unk8;
        func_00273340(m, e->m10);
        if (s->flags & 4) {
            func_0027335C(m, e->m1C);
        } else {
            func_002702EC(m, e->m28);
            func_002702EC(m, e->m68);
        }
        p = n->prev;
        n->unkAC = 0;
        n->unkA8 = 0.0f;
        if (p != 0) {
            func_00271FD8(&v, n->m10, p->m10);
            d = sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
            p->unkAC = d;
            s->unk4C = s->unk4C + d;
        }
        if (s->shape->unk1C == 0) {
            if (s->unk4C > 0.0f) {
                acc = 0.0f;
                for (n = s->list; n != 0; n = n->next) {
                    n->unkA8 = acc / s->unk4C;
                    acc = acc + n->unkAC;
                }
            }
            return e;
        }
        if (p != 0) {
            s->unk28 = s->unk28 + p->unkAC * D_800CAF50;
        }
        n->unkA8 = s->unk28;
    }
    return e;
}

