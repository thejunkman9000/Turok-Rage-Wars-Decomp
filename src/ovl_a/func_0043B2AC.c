#include "o05_types.h"

typedef struct { u16 w[38]; } O05Row;
typedef struct { u8 pad[0x10]; u8 b10; } O05Wb;
extern O05L2 *D_800E59E0;
extern O05Row D_800E59E6[];
extern O05Row D_800E59EE[];
extern O05Row D_800E59EA[];
extern O05Row D_800E5A02[];
extern O05Row D_800E5A1A[];
extern O05Row D_800E5A2E[];
extern O05Row D_800E5A06[];
O05Wb *func_0040ECB0(void *p, s32 id);
void func_0040E958(void *w, s32 a);
void func_0040E9A8(void *w, s32 a);
void func_0043B67C(s32 k, s32 i, s32 v);

void func_0043B2AC(s32 k) {
    s32 i;
    O05Wb *w;
    D_800E59E0->row[k].f4A8 = 1;
    func_0040E958(func_0040ECB0(D_800E59E0->f0, D_800E59E6[k].w[0]), 0);
    switch (D_800E59E0->row[k].f4CC) {
    case 0:
        func_0040E958(func_0040ECB0(D_800E59E0->f0, D_800E5A02[k].w[0]), 0);
        w = func_0040ECB0(D_800E59E0->f0, D_800E5A2E[k].w[0]);
        func_0040E958(w, 1);
        w->b10 = 0x23;
        break;
    case 1:
        for (i = 0; i < 3; i++) {
            func_0040E958(func_0040ECB0(D_800E59E0->f0, D_800E59EE[k].w[i * 2]), 0);
            w = func_0040ECB0(D_800E59E0->f0, D_800E5A1A[k].w[i * 2]);
            func_0040E958(w, 1);
            w->b10 = 0x23;
            func_0043B67C(k, i, D_800E59E0->row[k].tab4B0[i]);
        }
        func_0040E958(func_0040ECB0(D_800E59E0->f0, D_800E5A02[k].w[0]), 0);
        w = func_0040ECB0(D_800E59E0->f0, D_800E5A2E[k].w[0]);
        func_0040E958(w, 1);
        w->b10 = 0x23;
        func_0040E958(D_800E59E0->row[k].f4C8, 0);
        break;
    case 2:
    default:
        for (i = 0; i < 6; i++) {
            func_0040E958(func_0040ECB0(D_800E59E0->f0, D_800E59EE[k].w[i * 2]), 0);
            w = func_0040ECB0(D_800E59E0->f0, D_800E5A1A[k].w[i * 2]);
            func_0040E958(w, 1);
            w->b10 = 0x23;
            func_0043B67C(k, i, D_800E59E0->row[k].tab4B0[i]);
        }
        break;
    }
    for (i = 0; i < 5; i++) {
        w = func_0040ECB0(D_800E59E0->f0, D_800E5A06[k].w[i * 2]);
        func_0040E958(w, 0);
        w->b10 = 0x37;
    }
    w = func_0040ECB0(D_800E59E0->f0, D_800E5A1A[k].w[D_800E59E0->row[k].f4AC * 2]);
    func_0040E9A8(w, 1);
    w->b10 = 0x96;
}
