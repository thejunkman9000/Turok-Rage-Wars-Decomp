#include "s410_types.h"
extern S410Mgr *D_8014D080;
extern s32 D_8014D098;
void func_0029ACF0(S410Ctx *, s32, s32, s32, s32, s32);
void func_00297CD0(s32);
void func_0029A73C(void);
void func_00299368(s32);
void func_0029A8A8(void);
void func_0040E9A8(S410Ctx *, s32);

s32 func_0029864C(s32 mode, s32 cmd, s32 a2, s32 a3, s32 a4)
{
    S410Mgr *m = D_8014D080;
    s32 *flag = &m->lock;
    s32 r = 0;
    s32 saved;
    S410Ctx *ctx;
    S410Fn fn;
    s32 i;
    s32 last;
    s32 z;
    s32 kind;
    S410Mgr *m2;
    s32 save2;
    s32 *lk2;

    if (m->fn0 != 0) {
        saved = m->lock;
        m->lock = 0;
        r = m->fn0(cmd, a2, a3, a4);
        if (m->lock == 1) {
            m->lock = saved;
            return r;
        }
        m->lock = saved;
    }
    last = D_8014D080->top;
    for (i = D_8014D080->unk8; i <= last; i++) {
        if (cmd < 0xE03) {
            if (cmd > 0xE00) {
                a2 = (s32)&D_8014D080->stk[i].unkC;
            }
        }
        ctx = D_8014D080->stk[i].ctx;
        fn = ctx->fn;
        if (fn != 0) {
            saved = *flag;
            *flag = 0;
            r = fn(ctx, cmd, a2, a3, a4);
            if (*flag == 1) {
                *flag = saved;
                return r;
            }
            *flag = saved;
        }
        if (mode != 0) {
            D_8014D098 = D_8014D080->stk[i].id;
            saved = *flag;
            *flag = 0;
            if (ctx != 0) {
                m2 = D_8014D080;
                save2 = m2->lock;
                m2->lock = 0;
                lk2 = &m2->lock;
                if (ctx->child1 != 0) {
                    func_0029ACF0(ctx->child1, cmd, a2, a3, a4, 1);
                }
                if (m2->lock == 0) {
                    if (ctx->child2 != 0) {
                        func_0029ACF0(ctx->child2, cmd, a2, a3, a4, 1);
                    }
                }
                *lk2 = save2;
            }
            D_8014D098 = -1;
            if (*flag == 1) {
                *flag = saved;
                return r;
            }
            z = 0;
            *flag = saved;
        } else {
            z = 0;
        }
        if ((u32)cmd < 0xE00) {
            kind = z;
        } else if ((u32)(cmd - 0x1000) < 0x1000) {
            kind = 1;
        } else if ((u32)(cmd - 0xE00) < 0x200) {
            kind = 2;
        } else if ((u32)(cmd - 0x4000) < 0x4000) {
            kind = 3;
        } else {
            kind = z;
        }
        switch (kind) {
        case 0:
            switch (cmd) {
            case 5:
            case 6:
            case 7:
            case 8:
                if (a3 == 1) {
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
                z = 0;
                func_0040E9A8(ctx, 1);
                break;
            case 16:
                z = 0;
                func_0040E9A8(ctx, z);
                break;
            default:
                z = 0;
                break;
            }
            break;
        case 1:
            z = 0;
            break;
        case 2:
            z = 0;
            break;
        case 3:
            z = 0;
            break;
        }
        r = z;
    }
    return r;
}
