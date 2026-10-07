#include "b22_types.h"

extern SndMgr *D_8014D080;
extern s32 D_8014D098;

void func_0029ACF0(SndCtx *c, u32 cmd, s32 a2, s32 a3, s32 a4, s32 f);
void func_00297CD0(s32);
void func_0029A73C(void);
void func_00299368(s32);
void func_0029A8A8(void);
void func_0040E9A8(SndCtx *, s32);

static inline s32 Classify(u32 cmd) {
    if (cmd < 0xE00) return 0;
    if (cmd - 0x1000 < 0x1000) return 1;
    if (cmd - 0xE00 < 0x200) return 2;
    if (cmd - 0x4000 < 0x4000) return 3;
    return 0;
}

s32 func_0029864C(s32 id, u32 cmd, s32 a2, s32 a3, s32 a4) {
    SndMgr *m = D_8014D080;
    s32 *flag = &m->unk520;
    s32 r = 0;
    s32 saved;
    SndCtx *ctx;
    s32 i;
    s32 last;
    s32 off;
    s32 z;

    if (m->fn0 != NULL) {
        saved = *flag;
        *flag = 0;
        r = m->fn0(cmd, a2, a3, a4);
        if (*flag == 1) {
            *flag = saved;
            return r;
        }
        *flag = saved;
    }
    i = D_8014D080->unk8;
    last = D_8014D080->top;
    if (last < i) return r;
    off = i * 0x1C;
    do {
        if (cmd >= 0xE01 && cmd < 0xE03) {
            a2 = (s32)((u8 *)D_8014D080->stk + off + 0xC);
        }
        ctx = *(SndCtx **)((u8 *)D_8014D080->stk + off);
        if (ctx->unk40 != 0) {
            saved = *flag;
            *flag = 0;
            r = ((s32 (*)(SndCtx *, u32, s32, s32, s32))ctx->unk40)(ctx, cmd, a2, a3, a4);
            if (*flag == 1) {
                *flag = saved;
                return r;
            }
            *flag = saved;
        }
        if (id == 0) {
            z = 0;
        } else {
            D_8014D098 = *(s32 *)((u8 *)D_8014D080->stk + off + 4);
            saved = *flag;
            *flag = 0;
            if (ctx != NULL) {
                SndMgr *m2 = D_8014D080;
                s32 s5 = m2->unk520;
                m2->unk520 = 0;
                if (ctx->child1 != NULL) {
                    func_0029ACF0(ctx->child1, cmd, a2, a3, a4, 1);
                }
                if (m2->unk520 == 0) {
                    if (ctx->child2 != NULL) {
                        func_0029ACF0(ctx->child2, cmd, a2, a3, a4, 1);
                    }
                }
                m2->unk520 = s5;
            }
            D_8014D098 = -1;
            if (*flag == 1) {
                *flag = saved;
                return 0;
            }
            *flag = saved;
            z = 0;
        }
        switch (Classify(cmd)) {
        case 1:
        case 2:
        case 3:
            r = z;
            break;
        case 0:
            switch (cmd) {
            case 1:
                if ((ctx->flags12 & 0x10) && ctx->unk3C != 0) {
                    func_0029A73C();
                    func_00299368(ctx->unk3C);
                }
                r = z;
                break;
            case 2:
                if (D_8014D080->top > 0) {
                    func_0029A8A8();
                }
                r = z;
                break;
            case 5: case 6: case 7: case 8:
                if (a3 == 1) {
                    func_00297CD0(cmd);
                }
                r = z;
                break;
            case 15:
                z = 0;
                func_0040E9A8(ctx, 1);
                r = z;
                break;
            case 16:
                z = 0;
                func_0040E9A8(ctx, z);
                r = z;
                break;
            default:
                z = 0;
                r = z;
                break;
            }
            break;
        }
        off += 0x1C;
    } while (++i <= last);
    return r;
}
