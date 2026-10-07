#include "o02_types.h"
typedef struct { s32 w[13]; } S_func_00413E88;
extern S_func_00413E88 D_800E2B20[];
u32 func_00413E88(u32 argb, s32 idx) {
    S_func_00413E88 *e = &D_800E2B20[idx];
    u32 r = (argb >> 16) & 0xFF;
    u32 g = (argb & 0xFF00) >> 8;
    u32 b = argb & 0xFF;
    u32 a = argb >> 24;
    r = (e->w[9] < 0 ? (r >> -e->w[9]) & e->w[5] : (r << e->w[9]) & e->w[5]);
    g = (e->w[10] < 0 ? (g >> -e->w[10]) & e->w[6] : (g << e->w[10]) & e->w[6]);
    b = (e->w[11] < 0 ? (b >> -e->w[11]) & e->w[7] : (b << e->w[11]) & e->w[7]);
    a = (e->w[12] < 0 ? (a >> -e->w[12]) & e->w[8] : (a << e->w[12]) & e->w[8]);
    return r | g | b | a;
}
