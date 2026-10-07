#include "r05_types.h"

extern f32 D_800C9208;
extern f32 D_800C920C;
extern f32 D_800C9210;
extern f32 D_800C9214;
extern f32 D_800C9218;
extern f32 D_800C921C;
extern f32 D_8010EC70;
extern s32 D_8010EC74;
extern s32 D_8010EC78;
extern f32 D_8010EC7C;
extern f32 D_8010EC80;
extern s32 D_8010EC84;
extern s32 D_8010EC88;

void *memcpy(void *d, void *s, u32 n);
s32 func_00285150(void *p, s32 x);
void *func_0028FD94(void *t, s32 i);
void *func_0028FDA8(void *t, s32 i, s32 *size);
void *func_00254420(s32 a, void *p, s32 size, s32 n);
s32 func_0025F0F4(void *a, void *t, s32 n, s32 m, s32 blur, s32 kind);
void func_002537D8(s32 a, void *p);
void func_00253CB0(s32 a, void *p, void *q);

static inline s32 TabSlot_(R05Tab *t) {
    s32 i;
    for (i = 0; i <= t->n; i++) {
        if (t->off[i] == 0xDEADBEEF) {
            break;
        }
    }
    i--;
    return i;
}

static inline void TabPut_(R05Tab *t, void *src, s32 size) {
    s32 i = TabSlot_(t);
    t->off[i + 1] = t->off[i] + size;
    if (src != 0) {
        memcpy((u8 *)t + t->off[i], src, size);
    }
}

static inline void TabAdd_(R05Tab *t, s32 size) {
    s32 i = TabSlot_(t);
    t->off[i + 1] = t->off[i] + size;
}

static inline void TabInit_(R05Tab *t, s32 n, s32 first) {
    s32 i;
    t->n = n;
    t->off[0] = first;
    for (i = 1; i <= n; i++) {
        t->off[i] = 0xDEADBEEF;
    }
}

void func_0025F58C(void *unused, R05Src **pp)
{
    s32 sz0, sz1, sz2, sz3, sz4, sz5, sz6, sz7, sz8;
    R05Tab *root;
    s32 total;
    void *d0, *d1, *d2, *d3, *d4, *d6;
    R05Grid *g;
    R05Tab *blk;
    R05Tab *out;
    R05Tab *sub;
    R05Cfg *cfg;
    void *p1;
    void *p2;
    void *p3;
    void *p4;
    s32 w;
    s32 tA, tB, fp;
    s32 ok;
    f32 t;
    void *res;

    if (func_00285150(pp, 1) != 0) {
        root = (*pp)->root;
        total = (*pp)->total;
        d0 = func_0028FDA8(root, 0, &sz0);
        d1 = func_0028FDA8(root, 1, &sz1);
        d2 = func_0028FDA8(root, 2, &sz2);
        d3 = func_0028FDA8(root, 3, &sz3);
        d4 = func_0028FDA8(root, 4, &sz4);
        blk = func_0028FDA8(root, 5, &sz5);
        g = func_0028FD94(blk, 0);
        func_0028FDA8(blk, 1, &sz6);
        func_0028FDA8(blk, 2, &sz7);
        d6 = func_0028FDA8(root, 6, &sz8);
        func_0028FD94(d3, 0);
        w = g->w;
        D_8010EC84 = w;
        D_8010EC88 = w;
        g->f18 = (f32)w;
        g->f1C = D_800C920C;
        if (w >= 2) {
            t = (f32)(w - 1);
            g->f1C = t / t;
        }
        tB = ((g->cntB * 16) * D_8010EC88) + ((g->cntB * 4 + 0xF) & ~7);
        tA = ((g->cntA * 16) * D_8010EC88) + ((g->cntA * 4 + 0xF) & ~7);
        fp = tA + tB + 0x38;
        out = func_00254420(0, pp, (total - sz5) + fp + sz8, D_8010EC88);
        res = out;
        if (out != 0) {
            R05Tab *tb = *(R05Tab **)out;
            TabInit_(tb, 7, 0x28);
            TabPut_(tb, d0, sz0);
            TabPut_(tb, d1, sz1);
            TabPut_(tb, d2, sz2);
            TabPut_(tb, d3, sz3);
            TabPut_(tb, d4, sz4);
            {
                s32 i = TabSlot_(tb);
                tb->off[i + 1] = tb->off[i] + fp;
                sub = (R05Tab *)((u8 *)tb + tb->off[i]);
            }
            TabInit_(sub, 3, 0x18);
            TabPut_(sub, g, 0x20);
            TabAdd_(sub, tB);
            TabAdd_(sub, tA);
            TabPut_(tb, d6, sz8);
            cfg = func_0028FD94(blk, 0);
            p1 = func_0028FD94(blk, 1);
            p2 = func_0028FD94(blk, 2);
            p3 = func_0028FD94(sub, 1);
            p4 = func_0028FD94(sub, 2);
            D_8010EC78 = 1;
            D_8010EC74 = 0;
            D_8010EC7C = D_800C9210;
            D_8010EC80 = D_800C9214;
            D_8010EC70 = cfg->unkC;
            if (func_0025F0F4(p1, p3, cfg->cntB, 3, cfg->unk0, cfg->unk8) == 0) {
                ok = 0;
            } else {
                D_8010EC78 = 0;
                D_8010EC74 = 1;
                D_8010EC7C = D_800C9218;
                D_8010EC80 = D_800C921C;
                D_8010EC70 = cfg->unkC;
                ok = func_0025F0F4(p2, p4, cfg->cntA, 4, cfg->unk0, cfg->unk8) != 0;
            }
            if (ok == 0) {
                func_002537D8(0, out);
                res = 0;
            }
        }
        func_00253CB0(0, pp, res);
    }
}
