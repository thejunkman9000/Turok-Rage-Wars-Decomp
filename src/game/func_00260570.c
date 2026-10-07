#include "b14_types.h"
typedef struct { s16 a; s16 b; } B14Key;
typedef struct { u8 pad[0xC]; s16 q[4]; u8 pad2[0x14 - 0x14]; } B14Q20;
typedef struct { s16 pad[6]; s16 q[4]; } B14Val20;
typedef struct {
    /* 0x00 */ B14Key *keys;
    /* 0x04 */ B14Val20 *vals;
    /* 0x08 */ s32 pad8;
    /* 0x0C */ void *tree;
    /* 0x10 */ s32 lo;
    /* 0x14 */ s32 hi;
    /* 0x18 */ s32 pad18[2];
    /* 0x20 */ s32 t;
} B14Anim2;
s32 *func_0028FD94(void *tree, s16 id);
void func_00270B1C(f32 *out, s32 t, s32 *a, s32 *b);
extern const f32 D_800C925C;


void func_00260570(B14Anim2 *a, s32 idx, f32 *out) {
s32 *n;
    B14Val20 *v;
    if (a->keys[idx].b == -1) {
        v = &a->vals[idx];
        out[0] = v->q[0] * D_800C925C;
        out[1] = v->q[1] * D_800C925C;
        out[2] = v->q[2] * D_800C925C;
        out[3] = v->q[3] * D_800C925C;
    } else {
        n = func_0028FD94(a->tree, a->keys[idx].b);
        func_00270B1C(out, a->t, n + a->lo, n + a->hi);
    }
}
