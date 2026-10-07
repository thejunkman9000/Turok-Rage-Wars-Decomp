#include "o02_types.h"
typedef struct S_func_0041215C { u8 pad0[4]; struct S_func_0041215C *next; struct S_func_0041215C *child; u8 pad0C[2]; u16 type; u8 pad10[0x2C-0x10]; struct S_func_0041215C *f2C; struct S_func_0041215C *f30; struct S_func_0041215C *f34; } S_func_0041215C;
void func_004106F4(void *n, s32 m);
void func_00411B70(void *n);
void func_0041215C(S_func_0041215C *n, s32 a, s32 b) {
    if (n) {
        if (n->next && b) {
            func_0041215C(n->next, a, b);
        }
        if (n->child) {
            func_0041215C(n->child, a, b);
        }
        switch (n->type) {
        case 3:
            if (a) {
                func_004106F4(n->f2C, 3);
            } else {
                func_00411B70(n->f2C);
            }
            break;
        case 4:
            break;
        case 8:
            if (n->f2C) func_0041215C(n->f2C, a, 0);
            if (n->f34) func_0041215C(n->f34, a, 0);
            if (n->f30) func_0041215C(n->f30, a, 0);
            break;
        }
    }
}
