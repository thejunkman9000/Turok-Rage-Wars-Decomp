#include "s602_types.h"

extern f32 D_800C8410;
extern f32 D_800D05C8;
extern f32 D_800D05CC;
extern f32 D_800D05D0;
extern f32 D_800D05D4;
extern s32 D_800D2B40;
extern s32 D_800E28D0;
extern s32 D_800E28D4;
extern S6BB D_801031F0;
extern S6BB D_80103208;

typedef struct S6F { u32 fl; } S6F;
extern u32 D_80103220;
extern S6Nd *D_80146274;
extern u8 D_801462E7;
extern s32 D_80146894;
extern u8 D_801468A0[];

s32 func_002337C0(void *);
void func_00234FDC(void *);
s32 func_00245774(void);
s32 func_00245788(void);
s32 func_00245840(void);
void func_00255C58(void *, void *);
void func_00255E78(void *, void *);

void func_00236864(S6World *w)
{
    f32 ax, ay, bx, by, sx, sy, tx, ty;
    S6Nd *n;
    S6Nd *nx;
    S6Nd *p;
    s32 a, b, ok;
    u32 c;
    u8 *q;
    S6F *pf;

    ax = D_800E28D0;
    bx = 0.0f;
    ay = D_800E28D4;
    by = 0.0f;
    if (w->mode >= 2) {
        bx = D_800D05CC;
        ay -= D_800D05C8;
        by = D_800D05D0;
        ax -= D_800D05D4;
    }
    sx = ax - by;
    tx = sx * D_800C8410;
    sy = ay - bx;
    n = D_80146274;
    ty = sy * D_800C8410;
    if (n != 0) {
        do {
            nx = n->next;
            a = func_002337C0(n->sub18);
            b = func_002337C0(n->sub2C);
            c = func_002337C0(n->sub40);
            ok = 0;
            if (a != 0 && b != 0) {
                ok = c > 0;
            }
            if (ok != 0) {
                func_00255E78(w->listB, n);
                func_00255C58(w->listA, n);
            }
            n = nx;
        } while (n != 0);
    }
    p = &w->nd;
    p->r0 = D_800E28D0;
    p->r1 = D_800E28D4;
    p->r2 = 0;
    p->r3 = 0;
    if (func_00245788() == 0 && func_00245774() == 0) {
        p = w->first;
        switch (w->mode) {
        case 1:
            p->r0 = sx;
            p->r1 = sy;
            p->r2 = 0;
            p->r3 = 0;
            break;
        case 2:
            if (D_801462E7 == 0) {
                p->r0 = sx;
                p->r1 = ty;
                p->r2 = by;
                p->r3 = bx;
                p = p->next;
                p->r0 = sx;
                p->r1 = ty;
                p->r2 = by;
                p->r3 = bx + ty;
            } else {
                p->r0 = tx;
                p->r1 = sy;
                p->r2 = by;
                p->r3 = bx;
                p = p->next;
                p->r0 = tx;
                p->r1 = sy;
                p->r3 = bx;
                p->r2 = by + tx;
            }
            break;
        case 3:
            q = D_801468A0;
            if (*(s32 *)(q + 0xAC) == 0) {
                u8 *g = q - 0x5D8;
                if (*(u8 *)(g + 0x148) == 1) {
                    p->r0 = tx;
                    p->r1 = ty;
                    p->r2 = by;
                    p->r3 = bx;
                    p = p->next;
                }
                if (*(u8 *)(g + 0x1DE) == 1) {
                    p->r0 = tx;
                    p->r1 = ty;
                    p->r3 = bx;
                    p->r2 = by + tx;
                    p = p->next;
                }
                if (*(u8 *)(g + 0x274) == 1) {
                    p->r0 = tx;
                    p->r1 = ty;
                    p->r2 = by;
                    p->r3 = bx + ty;
                    p = p->next;
                }
                if (*(u8 *)(g + 0x30A) == 1) {
                    p->r0 = tx;
                    p->r1 = ty;
                    p->r2 = by + tx;
                    p->r3 = bx + ty;
                }
            } else {
                p->r0 = tx;
                p->r1 = ty;
                p->r2 = by;
                p->r3 = bx;
                p = p->next;
                p->r0 = tx;
                p->r1 = ty;
                p->r3 = bx;
                p->r2 = by + tx;
                p = p->next;
                p->r0 = tx;
                p->r1 = ty;
                p->r2 = by;
                p->r3 = bx + ty;
            }
            break;
        case 4:
            p->r0 = tx;
            p->r1 = ty;
            p->r2 = by;
            p->r3 = bx;
            p = p->next;
            p->r0 = tx;
            p->r1 = ty;
            p->r3 = bx;
            p->r2 = by + tx;
            p = p->next;
            p->r0 = tx;
            p->r1 = ty;
            p->r2 = by;
            p->r3 = bx + ty;
            p = p->next;
            p->r0 = tx;
            p->r1 = ty;
            p->r2 = by + tx;
            p->r3 = bx + ty;
            break;
        }
    }
    D_80103208 = w->nd.bbA;
    D_801031F0 = w->nd.bbB;
    D_80103220 = D_800D2B40;
    func_00234FDC(&w->nd);
    p = w->first;
    if (p != 0) {
        if (D_80146894 != 0 || func_00245840() != 0) {
            func_00234FDC(p);
        }
        if (func_00245788() != 0 || func_00245774() != 0) {
            func_00234FDC(p);
        }
        D_80103208 = p->bbA;
        D_801031F0 = p->bbB;
        D_80103220 = p->flags;
        p = *(S6Nd **)((u8 *)p + 4);
        if (p != 0) {
            do {
                f32 v;
                if (D_80146894 != 0 || func_00245840() != 0) {
                    func_00234FDC(p);
                }
                v = p->bbA.f[0];
                if (!(v <= D_80103208.f[0])) v = D_80103208.f[0];
                D_80103208.f[0] = v;
                v = p->bbA.f[1];
                if (!(v <= D_80103208.f[1])) v = D_80103208.f[1];
                D_80103208.f[1] = v;
                v = p->bbA.f[2];
                if (!(v <= D_80103208.f[2])) v = D_80103208.f[2];
                D_80103208.f[2] = v;
                v = p->bbA.f[3];
                if (!(D_80103208.f[3] <= v)) v = D_80103208.f[3];
                D_80103208.f[3] = v;
                v = p->bbA.f[4];
                if (!(D_80103208.f[4] <= v)) v = D_80103208.f[4];
                D_80103208.f[4] = v;
                v = p->bbA.f[5];
                if (!(D_80103208.f[5] <= v)) v = D_80103208.f[5];
                D_80103208.f[5] = v;
                v = p->bbB.f[0];
                if (!(v <= D_801031F0.f[0])) v = D_801031F0.f[0];
                D_801031F0.f[0] = v;
                v = p->bbB.f[1];
                if (!(v <= D_801031F0.f[1])) v = D_801031F0.f[1];
                D_801031F0.f[1] = v;
                v = p->bbB.f[2];
                if (!(v <= D_801031F0.f[2])) v = D_801031F0.f[2];
                D_801031F0.f[2] = v;
                v = p->bbB.f[3];
                if (!(D_801031F0.f[3] <= v)) v = D_801031F0.f[3];
                D_801031F0.f[3] = v;
                v = p->bbB.f[4];
                if (!(D_801031F0.f[4] <= v)) v = D_801031F0.f[4];
                D_801031F0.f[4] = v;
                v = p->bbB.f[5];
                if (!(D_801031F0.f[5] <= v)) v = D_801031F0.f[5];
                D_801031F0.f[5] = v;
                ((S6F *)&D_80103220)->fl |= p->flags;
                p = p->next;
            } while (p != 0);
        }
    }
    if (w->oldMode != w->mode) {
        w->cnt = 2;
        w->oldMode = w->mode;
        return;
    }
    if (w->cnt != 0) {
        w->cnt = w->cnt - 1;
    }
}
