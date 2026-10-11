#include "s1009_types.h"
extern s32 func_0044252C(S10Menu *a, s32 cur, s32 step, s32 lo, s32 hi, s32 wrap);
s32 func_0043E458(void *a, S10Menu *m) {
    S10Sub *sub = m->ctx->sub;
    sub->b7B = func_0044252C(m, sub->b7B, 1, 0, 1, 1);
    return 0;
}
