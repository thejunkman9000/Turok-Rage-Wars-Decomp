#include "b23_types.h"

typedef struct E438C E438C;
struct E438C {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ E438C *next;
    /* 0x08 */ u8 pad8[8];
    /* 0x10 */ Vec3f pos;
    /* 0x1C */ f32 unk1C;
    /* 0x20 */ f32 unk20;
    /* 0x24 */ f32 unk24;
    /* 0x28 */ u8 m28[2][0x40];
};

typedef struct S438C {
    u8 pad0[0x40];
    E438C *list;
    u8 pad44[4];
    s32 unk48;
} S438C;

extern s32 D_800D297C;

void func_002702EC(void *src, void *dst);
void func_00272848(void *m);
void func_00272D20(void *m, f32 a, f32 b, f32 c);
void func_002A41D8(E438C *a, E438C *b, void *arg, void *m);

void func_002A438C(S438C *slot, void *arg) {
    u8 m[0x30];
    Vec3f v;
    E438C *e, *n, *p, *q;

    if (slot->unk48 < 2) {
        return;
    }
    e = slot->list;
    n = e->next;
    if (e != 0) {
        func_00272D20(m, e->unk1C, e->unk20, e->unk24);
    } else {
        func_00272848(m);
    }
    if (e == 0) {
        goto tail;
    }
loop:
    if (n == 0) {
        goto tail;
    }
    p = e;
    q = n;
    if (e == 0) {
        goto copy;
    }
    if (e->pos.x == n->pos.x && e->pos.y == n->pos.y) {
again:
        if (p->pos.z == q->pos.z) {
            p = q;
            q = q->next;
            if (p == 0) {
                goto copy;
            }
            if (q == 0) {
                goto check;
            }
            if (p->pos.x == q->pos.x && p->pos.y == q->pos.y) {
                goto again;
            }
        }
    }
check:
    if (p == 0) {
        goto copy;
    }
    if (q == 0) {
        goto copy;
    }
    func_002A41D8(p, q, arg, m);
    goto next;
copy:
    v.x = e->pos.x;
    v.y = e->pos.y;
    v.z = e->pos.z;
next:
    func_002702EC(m, e->m28[D_800D297C]);
    e = n;
    n = e->next;
    if (e != 0) {
        goto loop;
    }
tail:
    v.x = e->pos.x;
    v.y = e->pos.y;
    v.z = e->pos.z;
    func_002702EC(m, e->m28[D_800D297C]);
}
