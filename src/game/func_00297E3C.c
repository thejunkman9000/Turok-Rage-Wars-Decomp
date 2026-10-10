#include "s410_types.h"
extern S410Mgr *D_8014D080;
extern s32 D_8014D084;
typedef S410Fn (*S410SlotFn)(s32);
S410Ctx *func_00299170(s32);
S410Fn func_0029A7E4(s32);
s32 func_0029A958(void);
S410Ctx *func_00411E4C(s32);
void func_00297CD0(s32);
void func_0029A73C(void);
void func_00299368(s32);
void func_0029A8A8(void);
void func_0040E9A8(S410Ctx *, s32);

s32 func_00297E3C(s32 id, u32 cmd, s32 a, s32 b, s32 c)
{
    s32 *flag;
    s32 ret = 0;
    S410Ctx *ctx = 0;
    S410Fn fn = 0;
    s32 isAll = 0;
    s32 saved;
    s32 kind;
    s32 kind2;
    S410Ctx *top;
    S410Fn h;
    S410Ctx *cx;

    if (cmd != 0xE09) {
        D_8014D084++;
    }
    flag = &D_8014D080->lock;
    kind = S410_Classify(cmd);
    top = func_00411E4C(func_0029A958());
    if (id == -1) {
        isAll = 1;
        ctx = top;
    }
    if (isAll == 0) {
        ctx = func_00299170(id);
        if (ctx == 0) {
        ret0:
        ret1:
        ret2:
            return 0;
        }
        fn = func_0029A7E4(ctx->unkE);
        if (fn == 0) {
            switch (S410_Classify(cmd)) {
            case 1:
                goto ret0;
            case 0:
                switch (cmd) {
                case 5:
                case 6:
                case 7:
                case 8:
                    if (b == 1) {
                        func_00297CD0(cmd);
                    }
                    goto ret0;
                case 1:
                    if ((ctx->flags12 & 0x10) == 0) {
                        goto ret0;
                    }
                    if (ctx->unk3C == 0) {
                        goto ret0;
                    }
                    func_0029A73C();
                    func_00299368(ctx->unk3C);
                    goto ret0;
                case 2:
                    if (D_8014D080->top <= 0) {
                        goto ret0;
                    }
                    func_0029A8A8();
                    goto ret0;
                case 15:
                    func_0040E9A8(ctx, 1);
                    goto ret0;
                case 16:
                    func_0040E9A8(ctx, 0);
                    goto ret0;
                default:
                    goto ret0;
                }
            case 2:
                goto ret1;
            default:
                goto ret0;
            }
        }
    }
    __asm__ volatile("" : "+r"(ctx));
    saved = *flag;
    *flag = 0;
    if (top->fn != 0) {
        ret = top->fn(ctx, cmd, a, b, c);
    }
    if (*flag == 1) {
        *flag = saved;
        return ret;
    }
    if (isAll == 0) {
        if (kind != 2) {
            if (top->fn != 0) {
                ret = top->fn(top, cmd, a, b, c);
            }
            if (*flag == 1) {
                *flag = saved;
                return ret;
            }
        }
        cx = func_00299170(id);
        h = 0;
        if (cx != 0) {
            h = cx->fn;
        }
        if (h != 0) {
            ret = h(ctx, cmd, a, b, c);
        }
        if (*flag == 1) {
            *flag = saved;
            return ret;
        }
        if (fn != 0) {
            ret = fn(ctx, cmd, a, b, c);
        }
        if (*flag == 1) {
            *flag = saved;
            return ret;
        }
    }
    ret = 0;
    if (cmd < 0xE00) {
        kind2 = ret;
    } else if (cmd - 0x1000 < 0x1000) {
        kind2 = 1;
    } else if (cmd - 0xE00 < 0x200) {
        kind2 = 2;
    } else if (cmd - 0x4000 < 0x4000) {
        kind2 = 3;
    } else {
        kind2 = 0;
    }
    switch (kind2) {
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
            if (ctx->unk3C == 0) {
                break;
            }
            func_0029A73C();
            func_00299368(ctx->unk3C);
            break;
        case 2:
            if (D_8014D080->top <= 0) {
                break;
            }
            func_0029A8A8();
            break;
        case 15:
            ret = 0;
            func_0040E9A8(ctx, 1);
            break;
        case 16:
            ret = 0;
            func_0040E9A8(ctx, ret);
            break;
        default:
            ret = 0;
            break;
        }
        break;
    case 1:
        ret = 0;
        break;
    case 2:
        ret = 0;
        break;
    case 3:
        ret = 0;
        break;
    }
    *flag = saved;
    return ret;
}
