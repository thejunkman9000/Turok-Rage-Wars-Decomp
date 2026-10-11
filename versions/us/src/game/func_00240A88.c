#include "b09_types.h"

#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))
f32 sqrtf(f32);
f32 func_00274640(f32);

f32 func_00240A88(B09Quad *q, f32 x0, f32 z0, f32 x1, f32 z1) {
    f32 y0;
    f32 y1;
    f32 num;
    f32 den;
    f32 r;
    f32 a;
    B09V3 n;
    B09V3 p;
    if (q == NULL) {
        return 0.0f;
    }
    n = *(B09V3 *)&q->nx;
    if (n.y == 0.0f) {
        y0 = q->v[0].y;
    } else {
        p = q->v[0];
        y0 = ((p.z - z0) * n.z + (p.x - x0) * n.x + p.y * n.y) / n.y;
    }
    n = *(B09V3 *)&q->nx;
    if (n.y == 0.0f) {
        y1 = q->v[0].y;
    } else {
        p = q->v[0];
        y1 = ((p.z - z1) * n.z + (p.x - x1) * n.x + p.y * n.y) / n.y;
    }
    num = (x1 - x0) * (x1 - x0) + (z1 - z0) * (z1 - z0);
    den = num + (y1 - y0) * (y1 - y0);
    if (den == 0.0f) {
        return 0.0f;
    }
    r = sqrtf(num / den);
    a = func_00274640(MAX(-1.0f, MIN(1.0f, r)));
    if (!(y0 < y1)) {
        a = -a;
    }
    return a;
}
