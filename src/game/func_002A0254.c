#include "b23_types.h"

extern f32 D_800CAE58;
extern f32 D_800CAE5C;

void func_0029CBB0(f32 a, f32 *s, f32 *c);

void func_002A0254(Mtx4f *m, Vec3f *axis, f32 angle) {
    f32 s, c;
    f32 t, tx, ty, tz, txx, txy, txz, tyy, tyz, tzz, xs, ys, zs;
    f32 x, y, z, zero, nv;

    func_0029CBB0(angle, &s, &c);
    nv = c;
    t = D_800CAE5C - nv;
    x = axis->x;
    tx = t * x;
    y = axis->y;
    ty = t * y;
    z = axis->z;
    tz = t * z;
    txx = tx * x;
    txy = tx * y;
    txz = tx * z;
    tyy = ty * y;
    tyz = ty * z;
    tzz = tz * z;
    xs = s * x;
    ys = s * y;
    zs = s * z;
    zero = 0.0f;
    m->m[3][2] = zero;
    m->m[3][1] = zero;
    m->m[3][0] = zero;
    m->m[2][3] = zero;
    m->m[1][3] = zero;
    m->m[0][3] = zero;
    m->m[3][3] = D_800CAE5C;
    m->m[0][0] = txx + c;
    m->m[0][1] = txy + zs;
    m->m[0][2] = txz - ys;
    m->m[1][0] = txy - zs;
    m->m[1][1] = tyy + nv;
    m->m[1][2] = tyz + xs;
    m->m[2][0] = txz + ys;
    m->m[2][1] = tyz - xs;
    m->m[2][2] = tzz + nv;
}
