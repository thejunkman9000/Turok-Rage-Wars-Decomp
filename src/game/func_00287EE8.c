#include "b19b_types.h"
extern B19bG0 D_801462D0;
extern f32 D_800CA2F8[];
extern f32 D_80103214[];
extern f32 D_801031F8[];
extern s32 D_800D2930;
void func_0022A1D0(void *, void *);
f32 func_0023945C(s32, void *);
s32 func_00245788();
void func_0024B8B4(void *);
s32 func_0024D150(void *);
s32 func_0024E1A4(void *);
void func_00262EA8(void *, void *);
s32 func_00297B74(s32, void *);

void func_00287EE8(B19bWorld *w) {
    s32 lim, mask, sflag, i, s2, s5, kind, fl, v;
    B19bObj *objs;
    B19bObj *o;
    B19bInfo *info;
    f32 *bB, *bA;
    s32 t, t0, t1, t2, t3, t4, t5, t6, t7;
    mask = D_801462D0.mask;
    w->n2 = 0;
    w->n3 = 0;
    w->n4 = 0;
    func_0022A1D0((u8 *)&D_801462D0 - 0x1290, w);
    s5 = 0;
    if (D_801462D0.f15 == 0) s5 = *(s32 *)((u8 *)&D_801462D0 - 0x1228);
    sflag = 0;
    if (func_00245788() == 0) sflag = w->f1B408 == 0;
    i = w->first;
    lim = w->count;
    objs = w->objs;
    if (i < lim) {
        bB = D_80103214;
        bA = D_801031F8 + 1;
        do {
            o = &objs[i];
            fl = o->flags;
            if (fl & 0x100) {
                info = o->info;
                s2 = 0;
                if (info->flags & mask) {
                    if (sflag != 0 && !(fl & 2) && o->f10F == 0 && !(fl & 0x400) && info->kind != 3) {
                        if (info->kind != 0xE) {
                            if (func_0024D150(o) == 0) {
                                if (bB[0] > o->fE8 && bB[-3] < o->fF4 && bB[2] > o->fF0 && bB[-1] < o->fFC && bB[1] > o->fEC && bB[-2] < o->fF8) {
                                    if (s5 != 0) {
                                        s2 = func_00297B74(s5 + 0x2F0, &o->fE8);
                                    } else {
                                        goto set1;
                                    }
                                }
                            } else {
                                goto L4;
                            }
                        } else {
                            goto L5;
                        }
                    } else {
                    L4:
                        if (info->kind == 0xE) {
                        L5:
                            if (func_0023945C(s5, (u8 *)o + 8) < D_800CA2F8[1]) s2 = 1;
                        } else {
                            s2 = 0;
                            if (bA[0] > o->fE8 && bA[-3] < o->fF4 && bA[2] > o->fF0 && bA[-1] < o->fFC && bA[1] > o->fEC && bA[-2] < o->fF8) {
                            set1:
                                s2 = 1;
                            }
                        }
                    }
                }
                if (func_00245788() != 0 && D_800D2930 != 0) {
                    if (!(info->flags & 0x200)) s2 = 0;
                } else if (!(info->flags & 0x100)) {
                    kind = info->kind;
                    if (kind != 0xB && kind != 0xE) s2 = 0;
                }
                fl = o->flags;
                if (fl < 0) v = fl | 0x8000;
                else v = fl & 0xFFFF7FFF;
                o->flags = v;
                if (s2 != 0) {
                    (*(volatile s32 *)&o->flags) |= 0x80000000;
                    if (info->kind != 0xE) {
                        func_0024B8B4(o);
                        if (func_0024D150(o) != 0) {
                            t0 = w->n0;
                            if (t0 != 0x200) {
                                w->l0[t0] = o;
                                w->n0 = t0 + 1;
                            }
                        }
                        if (func_0024E1A4(o) != 0) {
                            t1 = w->n1;
                            if (t1 != 0x80) {
                                w->l1[t1] = o;
                                w->n1 = t1 + 1;
                            }
                        }
                        t2 = w->n2;
                        if (t2 < 0x80) {
                            w->l2[t2] = o;
                            w->n2 = t2 + 1;
                        }
                        t3 = w->n3;
                        if (t3 < 0x40 && o->info->kind == 1) {
                            w->l3[t3] = o;
                            { s32 u = w->n3; o->idx = u; w->n3 = u + 1; }
                        }
                        t4 = w->n4;
                        if (t4 < 0x20 && (o->flags & 2)) {
                            w->l4[t4] = o;
                            w->n4 = t4 + 1;
                        }
                        t5 = w->n5;
                        if (t5 < 0x10 && o->info->kind == 5) {
                            w->l5[t5] = o;
                            w->n5 = t5 + 1;
                        }
                        t6 = w->n6;
                        if (t6 < 0x20) {
                            if (o->id == 0x64F) {
                                w->l6[t6] = o;
                                w->n6 = t6 + 1;
                            }
                        }
                        if (o->id == 0x64D) {
                            t7 = w->n7;
                            if (t7 < 4) {
                                w->l7[t7] = o;
                                w->n7 = t7 + 1;
                            }
                        }
                    }
                } else {
                    { s32 u = (*(volatile s32 *)&o->flags); u &= 0x7FFFFFFF; u &= ~0x200; o->flags = u; }
                }
            }
            lim = lim;
            i++;
        } while (i < lim);
    }
    func_00262EA8((u8 *)w + 0x15388, w);
    t = w->cur3 + 1;
    w->cur3 = t;
    if (t >= w->n3) w->cur3 = 0;
}
