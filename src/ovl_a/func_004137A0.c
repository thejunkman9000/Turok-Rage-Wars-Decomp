#include "o02_types.h"
typedef struct { u8 b0; u8 b1; s16 f2; s16 f4; s16 f6; s16 f8; s16 fA; s32 fC; s32 f10; s32 f14; s32 f18; } S_func_004137A0;
void func_004137A0(S_func_004137A0 *p, s32 a, s32 b, s32 c, s32 d, s32 e, s32 flag1, s32 f, s32 g, s32 flag2, s32 h, s32 i, s32 j) {
    p->b0 = a;
    p->f4 = b;
    p->f6 = c;
    p->b1 = 0;
    p->f2 = j;
    p->f8 = d;
    p->fA = e;
    p->f18 = g;
    p->fC = f;
    p->f14 = i;
    p->f10 = h;
    if (flag1) p->b1 = 1;
    if (flag2) p->b1 |= 2;
}
