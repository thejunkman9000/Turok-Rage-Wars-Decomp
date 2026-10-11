#include "s1009_types.h"
extern s32 func_0044252C(S10Menu *a, s32 cur, s32 step, s32 lo, s32 hi, s32 wrap);
s32 func_0043E318(void *a, S10Menu *m) {
    S10Sub *sub = m->ctx->sub;
    sub->b83 = func_0044252C(m, sub->b83, 1, 0, 10, 0);
    return 0;
}
