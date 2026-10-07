#include "b22_types.h"
extern SndMgr *D_8014D080;
extern f64 D_800CA7B0;
s32 func_00297E3C(s32, s32, s32, s32, s32);
s32 func_0029864C(s32, s32, s32, s32, s32);
f64 func_002A28CC(s32);
void func_00297CD0(s32);
void func_0029A73C(void);
void func_00299368(s32);
void func_0029A8A8(void);
s32 func_0029A958(void);
void func_0040E9A8(SndCtx *, s32);
static inline s32 Classify(u32 cmd)
{
    if (cmd < 0xE00) {
        return 0;
    }
    if (cmd - 0x1000 < 0x1000) {
        return 1;
    }
    if (cmd - 0xE00 < 0x200) {
        return 2;
    }
    if (cmd - 0x4000 < 0x4000) {
        return 3;
    }
    return 0;
}
s32 func_00298A34(u32 cmd, s32 a, s32 b, s32 c)
{
    s32 *flag = &D_8014D080->unk520;
    SndCtx *ctx = D_8014D080->stk[D_8014D080->top].ctx;
    s32 r = 0;
    s32 saved;
    s32 now;
    s32 (*fn)();
    func_0029A958();
    switch (Classify(cmd)) {
    case 0:
        return func_00297E3C(D_8014D080->stk[D_8014D080->top].unk8 ? D_8014D080->stk[D_8014D080->top].unk8->id : -1, cmd, a, b, c);
    case 2:
        if (cmd == 0xE08) {
            now = func_002A28CC(1) * D_800CA7B0;
            a = now - D_8014D080->unk524;
            b = now;
            D_8014D080->unk524 = b;
        }
        saved = *flag;
        *flag = 0;
        func_0029864C(1, cmd, a, b, c);
        *flag = saved;
        return r;
    case 1:
    case 3:
        saved = *flag;
        *flag = 0;
        fn = (s32 (*)())D_8014D080->stk[D_8014D080->top].ctx->unk40;
        if (fn) {
            r = fn(ctx, cmd, a, b, c);
        }
        if (*flag != 0) {
            *flag = saved;
            return r;
        }
        a = 0;
        switch (Classify(cmd)) {
        case 0:
            switch (cmd) {
            case 1:
                if (ctx->flags12 & 0x10) {
                    if (ctx->unk3C == 0) {
                        *flag = saved;
                        return r;
                    }
                    func_0029A73C();
                    func_00299368(ctx->unk3C);
                    *flag = saved;
                    return r;
                }
                r = a;
                break;
            case 2:
                if (D_8014D080->top > 0) {
                    func_0029A8A8();
                    *flag = saved;
                    return r;
                }
                r = a;
                break;
            case 5:
            case 6:
            case 7:
            case 8:
                if (b == 1) {
                    func_00297CD0(cmd);
                }
                r = a;
                break;
            case 15:
                a = 0;
                func_0040E9A8(ctx, 1);
                r = a;
                break;
            case 16:
                a = 0;
                func_0040E9A8(ctx, a);
                r = a;
                break;
            default:
                a = 0;
                r = a;
                break;
            }
            break;
        case 1:
            a = 0;
            r = a;
            break;
        case 2:
            a = 0;
            r = a;
            break;
        case 3:
            a = 0;
            r = a;
            break;
        }
        *flag = saved;
        return r;
    }
    return r;
}
