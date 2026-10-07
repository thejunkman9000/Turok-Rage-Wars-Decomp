#include "b09_types.h"

void func_00271FD8(f32 *, void *, void *);
void func_00272088(f32 *, void *, f32 *);

s32 func_002414E4(B09Quad *q, B09V3 *pt) {
    f32 c[3];
    f32 e[3];
    f32 d[3];
    B09V3 *cur;
    B09V3 *prev;
    s32 n;
    s32 i;
    n = q->kind;
    if (n == 1) {
        return 1;
    }
    cur = &q->v[0];
    prev = &q->v[n - 1];
    for (i = n - 1; i != -1; i--) {
        func_00271FD8(e, cur, prev);
        func_00272088(c, &q->nx, e);
        func_00271FD8(d, pt, prev);
        prev = cur;
        if (c[0] * d[0] + c[1] * d[1] + c[2] * d[2] > 0.0f) {
            return 0;
        }
        cur++;
    }
    return 1;
}
