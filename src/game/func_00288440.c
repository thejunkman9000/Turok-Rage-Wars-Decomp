#include "b19_types.h"
extern B19Cam *D_801450A8;
extern const f32 D_801031F0;
extern f32 D_801031F8;
extern f32 D_801031FC;
extern f32 D_80103200;
extern f32 D_80103204;
extern u8 D_800CA300[];
extern u8 D_800CA310[];
extern u8 *func_0028FD94(s32, s32);
s32 func_0028FE1C(s32, s32, s32, s32 *);
s32 **func_002518DC(s32, s32, s32, s32, s32, void *, void (*)(), void *, s32);
s32 *func_002543A8(s32, s32, s32, s32, void *, void (*)(), void *);
void func_00253610(s32, void *);
void func_002536F4(s32, void *);
void func_00297020(void *, s32, s32, s32, void *);
void func_00285130();
void func_0028795C();
void func_00288440(B19Owner *ow) {
    s32 i;
    B19Ent12 *out;
    s32 j0;
    s32 **h;
    s32 ci;
    s32 found;
    f32 *A;
    s32 cj;
    f32 *C;
    s32 rows;
    s32 idx;
    s32 cols;
    s32 sp28;
    f32 *B;
    s32 j;
    B19Cam *q;
    s32 z;
    s32 s7;
    s32 i0;
    u8 *r;
    s32 count;
    u8 *E;
    B19Cell *cell;
    s32 fp;
    B19Cam *cam;
    f32 *D;
    cam = D_801450A8;
    if (cam == 0) return;
    i0 = 0;
    count = 0;
    r = func_0028FD94(ow->f68, 0);
    j0 = 0;
    A = (f32 *)(r + 8);
    cols = *(s32 *)(r + 4);
    r = func_0028FD94(ow->f68, 1);
    B = (f32 *)(r + 8);
    s7 = cols - 1;
    r = func_0028FD94(ow->f68, 2);
    rows = *(s32 *)(r + 4);
    C = (f32 *)(r + 8);
    r = func_0028FD94(ow->f68, 3);
    D = (f32 *)(r + 8);
    E = func_0028FD94(ow->f68, 4) + 8;
    fp = rows - 1;
    while (i0 < cols && B[i0] < D_801031F0) i0++;
    while (s7 >= 0 && D_801031FC < A[s7]) s7--;
    while (j0 < rows && D[j0] < D_801031F8) j0++;
    while (fp >= 0 && D_80103204 < C[fp]) fp--;
    out = (B19Ent12 *)((u8 *)ow + 0x1508);
    if (ow->f1B92C == 1) {
        ci = (s32)((cam->x - ow->f1B910) / ow->f1B918);
        cj = (s32)((cam->z - ow->f1B914) / ow->f1B91C);
    } else {
        ci = -1;
        cj = -1;
    }
    if (ci < 0 || ci >= cols || cj < 0 || cj >= rows) {
        ow->f1B928 = 0;
    } else {
        ow->f1B928 = 1;
        ow->f1B6B0 = func_002543A8(0, ow->f8C, ci + cj * cols + 1, ow->f40, ow, func_00285130, D_800CA310);
        func_00253610(0, ow->f1B6B0);
        func_00297020((u8 *)ow + 0x1B6B4, ci, cj, *ow->f1B6B0, &cam->x);
    }
    for (j = j0; j <= fp; j++) {
        s32 base = j * cols;
        for (i = i0; i <= s7; i++) {
            idx = i + base;
            cell = (B19Cell *)(E + idx * 0x14);
            if (cell->n == 0) {
                found = 0;
                for (q = cam; q != 0; q = q->next) {
                    if (q->a < cell->x1 && cell->x0 < q->c && cell->z1 > q->b && cell->z0 < q->d) {
                        found = 1;
                        break;
                    }
                }
                if (found != 0) {
                    s32 t = func_0028FE1C(ow->f64, ow->f30, idx, &sp28);
                    h = func_002518DC(0, t, t, sp28, 8, ow, func_0028795C, D_800CA300, 0);
                    if (h != 0) {
                        if (**h != 0) {
                            out->pp = h;
                            *(void **)&out->box = cell;
                            out->a = i;
                            out->b = j;
                            out++;
                            count++;
                            if (count == 0x80) goto done;
                        } else {
                            func_002536F4(0, h);
                        }
                    }
                }
            }
        }
    }
done:
    ow->ncount = count;
    ow->nent = count;
}
