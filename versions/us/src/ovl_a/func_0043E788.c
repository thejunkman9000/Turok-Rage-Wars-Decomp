#include "s1009_types.h"
extern s32 func_004426E4();
extern u8 D_00450758[];
s32 func_0043E788(void *a, S10Menu *m) {
    S10Ctx *ctx = m->ctx;
    S10Sub *sub = ctx->sub;
    ctx->f858 = 0;
    sub->b80 = 0;
    func_004426E4(ctx->f5DC + 0x554, D_00450758, ctx, ctx->f698, ctx->f5D4);
    return 1;
}
