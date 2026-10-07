#include "o02_types.h"
typedef struct { s32 w[13]; } S_e;
extern S_e D_800E2B20[];
u32 func_00413F60(u32 argb, s32 idx) {
    S_e *e = &D_800E2B20[idx];
    u32 c0, c1, c2, c3;
    c0 = e->w[9] < 0 ? (argb & e->w[5]) << -e->w[9] : (argb & e->w[5]) >> e->w[9];
    c1 = e->w[10] < 0 ? (argb & e->w[6]) << -e->w[10] : (argb & e->w[6]) >> e->w[10];
    c2 = e->w[11] < 0 ? (argb & e->w[7]) << -e->w[11] : (argb & e->w[7]) >> e->w[11];
    c3 = e->w[12] < 0 ? (argb & e->w[8]) << -e->w[12] : (argb & e->w[8]) >> e->w[12];
    return (c3 << 24) | (c0 << 16) | (c1 << 8) | c2;
}
