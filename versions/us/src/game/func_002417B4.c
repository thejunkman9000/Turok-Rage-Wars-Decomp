#include "b09_types.h"

f32 sqrtf(f32);
f32 func_00274640(f32);

f32 func_002417B4(B09Quad *q) {
    f32 r = sqrtf(q->nx * q->nx + q->nz * q->nz);
    f32 a;
    if (r == 0.0f) {
        return 0.0f;
    }
    a = func_00274640(q->nz / r);
    if (!(q->nx > 0.0f)) {
        a = -a;
    }
    return a;
}
