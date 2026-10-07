

#include "b22_types.h"
void func_0029CBB0(f32, f32 *, f32 *);
void func_002A1748(void *, s32, s32);
void func_0029D6A8(B22Mtx *m, Vec3f *a)
{
    f32 sy, cy, sx, cx, sz, cz;
    f32 p, q, r;
    u16 mask;
    mask = 0;
    if (a->x != 0.0f) {
        mask = 4;
    }
    if (a->y != 0.0f) {
        mask |= 2;
    }
    if (a->z != 0.0f) {
        mask |= 1;
    }
    switch (mask) {
    case 0:
        func_002A1748(m, 0, 0x40);
        m->m[0][0] = 1.0f;
        m->m[1][1] = 1.0f;
        m->m[2][2] = 1.0f;
        m->m[3][3] = 1.0f;
        break;
    case 2:
        func_002A1748(m, 0, 0x40);
        m->m[0][0] = 1.0f;
        m->m[1][1] = 1.0f;
        m->m[2][2] = 1.0f;
        m->m[3][3] = 1.0f;
        func_0029CBB0(a->y, &sy, &cy);
        m->m[2][0] = sy;
        m->m[0][0] = cy;
        m->m[0][2] = -sy;
        m->m[2][2] = cy;
        break;
    case 4:
        func_002A1748(m, 0, 0x40);
        m->m[0][0] = 1.0f;
        m->m[1][1] = 1.0f;
        m->m[2][2] = 1.0f;
        m->m[3][3] = 1.0f;
        func_0029CBB0(a->x, &sx, &cx);
        m->m[1][1] = cx;
        m->m[2][1] = -sx;
        m->m[1][2] = sx;
        m->m[2][2] = cx;
        break;
    case 1:
        func_002A1748(m, 0, 0x40);
        m->m[0][0] = 1.0f;
        m->m[1][1] = 1.0f;
        m->m[2][2] = 1.0f;
        m->m[3][3] = 1.0f;
        func_0029CBB0(a->z, &sz, &cz);
        m->m[0][0] = cz;
        m->m[1][0] = -sz;
        m->m[0][1] = sz;
        m->m[1][1] = cz;
        break;
    default:
        func_0029CBB0(a->x, &sx, &cx);
        func_0029CBB0(a->y, &sy, &cy);
        func_0029CBB0(a->z, &sz, &cz);
        p = sx * sy;
        q = cx * cz;
        r = cx * sz;
        m->m[0][0] = cy * cz;
        m->m[1][0] = p * cz - r;
        m->m[2][0] = q * sy + sx * sz;
        m->m[0][1] = cy * sz;
        m->m[1][1] = p * sz + q;
        m->m[0][2] = -sy;
        m->m[2][1] = r * sy - sx * cz;
        m->m[1][2] = sx * cy;
        m->m[2][2] = cx * cy;
        m->m[0][3] = m->m[1][3] = m->m[2][3] = m->m[3][0] = m->m[3][1] = m->m[3][2] = 0.0f;
        m->m[3][3] = 1.0f;
        break;
    }
}



