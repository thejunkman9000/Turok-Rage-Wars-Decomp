#include "b19a_types.h"
extern B19aDl *D_80110634;
extern B19aGlobal D_801462D0;
extern u8 D_801462E5;
extern s32 D_800D2AE0;
extern s32 D_800D2980;
void func_00288E78();
void *func_002392DC(B19aView *);
void func_0026D980();
void func_0026D9D0();
void func_00253B5C(s32, s32 **);
void *func_0028FD94(s32, s32);
void func_00250950(B19aObjA *, B19aView *);
void func_0024F284(B19aObjB *, B19aView *);
s32 func_00297390(void *, s32, s32, s32);
s32 func_00297B74(void *, void *);
s32 func_002500A4(B19aObjA *, B19aView *);
void func_0025021C(B19aObjA *, B19aView *);
void func_0024EB80(B19aObjB *);
void func_002536F4(s32, s32 *);
void func_002537D8(s32, s32 *);
void func_00289054(B19aOwner *ow, B19aView *v) {
    B19aObjA *base;
    s32 *grp;
    s32 i;
    s32 n;
    u32 mask;
    u32 vmask;
    s32 idx;
    s32 flag;
    u8 *actor;
    B19aTbl *tbl;
    s32 cnt;
    s32 si;
    B19aTbl *t;
    B19aEnt *pe;
    B19aEnt *e;
    B19aObjA *a;
    B19aObjB *p;
    B19aObjB *pb;
    s32 k;
    s32 cnt1;
    s32 cnt2;
    s32 pushed;
    s32 off;
    s32 c;
    mask = D_801462D0.mask;
    vmask = v->mask;
    ow->nB = 0;
    if (D_800D2AE0 == 0 && D_801462D0.b15 != 0) {
        func_00288E78();
        return;
    }
    actor = func_002392DC(v);
    tbl = ow->tbl94;
    cnt = tbl->cnt;
    si = 0;
    if (cnt > 0) {
        do {
            if (tbl->ids[si] == 0x33) {
                idx = si;
                goto found;
            }
            si++;
        } while (si < cnt);
    }
    idx = -1;
found:
    flag = 0;
    if (actor != 0) {
        if (idx != -1) flag = D_801462E5 == 0;
    }
    { B19aDl **pp = &D_80110634; B19aDl *q = (*pp)++; q->w0 = 0xE7000000; q->w1 = 0; }
    { B19aDl **pp = &D_80110634; B19aDl *q = (*pp)++; q->w0 = 0xE3000A01; q->w1 = 0x100000; }
    func_0026D980();
    ow->nB = 0;
    if (actor != 0 && (*(u32 *)(actor + 0x664) & 0x100)) {
        { B19aDl **pp = &D_80110634; B19aDl *q = (*pp)++; q->w0 = 0xDB040004; q->w1 = 1; }
        { B19aDl **pp = &D_80110634; B19aDl *q = (*pp)++; q->w0 = 0xDB04000C; q->w1 = 1; }
        { B19aDl **pp = &D_80110634; B19aDl *q = (*pp)++; q->w0 = 0xDB040014; q->w1 = 0xFFFF; }
        { B19aDl **pp = &D_80110634; B19aDl *q = (*pp)++; q->w0 = 0xDB04001C; q->w1 = 0xFFFF; }
    } else {
        { B19aDl **pp = &D_80110634; B19aDl *q = (*pp)++; q->w0 = 0xDB040004; q->w1 = 2; }
        { B19aDl **pp = &D_80110634; B19aDl *q = (*pp)++; q->w0 = 0xDB04000C; q->w1 = 2; }
        { B19aDl **pp = &D_80110634; B19aDl *q = (*pp)++; q->w0 = 0xDB040014; q->w1 = 0xFFFE; }
        { B19aDl **pp = &D_80110634; B19aDl *q = (*pp)++; q->w0 = 0xDB04001C; q->w1 = 0xFFFE; }
    }
    i = 0;
    n = ow->nent;
    pe = ow->ent;
    if (n > 0) {
        do {
            e = pe + i;
            if (v->mn[0] < e->box->x1 && e->box->x0 < v->mx[0] && v->mn[2] < e->box->z1 && e->box->z0 < v->mx[2]) {
                func_00253B5C(0, e->pp);
                k = 0;
                grp = *e->pp;
                t = func_0028FD94((s32)grp, 0);
                cnt1 = t->cnt;
                base = (B19aObjA *)((u8 *)t + 8);
                off = 0;
                if (cnt1 > 0) {
                    do {
                        a = (B19aObjA *)((u8 *)base + off);
                        pushed = 0;
                        if (a->info->flags4 & mask) {
                            a->owner = e->pp;
                            if (D_800D2980 == 0) func_00250950(a, v);
                            if ((a->flags & 8) && (a->info->flags14 & 4)) {
                                pushed = 1;
                                if (a->id == idx) {
                                    if (flag != 0) {
                                        c = ow->nA;
                                        if (c != 0x40) {
                                            ow->visA[c] = a;
                                            ow->nA = c + 1;
                                        }
                                    }
                                } else {
                                    c = ow->nA;
                                    if (c != 0x40) {
                                        ow->visA[c] = a;
                                        ow->nA = c + 1;
                                    }
                                }
                            }
                            if (ow->f1B928 == 0 || func_00297390((u8 *)ow + 0x1B6B4, e->a, e->b, k) != 0) {
                                if (a->mn[0] < v->mx[0] && v->mn[0] < a->mx[0] && a->mn[2] < v->mx[2] && v->mn[2] < a->mx[2] && a->mn[1] < v->mx[1] && v->mn[1] < a->mx[1] && func_00297B74((u8 *)v + 0x2F0, &a->mn[0]) != 0) {
                                    if ((a->flags & 8) && pushed == 0 && (a->id != idx || flag != 0)) {
                                        c = ow->nA;
                                        if (c != 0x40) {
                                            ow->visA[c] = a;
                                            ow->nA = c + 1;
                                        }
                                    }
                                    if (func_002500A4(a, v) != 0) {
                                        if (a->flags & 4) {
                                            c = ow->nB;
                                            if (c != 0x40) {
                                                ow->visB[c] = a;
                                                ow->nB = c + 1;
                                            }
                                        } else {
                                            func_0025021C(a, v);
                                        }
                                    }
                                    a->flags = a->flags & 0xFDFF;
                                } else {
                                    a->flags = a->flags | 0x200;
                                }
                            }
                        }
                        k++;
                        off += 0xE8;
                    } while (k < cnt1);
                }
                t = func_0028FD94((s32)grp, 1);
                cnt2 = t->cnt;
                pb = (B19aObjB *)((u8 *)t + 8);
                for (k = 0; k < cnt2; k++) {
                    p = pb + k;
                        p->owner = e->pp;
                    if (D_800D2980 == 0) func_0024F284(p, v);
                    if (p->info->flags4 & mask) {
                        u32 fl = p->flags;
                        if (!(fl & 1) && (vmask & p->mask) && p->mn[0] < v->mx[0] && v->mn[0] < p->mx[0] && p->mn[2] < v->mx[2] && v->mn[2] < p->mx[2] && p->mn[1] < v->mx[1] && v->mn[1] < p->mx[1] && (fl & 2) && func_00297B74((u8 *)v + 0x2F0, &p->mn[0]) != 0) {
                            if (p->flags & 0x20) {
                                c = ow->nB;
                                if (c != 0x40) {
                                    ow->visB[c] = p;
                                    ow->nB = c + 1;
                                }
                            } else {
                                func_0024EB80(p);
                            }
                        }
                    }
                }
            }
            i++;
        } while (i < n);
    }
    func_0026D9D0();
    if (ow->f1B928 != 0) {
        func_002536F4(0, ow->f1B6B0);
        func_002537D8(0, ow->f1B6B0);
    }
}
