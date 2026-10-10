#include "s410_types.h"
extern S410Mgr *D_8014D080;
void func_0029ACF0(S410Ctx *, s32, s32, s32, s32, s32);
void func_00297CD0(s32);
void func_0029A73C(void);
void func_00299368(s32);
void func_0029A8A8(void);
void func_0040E9A8(S410Ctx *, s32);

s32 func_00298310(s32 mode, u32 ev, s32 a2, s32 a3, s32 a4)
{
    S410Mgr *m = D_8014D080;
    S410Ctx *page = m->stk[m->top].ctx;
    s32 *flag;
    s32 r = 0;
    s32 saved;
    s32 z;
    s32 kind;
    S410Fn h;
    S410Mgr *m2;
    s32 save2;
    s32 *lk2;

    flag = &m->lock;
    if (m->fn0 != 0) {
        saved = m->lock;
        m->lock = 0;
        r = m->fn0(ev, a2, a3, a4);
        if (m->lock == 1) {
            m->lock = saved;
            return r;
        }
        m->lock = saved;
    }
    h = D_8014D080->stk[D_8014D080->top].ctx->fn;
    if (h != 0) {
        saved = *flag;
        *flag = 0;
        r = h(page, ev, a2, a3, a4);
        if (*flag == 1) {
            *flag = saved;
            return r;
        }
        *flag = saved;
    }
    if (mode != 0) {
        saved = *flag;
        *flag = 0;
        if (page != 0) {
            m2 = D_8014D080;
            save2 = m2->lock;
            m2->lock = 0;
            lk2 = &m2->lock;
            if (page->child1 != 0) {
                func_0029ACF0(page->child1, ev, a2, a3, a4, 1);
            }
            if (m2->lock == 0) {
                if (page->child2 != 0) {
                    func_0029ACF0(page->child2, ev, a2, a3, a4, 1);
                }
            }
            *lk2 = save2;
        }
        if (*flag == 1) {
            *flag = saved;
            return r;
        }
        *flag = saved;
    }
    z = 0;
    if (ev < 0xE00) {
    __asm__ volatile("" : "+r"(r));
        kind = z;
    } else if (ev - 0x1000 < 0x1000) {
        kind = 1;
    } else if (ev - 0xE00 < 0x200) {
        kind = 2;
    } else if (ev - 0x4000 < 0x4000) {
        kind = 3;
    } else {
        kind = 0;
    }
    switch (kind) {
    case 0:
        switch (ev) {
        case 5:
        case 6:
        case 7:
        case 8:
            if (a3 == 1) {
                func_00297CD0(ev);
            }
            break;
        case 1:
            if ((page->flags12 & 0x10) == 0) {
                break;
            }
            if (page->unk3C == 0) {
                break;
            }
            func_0029A73C();
            func_00299368(page->unk3C);
            break;
        case 2:
            if (D_8014D080->top <= 0) {
                break;
            }
            func_0029A8A8();
            break;
        case 15:
            z = 0;
            func_0040E9A8(page, 1);
            break;
        case 16:
            z = 0;
            func_0040E9A8(page, z);
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
    return z;
}
