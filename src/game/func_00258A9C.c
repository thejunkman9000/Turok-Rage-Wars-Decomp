#include "p3_types.h"

extern f32 D_800C8FD4;
void func_00257DF4(P3Ctx *ctx, s32 a1, P3Vec3 v, s32 p, s32 q);

void func_00258A9C(P3Ctx *ctx, s32 a1, P3Vec3 v, s32 p, s32 q, f32 f) {
    ctx->fval = f;
    func_00257DF4(ctx, a1, v, p, q);
    ctx->fval = D_800C8FD4;
}
