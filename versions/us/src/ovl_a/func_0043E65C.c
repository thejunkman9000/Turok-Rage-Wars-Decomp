#include "s1009_types.h"
extern s32 func_0026439C(void *p);
extern s32 func_004425F8(S10Menu *a, s32 cur, s32 step, s32 lo, s32 hi, s32 wrap);
extern void func_0044AD14(S10Ctx *c, s32 v);
extern void func_004422BC(void *a, s32 b, s32 c);
extern void func_0025DF54(s32 a);
extern void func_00442934(s32 a, s32 b, void *c);
extern u8 D_00450698[];
extern S10Pair D_800E5DFA[];
s32 func_0043E65C(void *x, S10Menu *m, void *y) {
    S10Ctx *ctx = m->ctx;
    S10Sub *sub = ctx->sub;
    if (func_0026439C(m->ctrl)) {
        func_0044AD14(ctx, sub->b80);
        func_0025DF54(D_800E5DFA[ctx->f5E0].v);
        func_00442934((s32)y, (s32)m, D_00450698);
        return 1;
    } else {
        s8 v = func_004425F8(m, sub->b80, 1, 0, 0x12, 1);
        sub->b80 = v;
        func_0044AD14(ctx, v);
        func_004422BC(x, 0xB, sub->b80);
        return 0;
    }
}
