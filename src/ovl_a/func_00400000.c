#include "o01_types.h"

extern const f32 D_800E0B20;
extern const f32 D_800E0B24;
extern const f32 D_800E0B28;
f32 *func_00252FFC(s32 size);
void func_00254784(void *p);

void func_00400000(s32 n, f32 *x, f32 *t, f32 *y2) {
    f32 *A;
    f32 *B;
    f32 *C;
    s32 i;
    s32 flag = 0;
    if (n == 1) {
        y2[0] = 0;
        return;
    }
    A = func_00252FFC(n * 4);
    B = func_00252FFC(n * 4);
    C = func_00252FFC(n * 4);
    for (i = 1; i < n - 1; i++) {
        A[i] = (t[i + 1] - t[i - 1]) * 2.0f;
        if (A[i] == 0.0f) {
            A[i] = D_800E0B20;
            flag = 1;
        }
    }
    for (i = 0; i < n - 1; i++) {
        C[i] = t[i + 1] - t[i];
        if (C[i] == 0.0f) {
            C[i] = D_800E0B24;
            flag = 1;
        }
    }
    for (i = 1; i < n - 1; i++) {
        B[i] = ((x[i + 1] - x[i]) / C[i] - (x[i] - x[i - 1]) / C[i - 1]) * D_800E0B28;
    }
    for (i = 1; i < n - 2; i++) {
        B[i + 1] = B[i + 1] - B[i] * C[i] / A[i];
        A[i + 1] = A[i + 1] - C[i] * C[i] / A[i];
    }
    for (i = 0; i < n; i++) {
        y2[i] = 0;
    }
    if (flag == 0) {
        for (i = n - 2; i > 0; i--) {
            y2[i] = (B[i] - C[i] * y2[i + 1]) / A[i];
        }
    }
    func_00254784(A);
    func_00254784(B);
    func_00254784(C);
}
