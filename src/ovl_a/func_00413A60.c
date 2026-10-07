#include "o02_types.h"
extern s32 D_80153C60;
extern u32 D_80153C68;
extern s32 D_80153C90, D_80153C94, D_80153C98, D_80153C9C;
extern s32 D_80153CB0, D_80153CB4, D_80153CB8, D_80153CBC;
extern void (*D_80153CD0)(void);
u32 func_00413A60(s32 idx) {
    u32 r, g, b, a;
    D_80153C60 = idx;
    D_80153CD0();
    r = (D_80153CB0 < 0 ? (D_80153C68 & D_80153C90) << -D_80153CB0 : (D_80153C68 & D_80153C90) >> D_80153CB0);
    g = (D_80153CB4 < 0 ? (D_80153C68 & D_80153C94) << -D_80153CB4 : (D_80153C68 & D_80153C94) >> D_80153CB4);
    b = (D_80153CB8 < 0 ? (D_80153C68 & D_80153C98) << -D_80153CB8 : (D_80153C68 & D_80153C98) >> D_80153CB8);
    a = (D_80153CBC < 0 ? (D_80153C68 & D_80153C9C) << -D_80153CBC : (D_80153C68 & D_80153C9C) >> D_80153CBC);
    if (D_80153C9C == 0) a = 0xFF;
    return (a << 24) | (r << 16) | (g << 8) | b;
}
