#include "b14_types.h"
typedef struct { s16 id; s16 pad; } B14Key;
typedef struct { B14W3 v; s32 pad[2]; } B14Val20;
typedef struct {
    /* 0x00 */ B14Key *keys;
    /* 0x04 */ B14Val20 *vals;
    /* 0x08 */ void *tree;
    /* 0x0C */ s32 pad0C[3];
    /* 0x18 */ s32 lo;
    /* 0x1C */ s32 hi;
    /* 0x20 */ s32 t;
} B14Anim;
s32 *func_0028FD94(void *tree, s16 id);
void func_00272038(B14W3 *out, s32 t, s32 *a, s32 *b);
void func_002604CC(B14Anim *a, s32 idx, B14W3 *out) {
    s32 *n;
    if (a->keys[idx].id == -1) {
        *out = a->vals[idx].v;
    } else {
        n = func_0028FD94(a->tree, a->keys[idx].id);
        func_00272038(out, a->t, n + a->lo, n + a->hi);
    }
}
