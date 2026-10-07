#include "o03_types.h"
extern s32 func_0040E154(void *a, void *b, O3Hdr *o, O3Xf *x);
extern void func_002A2898(s32 *a, s32 *b, s32 *c, s32 *d);
extern void func_002A2870(s32 a, s32 b, s32 c, s32 d);
extern void func_0040F508(O3Q4 *q, void *m);
extern void func_0040E87C(O3Hdr *o, O3Xf x);
void func_0041BA80(O3Hdr *self, O3Xf x) {
    O3Q16 sp30;
    O3Q16 sp40;
    O3Q4 q;
    O3Q4 c;
    s32 flag = 0;
    if (func_0040E154(&sp30, &sp40, self, &x) != 0) {
        if (self->unk12 & 0x200) {
            func_002A2898(&q.w[0], &q.w[2], &q.w[1], &q.w[3]);
            c = q;
            func_0040F508(&c, &sp40);
            flag = 1;
            func_002A2870(c.w[0], c.w[2], c.w[1], c.w[3]);
        }
        func_0040E87C(self->child, x);
        if (flag != 0) {
            func_002A2870(q.w[0], q.w[2], q.w[1], q.w[3]);
        }
    }
}
