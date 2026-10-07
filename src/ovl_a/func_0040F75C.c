#include "o02_types.h"
typedef struct O02R {
    s32 parent;                 /* 0x00 */
    s32 next;                   /* 0x04 */
    s32 child;                  /* 0x08 */
    u8 padC[2];
    u16 type;                   /* 0x0E */
    u8 pad10[2];
    u16 flags;                  /* 0x12 */
    u8 pad14[0x2C - 0x14];
    s32 f2C, f30, f34, f38;
    u8 pad3C[8];
    s32 f44;
} O02R;
extern s16 D_80153C0C;
extern u16 *D_80153C4C;
s32 func_00411E4C(s32 i);
void func_0041174C(s32 i);
#define FIX(f) \
    v = q->f; \
    id = (v & 0xFFFF0000) >> 16; \
    lo = v & 0xFFFF; \
    if (id != 0 || lo != 0) { \
        p = func_00411E4C(id); \
        if (p == 0) { \
            func_0041174C(id); \
            p = func_00411E4C(id); \
            D_80153C4C[id] |= 1; \
        } \
        q->f = p + lo; \
    }
void func_0040F75C(O02R *n, s32 newb, s32 oldb) {
    O02R *q;
    s32 v, id, lo, p;
    while (n) {
        if (n->flags & 0x10) {
            if (n->f2C) n->f2C = n->f2C + newb - oldb;
            if (n->f30) n->f30 = n->f30 + newb - oldb;
            if (n->f34) n->f34 = n->f34 + newb - oldb;
            if (n->f38) n->f38 = n->f38 + newb - oldb;
        }
        switch (n->type) {
        case 3:
            if (n->f2C < 0) {
                n->f2C = 0;
            } else if (n->f2C > D_80153C0C - 1) {
                n->f2C = 0;
            }
            break;
        case 2:
            if (n->f44) n->f44 = n->f44 + newb - oldb;
            n->flags |= 0x800;
            break;
        case 4:
            n->f38 = 0;
            break;
        case 8:
            q = n;
            FIX(f2C)
            FIX(f30)
            FIX(f34)
            break;
        }
        if (n->parent != 0 && (n->next != 0 || n->child != 0)) goto fix;
        if (n->type != 2) {
fix:
            n->parent = n->parent + newb - oldb;
        } else {
            n->parent = 0;
        }
        if (n->child) {
            n->child = n->child + newb - oldb;
            func_0040F75C((O02R *)n->child, newb, oldb);
        }
        if (n->next) n->next = n->next + newb - oldb;
        n = (O02R *)n->next;
    }
}
