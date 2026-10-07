#include "b19b_types.h"
extern void *memcpy(void *, const void *, u32);
void func_0026D980();
void func_0026D9D0(void);
void func_00250458(void *, s32);
void *func_00250754(void *, s32);
s32 func_00250A0C(void *);
s32 func_00250A34(void *);
void **func_00250ACC(void *, s32, s32, void **);
void **func_002518DC(s32, s32, s32, s32, s32, void *, void *, void *, s32);
void **func_002533DC(s32, s32, s32, void *);
void func_00253610(s32, void *);
void func_002536F4(s32, void *);
void func_00270980(void *, void *);
void func_00272908(void *, void *, void *);
void func_0028795C();
B19bTab *func_0028FD94(void *, s32);
s32 func_0028FE1C(s32, s32, s32, s32 *);
extern B19bDl *D_80110634;
extern u8 D_800CA300[];
extern u8 D_800CA31C[];

void func_00288908(B19bLvl *lv) {
    u8 mtx[0x40];
    B19bV3f in;
    B19bV3f out;
    void *pa[3000];
    void *pb[512];
    s32 tmp;
    s32 cntA, ci, lastA, lastC, cntC;
    B19bE14 *e4;
    s32 cnt;
    void **pbp;
    B19bDl *start;
    s32 row;
    void **fp;
    B19bDl *g0, *g1, *g2, *g3, *g4, *g5, *g6;
    s32 nBytesA, nBytesB, nBytesC, off1, off2;
    void **hp;
    s32 **blk;
    B19bTab *t;
    B19bEnt *ent, *ents;
    s32 i, j, k;
    void **sub;
    f32 y, m;

    fp = pa;
    pbp = pb;
    ci = 0;
    start = D_80110634;
    g0 = D_80110634++;
    g0->w0 = 0xE7000000;
    g0->w1 = 0;
    g1 = D_80110634++;
    g1->w0 = 0xE3000A01;
    g1->w1 = 0x100000;
    g2 = D_80110634++;
    g2->w0 = 0xDB040004;
    g2->w1 = 2;
    g3 = D_80110634++;
    g3->w0 = 0xDB04000C;
    g3->w1 = 2;
    g4 = D_80110634++;
    g4->w0 = 0xDB040014;
    g4->w1 = 0xFFFE;
    g5 = D_80110634++;
    g5->w0 = 0xDB04001C;
    g5->w1 = 0xFFFE;
    func_0026D980();
    cntA = func_0028FD94(lv->root, 0)->cnt;
    cntC = func_0028FD94(lv->root, 2)->cnt;
    e4 = (B19bE14 *)func_0028FD94(lv->root, 4)->ent;
    lastC = cntC - 1;
    lastA = cntA - 1;
    ci = 0;
    row = 0;
    {
        for (; lastC >= ci; ) {
            j = 0;
            {
                for (; lastA >= j; ) {
                    if (e4[j + row].f10 == 0) {
                        i = func_0028FE1C(lv->f64, lv->f30, j + row, &tmp);
                        hp = func_002518DC(0, i, i, tmp, 4, lv, func_0028795C, D_800CA300, 1);
                        if (hp != 0) {
                            blk = (s32 **)*hp;
                            if (*blk != 0) {
                                func_00253610(0, hp);
                                *fp = hp;
                                fp++;
                                t = func_0028FD94(blk, 0);
                                k = 0;
                                cnt = t->cnt;
                                ents = (B19bEnt *)t->ent;
                                {
                                    for (; k < cnt; ) {
                                        ent = &ents[k];
                                        if (!(ent->fD8 & 0x40)) {
                                            ent->f20 = hp;
                                            if ((ent->fD8 & 4) || func_00250A0C(ent) < 0) {
                                                *pbp = ent;
                                                pbp++;
                                            } else {
                                                fp = func_00250ACC(ent, func_00250A0C(ent), func_00250A34(ent), fp);
                                                func_00250458(ent, 0);
                                            }
                                            sub = func_00250754(ent, func_00250A34(ent));
                                            if (sub != 0) {
                                                s32 n;
                                                B19bTab *vt;
                                                s32 vi = 0;
                                                vt = func_0028FD94(*sub, 0);
                                                n = vt->cnt;
                                                func_00270980(mtx, ent->f28);
                                                if (n > 0) {
                                                    do {
                                                        B19bV3s *v = (B19bV3s *)((u8 *)vt + (vi * vt->f0 + 8));
                                                        in.x = v->x;
                                                        in.y = v->y;
                                                        in.z = v->z;
                                                        func_00272908(mtx, &in, &out);
                                                        y = out.y;
                                                        m = lv->minY;
                                                        if (!(y <= m)) y = m;
                                                        vi++;
                                                        lv->minY = y;
                                                    } while (vi < n);
                                                }
                                                func_002536F4(0, sub);
                                            }
                                        }
                                        k++;
                                    }
                                }
                            }
                            func_002536F4(0, hp);
                        }
                    }
                    j++;
                }
            }
            row += cntA;
            ci++;
        }
    }
    *fp = 0;
    fp++;
    *pbp = 0;
    pbp++;
    func_0026D9D0();
    nBytesA = (u8 *)fp - (u8 *)pa;
    off1 = ((nBytesA + 7) & ~7) + 0x18;
    nBytesB = (u8 *)pbp - (u8 *)pb;
    off2 = off1 + ((nBytesB + 7) & ~7);
    g6 = D_80110634++;
    g6->w0 = 0xDF000000;
    g6->w1 = 0;
    nBytesC = (u8 *)D_80110634 - (u8 *)start;
    hp = func_002533DC(0, off2 + ((nBytesC + 7) & ~7), 3, D_800CA31C);
    lv->hp = (s32 **)hp;
    lv->blob = *(s32 **)hp;
    lv->blob[0] = 3;
    lv->blob[1] = 0x18;
    lv->blob[2] = off1;
    lv->blob[3] = off2;
    memcpy(func_0028FD94(lv->blob, 0), pa, nBytesA);
    memcpy(func_0028FD94(lv->blob, 1), pb, nBytesB);
    memcpy(func_0028FD94(lv->blob, 2), start, nBytesC);
    D_80110634 = start;
}
