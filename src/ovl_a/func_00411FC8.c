#include "o02_types.h"
typedef struct { s16 n; u8 pad[0x12]; s32 mode; } S_vars;
extern S_vars D_80153C40;
extern s16 D_80153C0C;
extern s16 D_80153C20;
void func_0041174C(s32 i);
void func_004106F4(s32 i, s32 m);
void func_00410FD4(s32 a, s32 b, s32 c);
void func_00411FC8(void) {
    s32 i;
    D_80153C40.mode = 1;
    for (i = 0; i < D_80153C40.n; i++) {
        func_0041174C(i);
    }
    for (i = 0; i < D_80153C0C; i++) {
        func_004106F4(i, 2);
    }
    for (i = 0; i < D_80153C20; i++) {
        func_00410FD4(0, i, 0);
    }
}
