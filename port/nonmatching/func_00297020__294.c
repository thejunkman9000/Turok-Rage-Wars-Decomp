/* best attempt: structure matches except callee-saved register numbering (ROM: g=s4, seeds=s2, p=s3) and the sw/lwc1 scheduling of the first bounding-box compare */
#include "b21_grid.h"

void func_00263100(B21Grid *g, s32 *seed);
s32 func_00263174(B21Grid *g, s32 n);
s32 *func_0028FD94(u32 *tbl, u32 idx);

void func_00297020(B21Grid *g, s32 x, s32 y, u32 *seeds, f32 *p) {
    s32 lo[4];
    s32 hi[4];
    u32 i;
    u32 n;
    s32 j;
    s32 k;
    s32 idx;

    g->x = x;
    g->y = y;
    n = *seeds;
    for (i = 1; i < n; i++) {
        func_00263100(g, func_0028FD94(seeds, i));
        lo[0] = func_00263174(g, 0x20);
        lo[1] = func_00263174(g, 0x20);
        lo[2] = func_00263174(g, 0x20);
        hi[0] = func_00263174(g, 0x20);
        hi[1] = func_00263174(g, 0x20);
        hi[2] = func_00263174(g, 0x20);
        if (p[0] > *(f32 *)&lo[0] && p[0] < *(f32 *)&hi[0] &&
            p[1] > *(f32 *)&lo[1] && p[1] < *(f32 *)&hi[1] &&
            p[2] > *(f32 *)&lo[2] && p[2] < *(f32 *)&hi[2]) {
            break;
        }
    }
    if (i == n) {
        func_00263100(g, func_0028FD94(seeds, 0));
    }
    j = 0;
    idx = 0;
    for (j = 0; j < 17; j++) {
        for (k = 0; k < 17; k++) {
            switch (func_00263174(g, 2)) {
            case 1:
                g->map[idx] = -2;
                break;
            case 0:
                g->map[idx] = -3;
                break;
            case 2:
                g->map[idx] = 0;
                break;
            case 3:
                g->map[idx] = 3;
                break;
            }
            idx++;
        }
    }
    j = 0;
    idx = 0;
    for (j = 0; j < 17; j++) {
        for (k = 0; k < 17; k++) {
            if (g->map[idx] == 0) {
                g->map[idx] = *(u16 *)((u8 *)g + 6);
                g->unk4 += func_00263174(g, 9);
            }
            idx++;
        }
    }
}
