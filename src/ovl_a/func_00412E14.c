#include "o02_types.h"
typedef struct { s32 w[13]; } S_e;
extern S_e D_800E2B20[];
u32 func_00412E14(u32 argb, s32 ia, s32 ib) {
    S_e *e = &D_800E2B20[ia];
    u32 c0, c1, c2, c3;
    u32 r, g, b, a;
    c0 = e->w[9] < 0 ? (argb & e->w[5]) << -e->w[9] : (argb & e->w[5]) >> e->w[9];
    c1 = e->w[10] < 0 ? (argb & e->w[6]) << -e->w[10] : (argb & e->w[6]) >> e->w[10];
    c2 = e->w[11] < 0 ? (argb & e->w[7]) << -e->w[11] : (argb & e->w[7]) >> e->w[11];
    c3 = e->w[12] < 0 ? (argb & e->w[8]) << -e->w[12] : (argb & e->w[8]) >> e->w[12];
    argb = c3 << 24;
    argb |= c0 << 16;
    argb |= c1 << 8;
    argb |= c2;
    r = (argb >> 16) & 0xFF;
    g = (argb & 0xFF00) >> 8;
    b = argb & 0xFF;
    e = &D_800E2B20[ib];
    a = argb >> 24;
    r = (e->w[9] < 0 ? (r >> -e->w[9]) & e->w[5] : (r << e->w[9]) & e->w[5]);
    g = (e->w[10] < 0 ? (g >> -e->w[10]) & e->w[6] : (g << e->w[10]) & e->w[6]);
    b = (e->w[11] < 0 ? (b >> -e->w[11]) & e->w[7] : (b << e->w[11]) & e->w[7]);
    a = (e->w[12] < 0 ? (a >> -e->w[12]) & e->w[8] : (a << e->w[12]) & e->w[8]);
    return r | g | b | a;
}
