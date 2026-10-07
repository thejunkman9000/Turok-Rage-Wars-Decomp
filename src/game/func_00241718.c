#include "b09_types.h"

f32 func_00241718(B09Quad *q, f32 x, f32 z) {
    B09V3 n = *(B09V3 *)&q->nx;
    B09V3 p;
    f32 r;
    if (n.y != 0.0f) {
        p = q->v[0];
        r = ((p.z - z) * n.z + (p.x - x) * n.x + p.y * n.y) / n.y;
    } else {
        r = q->v[0].y;
    }
    return r;
}
