#include "m01_types.h"

typedef struct V16 { f32 x, y, z, w; } V16;
typedef struct VP { f32 x; volatile f32 y; f32 z, w; } VP;
extern f32 D_800C7228;
extern f32 D_800C722C;
f32 func_0024D274(M1Actor *a);
void func_00271FD8(V16 *dst, V16 *a, V16 *b);
void func_0024795C(f32 *q, M1Actor *a);
void func_002742B4(f32 *q, f32 *m);
void func_00272908(f32 *m, V16 *v, V16 *out);
void func_002720EC(V16 *v);
f32 func_00274640(f32 x);

s32 func_00214310(M1Actor *a, M1Actor *b, f32 maxd, f32 tolA, f32 tolB) {
    V16 A;
    V16 B;
    V16 D;
    V16 V4;
    V16 R;
    VP P;
    V16 Q;
    V16 P2;
    V16 Q2;
    f32 quat[4];
    f32 mat[16];
    f32 k;
    f32 len;
    f32 l2;
    f32 l3;
    f32 c;
    f32 z;

    *(Vec3f *)&A = a->pos;
    A.y += a->f70;
    k = D_800C7228;
    A.y += func_0024D274(a) * k;
    *(Vec3f *)&B = b->pos;
    B.y += b->f70;
    B.y += func_0024D274(b) * k;
    func_00271FD8(&D, &B, &A);
    len = sqrtf(D.x * D.x + D.y * D.y + D.z * D.z);
    if (maxd < len) {
        return 0;
    }
    func_0024795C(quat, a);
    func_002742B4(quat, mat);
    V4.x = 0.0f;
    V4.y = 0.0f;
    V4.z = len;
    func_00272908(mat, &V4, &R);
    tolA = tolA * D_800C722C;
    tolB = tolB * D_800C722C;
    P.x = D.x;
    P.y = 0.0f;
    z = P.y;
    P.z = D.z;
    l2 = sqrtf(D.x * D.x + D.z * D.z);
    if (l2 != z) {
        P.x /= l2;
        P.z /= l2;
    }
    Q.x = R.x;
    Q.y = z;
    Q.z = R.z;
    l3 = sqrtf(R.x * R.x + R.z * R.z);
    if (l3 != z) {
        Q.x /= l3;
        Q.z /= l3;
    }
    c = func_00274640(P.x * Q.x + P.y * Q.y + P.z * Q.z);
    if (c < z) {
        c = -c;
    }
    if (tolA < c) {
        return 0;
    }
    *(s32 *)&P2.x = 0;
    P2.y = D.y;
    P2.z = l2;
    func_002720EC(&P2);
    *(s32 *)&Q2.x = 0;
    Q2.y = R.y;
    Q2.z = l3;
    func_002720EC(&Q2);
    c = func_00274640(P2.x * Q2.x + P2.y * Q2.y + P2.z * Q2.z);
    if (c < 0.0f) {
        if (tolB < -c) return 0;
        return 1;
    }
    if (tolB < c) return 0;
    return 1;
}
