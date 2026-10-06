#include "b22_types.h"
typedef struct B22MtxHdr {
    u8 pad0[0x10];
    f32 m[4][4];
} B22MtxHdr;
void func_0029FA7C(B22MtxHdr *d, f32 m00, f32 m01, f32 m02, f32 m03, f32 m10, f32 m11, f32 m12, f32 m13, f32 m20, f32 m21, f32 m22, f32 m23, f32 m30, f32 m31, f32 m32, f32 m33)
{
    d->m[0][0] = m00;
    d->m[1][0] = m01;
    d->m[2][0] = m02;
    d->m[3][0] = m03;
    d->m[0][1] = m10;
    d->m[1][1] = m11;
    d->m[2][1] = m12;
    d->m[3][1] = m13;
    d->m[0][2] = m20;
    d->m[1][2] = m21;
    d->m[2][2] = m22;
    d->m[3][2] = m23;
    d->m[0][3] = m30;
    d->m[1][3] = m31;
    d->m[2][3] = m32;
    d->m[3][3] = m33;
}

