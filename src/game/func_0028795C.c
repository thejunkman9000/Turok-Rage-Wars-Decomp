#include "b19b_types.h"
extern void *memcpy(void *, const void *, u32);
s32 func_00285150(s32 ***, s32);
B19bTab *func_0028FD94(void *, s32);
void **func_00254420(s32, s32 ***, s32);
void func_00253CB0(s32, s32 ***, void **);
void func_0028FEEC(B19bTab *, void *, s32);
s32 func_0028FE08(s32, s32, u16);
void func_0024F940(void *, void *, s32, s32 *, f32);
void func_0024FD4C(void *, void *, s32, s32 *);
void func_0024E980(void *, void *, s32, s32 *);
void func_00276D20(void *, void *);
f32 func_0024D274(void *);
s32 func_0028FD70(void *);
void func_0028FDD8(B19bTab *, s32);
void func_0028994C(void **, s32, f32 *, void *);
extern f32 D_800CA2F8;

void func_0028795C(B19bCtx *c, s32 ***arg1) {
    B19bTab * tE;
    void *ptrs[128];
    void **pp;
    f32 pos[3];
    B19bTab * tA;
    B19bTab * tB;
    B19bTab * tC;
    B19bTab * tD;
    u8 * base;
    B19bTab * tAux;
    B19bTab * t;
    s32 nA;
    s32 nB;
    s32 nC;
    s32 nD;
    s32 n;
    s32 szAB;
    s32 szC;
    s32 szD;
    s32 szE;
    s32 tot;
    s32 x4;
    s32 tt;
    register s32 szx asm("$2");
    s32 i;
    s32 j;
    s32 k;
    s32 bit;
    s32 m;
    u8 *pbits;
    s32 key;
    s32 off;
    s32 sn;
    s32 * root;
    B19bBlob * blob;
    u8 * sec;
    u8 * secC;
    u8 * secD;
    B19bItemE * itemsA;
    B19bItemD * itemsD;
    B19bSrcA * pA;
    B19bSrcC * pC;
    u8 *nv;
    B19bSrcD * pD;
    f32 scale;
    B19bSrcB *qb;
    B19bItemE *qa; B19bSrcA *qpa; B19bSrcB *qpb; B19bItemC *qic; B19bSrcC *qpc; B19bItemD *qid; B19bSrcD *qpd; s32 v;
    B19bSrcB * pB;
    B19bItemC * itemsC;
    s32 * aux;
    void ** hp;
    if (func_00285150(arg1, 1) != 0) {
        root = **arg1;
        tA = func_0028FD94(root, 0);
        nA = tA->cnt;
        tB = func_0028FD94(root, 1);
        nB = tB->cnt;
        n = nA + nB;
        szAB = n * 0xE8 + 8;
        tC = func_0028FD94(root, 2);
        nC = tC->cnt;
        szx = nC * 0x1C8;
        szC = szx + 8;
        tD = func_0028FD94(root, 3);
        nD = tD->cnt;
        szD = (nD * 0xC0) | 8;
        tE = func_0028FD94(root, 4);
        x4 = *(s32 *)tE * 4;
        tot = szC + 0x18;
        tt = szAB + tot;
        szE = (x4 + 0xF) & ~7;
        hp = func_00254420(0, arg1, tt + szD + szE);
        if (hp != 0) {
            blob = *hp;
            off = 0x18;
            sn = 1;
            sec = (u8 *)blob + off;
            blob->n = 0;
            blob->off[0] = off;
            func_0028FEEC(tA, sec, 1);
            func_0028FEEC(tB, sec, 1);
            nv = tA->ent;
            ((B19bSec *)sec)->stride = 0xE8;
            ((B19bSec *)sec)->cnt = n;
            tAux = func_0028FD94(c->f6C, 2);
            pB = (B19bSrcB *)tB->ent;
            itemsA = (B19bItemE *)((u8 *)blob + 0x20);
            base = (u8 *)blob;
            aux = (s32 *)tAux->ent;
            pA = (B19bSrcA *)nv;
            i = 0;
            if (nA > 0) {
                do {
                    func_0024F940(&itemsA[i], &pA[i], func_0028FE08(c->f54, c->f24, pA[i].f8), aux, *c->fl);
                    i++;
                } while (i < nA);
            }
            if (nB > 0) {
                qb = pB;
                j = 0;
                do {
                    func_0024FD4C(&itemsA[j + nA], qb, func_0028FE08(c->f54, c->f24, qb->f28), aux);
                    qb++;
                    j++;
                } while (j < nB);
            }
            off += szAB;
            blob->n = sn;
            sn++;
            secC = base + off;
            blob->off[blob->n] = off;
            func_0028FEEC(tC, secC, 1);
            ((B19bSec *)secC)->stride = 0x1C8;
            ((B19bSec *)secC)->cnt = nC;
            itemsC = (B19bItemC *)(secC + 8);
            pC = (B19bSrcC *)tC->ent;
            k = 0;
            if (nC > 0) {
                do {
                    func_0024E980(&itemsC[k], &pC[k], func_0028FE08(c->f54, c->f24, pC[k].f14), aux);
                    bit = itemsC[k].f19E;
                    key = c->key;
                    t = func_0028FD94(func_0028FD94(func_0028FD94(c->root, 0), key), 1);
                    do {} while (0);
                    func_0028FD94(t, 0);
                    func_0028FDD8(t, 1);
                    pbits = (u8 *)func_0028FD94(t, 1);
                    m = 1 << (bit & 7);
                    if (pbits[bit / 8] & m) itemsC[k].f19C |= 1;
                    k++;
                } while (k < nC);
            }
            off += szC;
            blob->n = sn;
            sn++;
            secD = base + off;
            blob->off[blob->n] = off;
            func_0028FEEC(tD, secD, 1);
            ((B19bSec *)secD)->stride = 0xC0;
            i = 0;
            ((B19bSec *)secD)->cnt = nD;
            pD = (B19bSrcD *)tD->ent;
            itemsD = (B19bItemD *)(secD + 8);
            if (nD > 0) {
                qpd = pD;
                qid = itemsD;
                do {
                    do { func_00276D20(qid, qpd); } while (0);
                    qpd++;
                    qid++;
                    i++;
                } while (i < nD);
            }
            off += szD;
            blob->n = sn;
            sn++;
            blob->off[blob->n] = off;
            memcpy(base + off, tE, func_0028FD70(tE));
            do {} while (0);
            blob->n = sn;
            sn++;
            off += szE;
            blob->off[blob->n] = off;
            i = 0;
            if (nD > 0) {
                pp = ptrs;
                qpd = (B19bSrcD *)itemsD;
                do {
                    *pp++ = qpd;
                    qpd = (B19bSrcD *)((u8 *)qpd + 192);
                    i++;
                } while (i < nD);
            }
            do { do { k = 0; } while (0); } while (0);
            if (nC > 0) {
                scale = D_800CA2F8;
                do {
                    pos[0] = itemsC[k].f8;
                    pos[1] = itemsC[k].fC + func_0024D274(&itemsC[k]) * scale;
                    pos[2] = itemsC[k].f10;
                    func_0028994C(ptrs, nD, pos, itemsC[k].f1A8);
                    k++;
                } while (k < nC);
            }
        }
        func_00253CB0(0, arg1, hp);
    }
}
