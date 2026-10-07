#include "o01_types.h"

typedef struct O01SplRec {
    /* 0x00 */ f32 x, y, z;
    /* 0x0C */ f32 cx, cy, cz;
    /* 0x18 */ f32 arc;
    /* 0x1C */ f32 t;
    /* 0x20 */ f32 c2;
} O01SplRec;
typedef struct O01Spl {
    /* 0x00 */ s32 stride;
    /* 0x04 */ s32 count;
    /* 0x08 */ O01SplRec rec[1];
} O01Spl;
f32 *func_00252FFC(s32 size);
void func_00254784(void *p);
void func_00271FD8(O01Vec3 *dst, O01SplRec *a, O01SplRec *b);
void func_00400000(s32 n, f32 *x, f32 *t, f32 *y2);
f32 sqrtf(f32 x);

void func_004002D8(s32 n, O01Vec3 *pts, f32 *tv, O01Spl *out) {
    f32 *X;
    f32 *T;
    f32 *Y;
    O01SplRec *rec;
    O01Vec3 d;
    f32 acc = 0.0f;
    f32 z0;
    s32 i;
    X = func_00252FFC(n * 4);
    T = func_00252FFC(n * 4);
    Y = func_00252FFC(n * 4);
    rec = out->rec;
    out->stride = 0x24;
    out->count = n;
    if (n == 1) {
        rec[0].x = pts[0].x;
        rec[0].y = pts[0].y;
        z0 = pts[0].z;
        rec[0].cx = acc;
        rec[0].cy = acc;
        rec[0].cz = acc;
        rec[0].c2 = acc;
        rec[0].t = acc;
        rec[0].z = z0;
        return;
    }
    for (i = 0; i < n; i++) {
        rec[i].x = pts[i].x;
        rec[i].y = pts[i].y;
        rec[i].z = pts[i].z;
        rec[i].t = tv[i];
    }
    for (i = 0; i < n; i++) {
        rec[i].arc = acc;
        if (i == n - 1) {
            break;
        }
        func_00271FD8(&d, &rec[i], &rec[i + 1]);
        acc += sqrtf(d.x * d.x + d.y * d.y + d.z * d.z);
    }
    for (i = 0; i < n; i++) {
        X[i] = rec[i].x;
        T[i] = rec[i].arc;
    }
    func_00400000(n, X, T, Y);
    for (i = 0; i < n; i++) {
        rec[i].cx = Y[i];
    }
    for (i = 0; i < n; i++) {
        X[i] = rec[i].y;
        T[i] = rec[i].arc;
    }
    func_00400000(n, X, T, Y);
    for (i = 0; i < n; i++) {
        rec[i].cy = Y[i];
    }
    for (i = 0; i < n; i++) {
        X[i] = rec[i].z;
        T[i] = rec[i].arc;
    }
    func_00400000(n, X, T, Y);
    for (i = 0; i < n; i++) {
        rec[i].cz = Y[i];
    }
    for (i = 0; i < n; i++) {
        X[i] = rec[i].arc;
        T[i] = rec[i].t;
    }
    func_00400000(n, X, T, Y);
    for (i = 0; i < n; i++) {
        rec[i].c2 = Y[i];
    }
    func_00254784(X);
    func_00254784(T);
    func_00254784(Y);
}
