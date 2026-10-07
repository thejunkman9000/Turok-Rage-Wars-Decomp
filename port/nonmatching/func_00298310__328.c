/* best attempt: control flow/jump-table/compare trees match the ROM (menu event dispatcher); differences are callee-saved register numbering (page=s4,r=s3,save2=fp, a2 spilled) and the 'ret = 0' constant handling (ROM keeps a zero in s0 and re-zeroes it in the cases 15/16) */
#include "common.h"

typedef struct B21Page B21Page;
struct B21Page {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ B21Page *child4;
    /* 0x08 */ B21Page *child8;
    /* 0x0C */ u8 padC[6];
    /* 0x12 */ u16 flags;
    /* 0x14 */ u8 pad14[0x28];
    /* 0x3C */ s32 unk3C;
    /* 0x40 */ s32 (*fn)(B21Page *p, s32 ev, s32 a2, s32 a3, s32 a4);
};

typedef struct B21MenuEnt {
    /* 0x00 */ B21Page *page;
    /* 0x04 */ u8 pad4[0x18];
} B21MenuEnt;

typedef struct B21Menu {
    /* 0x000 */ s32 (*fn)(s32 ev, s32 a2, s32 a3, s32 a4);
    /* 0x004 */ s32 cur;
    /* 0x008 */ u8 pad8[4];
    /* 0x00C */ B21MenuEnt *ents;
    /* 0x010 */ u8 pad10[0x510];
    /* 0x520 */ s32 lock;
} B21Menu;

extern B21Menu *D_8014D080;
void func_0029ACF0(B21Page *p, s32 ev, s32 a2, s32 a3, s32 a4, s32 f);
void func_00297CD0(s32 dir);
void func_0029A73C();
void func_00299368(s32 a);
void func_0029A8A8();
void func_40E9A8(B21Page *p, s32 a);

s32 func_00298310(s32 flag, u32 ev, s32 a2, s32 a3, s32 a4) {
    B21Menu *m = D_8014D080;
    B21Page *page;
    s32 r;
    s32 saved;
    s32 *lock;
    s32 kind;
    s32 ret;
    s32 save2;
    B21Menu *m2;
    s32 *lk2;
    s32 (*h)(B21Page *p, s32 ev, s32 a2, s32 a3, s32 a4);

    r = 0;
    page = m->ents[m->cur].page;
    lock = &m->lock;
    if (m->fn != NULL) {
        saved = m->lock;
        m->lock = 0;
        r = m->fn(ev, a2, a3, a4);
        if (m->lock == 1) {
            m->lock = saved;
            return r;
        }
        m->lock = saved;
    }
    h = D_8014D080->ents[D_8014D080->cur].page->fn;
    if (h != NULL) {
        saved = *lock;
        *lock = 0;
        r = h(page, ev, a2, a3, a4);
        if (*lock == 1) {
            *lock = saved;
            return r;
        }
        *lock = saved;
    }
    if (flag != 0) {
        saved = *lock;
        *lock = 0;
        if (page != NULL) {
            m2 = D_8014D080;
            save2 = m2->lock;
            m2->lock = 0;
            lk2 = &m2->lock;
            if (page->child4 != NULL) {
                func_0029ACF0(page->child4, ev, a2, a3, a4, 1);
            }
            if (m2->lock == 0) {
                if (page->child8 != NULL) {
                    func_0029ACF0(page->child8, ev, a2, a3, a4, 1);
                }
                *lk2 = save2;
            } else {
                *lk2 = save2;
            }
        }
        if (*lock == 1) {
            *lock = saved;
            return r;
        }
        *lock = saved;
    }
    ret = 0;
    if (ev < 0xE00) {
        kind = ret;
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
    default:
        return ret;
    case 0:
        switch (ev) {
        case 1:
            if ((page->flags & 0x10) && page->unk3C != 0) {
                func_0029A73C();
                func_00299368(page->unk3C);
            }
            return ret;
        case 2:
            if (D_8014D080->cur > 0) {
                func_0029A8A8();
            }
            return ret;
        case 5:
        case 6:
        case 7:
        case 8:
            if (a3 == 1) {
                func_00297CD0(ev);
            }
            return ret;
        case 15:
            ret = 0;
            func_40E9A8(page, 1);
            return ret;
        case 16:
            ret = 0;
            func_40E9A8(page, ret);
            return ret;
        }
    case 1:
        ret = 0;
        return ret;
    case 2:
        ret = 0;
        return ret;
    case 3:
        ret = 0;
        return ret;
    }
}
