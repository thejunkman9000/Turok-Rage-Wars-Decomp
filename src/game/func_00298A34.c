#include "s410_types.h"
extern S410Mgr *D_8014D080;
extern f64 D_800CA7B0;
S410Ctx *func_00299170(s32);
s32 func_0029A958(void);
s32 func_00297E3C(s32, s32, s32, s32, s32);
s32 func_0029864C(s32, s32, s32, s32, s32);
f64 func_002A28CC();
void func_00297CD0(s32);
void func_0029A73C(void);
void func_00299368(s32);
void func_0029A8A8(void);
void func_0040E9A8(S410Ctx *, s32);

s32 func_00298A34(u32 cmd, s32 a, s32 b, s32 c)
{
    s32 *flag = &D_8014D080->lock;
    S410Ctx *ctx = D_8014D080->stk[D_8014D080->top].ctx;
    s32 ret = 0;
    s32 saved;
    s32 now;
    s32 kind;
    S410Fn fn;

    func_0029A958();
    if (cmd < 0xE00) {
        kind = ret;
    } else if (cmd - 0x1000 < 0x1000) {
        kind = 1;
    } else if (cmd - 0xE00 < 0x200) {
        kind = 2;
    } else if (cmd - 0x4000 < 0x4000) {
        kind = 3;
    } else {
        kind = 0;
    }
    switch (kind) {
    case 0:
        {
            S410Ctx *p = D_8014D080->stk[D_8014D080->top].unk8;
            ret = func_00297E3C(p ? p->id : -1, cmd, a, b, c);
        }
        break;
    case 2:
        if (cmd == 0xE08) {
            now = func_002A28CC() * D_800CA7B0;
            a = now - D_8014D080->unk524;
            b = now;
            D_8014D080->unk524 = b;
        }
        saved = *flag;
        *flag = 0;
        func_0029864C(1, cmd, a, b, c);
        *flag = saved;
        break;
    case 1:
    case 3:
        saved = *flag;
        *flag = 0;
        fn = D_8014D080->stk[D_8014D080->top].ctx->fn;
        if (fn != 0) {
            ret = fn(ctx, cmd, a, b, c);
        }
        if (*flag != 0) {
            *flag = saved;
            goto out;
        }
        a = 0;
        if (cmd < 0xE00) {
            kind = a;
        } else if (cmd - 0x1000 < 0x1000) {
            kind = 1;
        } else if (cmd - 0xE00 < 0x200) {
            kind = 2;
        } else if (cmd - 0x4000 < 0x4000) {
            kind = 3;
        } else {
            kind = 0;
        }
        switch (kind) {
        case 0:
            switch (cmd) {
            case 5:
            case 6:
            case 7:
            case 8:
                if (b == 1) {
                    func_00297CD0(cmd);
                }
                break;
            case 1:
                if ((ctx->flags12 & 0x10) == 0) {
                    break;
                }
                ret = a;
                if (ctx->unk3C == 0) {
                    goto done;
                }
                func_0029A73C();
                func_00299368(ctx->unk3C);
                goto done;
            case 2:
                if (D_8014D080->top <= 0) {
                    break;
                }
                func_0029A8A8();
                break;
            case 15:
                a = 0;
                func_0040E9A8(ctx, 1);
                break;
            case 16:
                a = 0;
                func_0040E9A8(ctx, a);
                break;
            default:
                a = 0;
                break;
            }
            break;
        case 1:
            a = 0;
            break;
        case 2:
            a = 0;
            break;
        case 3:
            a = 0;
            break;
        }
        ret = a;
    done:
        *flag = saved;
        break;
    }
out:
    return ret;
}
