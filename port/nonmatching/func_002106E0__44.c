#include "b03_types.h"
#include "r01_types.h"

extern f32 D_800C7080;
extern f32 D_800C7084;
extern Vec3f D_800CDAF0[];
extern R1Hit *D_80103FCC;
extern u8 D_80103FD0[];
f32 func_0024E454(void);
f32 func_0024D388(ActorB *a);
f32 func_0024D274(ActorB *a);
f32 func_0024E410(ActorB *a);
s32 func_0024490C(ActorB *a, Vec3f p, Vec3f q, u8 *out, f32 e, f32 f, f32 g, f32 h);

void func_002106E0(ActorB *a, s32 idx) {
    Vec3f P;
    Vec3f Q;
    Vec3f R;
    f32 dx, dz, v;
    f32 fa, fb, fc;

    P = a->pos;
    Q = D_800CDAF0[idx];
    Q.x = Q.x * a->brain->unk210;
    Q.y = Q.y * a->brain->unk210;
    Q.z = Q.z * a->brain->unk210;
    Q.y = Q.y + P.y;
    Q.x = Q.x + P.x;
    P.y = P.y + D_800C7080;
    Q.z = Q.z + P.z;
    fa = func_0024E454();
    fb = func_0024D388(a);
    fc = func_0024D274(a);
    if (func_0024490C(a, P, Q, D_80103FD0, fa, fb, fc, func_0024E410(a)) != 0) {
        R = D_80103FCC->pos;
        dx = R.x - P.x;
        R.y = 0.0f;
        dz = R.z - P.z;
        R.x = dx;
        R.z = dz;
        if (dx != R.y) {
            if (dz == R.y) {
                v = dx;
                if (dx < R.y) v = -dx;
                a->brain->fa[idx] = v;
            } else {
                v = dx;
                if (v < R.y) v = -v;
                if (dz < R.y) v = v - dz; else v = v + dz;
                a->brain->fa[idx] = v * D_800C7084;
            }
        } else if (dz != R.y) {
            v = dz;
            if (dz < R.y) v = -dz;
            a->brain->fa[idx] = v;
        }
    } else {
        a->brain->fa[idx] = a->brain->unk210;
    }
}
