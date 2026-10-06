#include "p3_types.h"

void func_00273424(P3Mtx *m, f32 x, f32 y, f32 z) {
    m->m[3][0] += x * m->m[0][0] + y * m->m[1][0] + z * m->m[2][0];
    m->m[3][1] += x * m->m[0][1] + y * m->m[1][1] + z * m->m[2][1];
    m->m[3][2] += x * m->m[0][2] + y * m->m[1][2] + z * m->m[2][2];
}
