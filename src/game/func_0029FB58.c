#include "b23_types.h"

void func_0029FB58(Mtx4f *m) {
    s32 i, j;
    f32 t;

    for (i = 0; i < 3; i++) {
        for (j = i + 1; j < 4; j++) {
            t = m->m[j][i];
            m->m[j][i] = m->m[i][j];
            m->m[i][j] = t;
        }
    }
}
