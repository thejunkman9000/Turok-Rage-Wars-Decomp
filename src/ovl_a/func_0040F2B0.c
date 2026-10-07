#include "o02_types.h"
typedef struct { s32 w0, w1, w2; f32 f3, f4; s32 w5, w6, w7, w8, w9; } S_ctx;
typedef struct { u8 pad[0x14]; s16 x; s16 y; } S_sub;
typedef struct { u8 pad[0x2C]; S_sub *f2C; S_sub *f30; S_sub *f34; } S_func_0040F2B0;
s32 func_0040E154(O02Rect *a, O02Rect *b, S_func_0040F2B0 *n, s32 *c);
void func_0040DB84(S_sub *n, S_ctx c);
void func_0040F2B0(S_func_0040F2B0 *n, S_ctx c) {
    O02Rect r30, r40;
    S_sub *s;
    if (func_0040E154(&r30, &r40, n, &c.w0)) {
        if (c.w2 & 0x100) {
            s = n->f34;
        } else if (c.w2 & 0x40) {
            s = n->f30;
        } else {
            s = n->f2C;
        }
        if (s) {
            c.w0 -= (s32)(s->x * c.f3);
            c.w1 -= (s32)(s->y * c.f4);
            func_0040DB84(s, c);
        }
    }
}
