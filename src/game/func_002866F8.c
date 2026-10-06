#include "b19_types.h"
extern s32 D_800D29B4;
s32 func_0028FD94(s32, s32);
s32 func_00275B80(B19Tri *, f32, f32);
f32 func_00275E44(B19Tri *, f32, f32);
f32 func_002752CC(B19Tri *, f32, f32);
B19Tri *func_002866F8(B19Owner *ow, B19Vec3 *p) {
    s32 idx;
    s32 i;
    f32 best;
    B19Tri *bestt;
    B19Tri *tri;
    B19Tri *t;
    B19Cells *cells;
    B19Cell *c; B19Cell *cb;
    s32 n;
    u32 j;
    f32 h, top, d;
    if (D_800D29B4 == 0) return 0;
    best = 0.0f;
    tri = (B19Tri *)(func_0028FD94(ow->f6C, 2) + 8);
    idx = 0;
    i = 0;
    bestt = 0;
    cells = (B19Cells *)func_0028FD94(ow->f6C, 3);
    n = cells->cnt;
    cb = cells->c;
    if (n > 0) {
        do {
        c = &cb[i];
        if (p->x >= c->x0 && p->x <= c->x1 && p->z >= c->z0 && p->z <= c->z1) {
            if (c->n != 0) {
                j = 0;
                t = (B19Tri *)(idx * 32 + (u32)tri);
                do {
                    if (func_00275B80(t, p->x, p->z) != 0) {
                        h = func_00275E44(t, p->x, p->z);
                        if (t->fl & 0x40) {
                            top = func_002752CC(t, p->x, p->z);
                            if (h <= p->y && p->y <= top) return t;
                        } else {
                            d = p->y - h;
                            if (d < 0.0f) d = -d;
                            if (bestt == 0 || d < best) {
                                bestt = t;
                                best = d;
                            }
                        }
                    }
                    t++;
                    idx++;
                    j++;
                } while (j < c->n);
            }
        } else {
            idx += c->n;
        }
        i++;
        } while (i < n);
    }
    return bestt;
}
