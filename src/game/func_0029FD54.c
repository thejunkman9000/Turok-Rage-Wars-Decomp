#include "b23_types.h"

extern f32 D_800CAE4C;

void func_0029FD54(Mtx4f *m) {
    s32 i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            m->m[j][i] = 0;
        }
    }
    m->m[0][0] = D_800CAE4C;
    m->m[1][1] = D_800CAE4C;
    m->m[2][2] = D_800CAE4C;
}
