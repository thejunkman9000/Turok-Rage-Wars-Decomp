#include "o02_types.h"
typedef struct { u8 pad[8]; s16 v; } S_func_00413878;
extern S_func_00413878 *D_80153D54;
extern s32 D_80153C78;
extern void (*D_80153CD8)(void);
extern u32 D_80153C68;
extern s32 D_80153C90, D_80153C94, D_80153C98, D_80153C9C;
extern s32 D_80153CB0, D_80153CB4, D_80153CB8, D_80153CBC;
extern void (*D_80153CD0)(void);
u32 func_00413878(s32 base, s32 n) {
    u32 r, g, b, a;
    D_80153C78 = base + n * D_80153D54->v;
    D_80153CD8();
    D_80153CD0();
    r = (D_80153CB0 < 0 ? (D_80153C68 & D_80153C90) << -D_80153CB0 : (D_80153C68 & D_80153C90) >> D_80153CB0);
    g = (D_80153CB4 < 0 ? (D_80153C68 & D_80153C94) << -D_80153CB4 : (D_80153C68 & D_80153C94) >> D_80153CB4);
    b = (D_80153CB8 < 0 ? (D_80153C68 & D_80153C98) << -D_80153CB8 : (D_80153C68 & D_80153C98) >> D_80153CB8);
    a = (D_80153CBC < 0 ? (D_80153C68 & D_80153C9C) << -D_80153CBC : (D_80153C68 & D_80153C9C) >> D_80153CBC);
    if (D_80153C9C == 0) a = 0xFF;
    return (a << 24) | (r << 16) | (g << 8) | b;
}
