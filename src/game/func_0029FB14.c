#include "b22_types.h"
void func_002A1748(void *, s32, s32);
void func_0029FB14(B22Mtx *m)
{
    func_002A1748(m, 0, 0x40);
    m->m[0][0] = 1.0f;
    m->m[1][1] = 1.0f;
    m->m[2][2] = 1.0f;
    m->m[3][3] = 1.0f;
}
