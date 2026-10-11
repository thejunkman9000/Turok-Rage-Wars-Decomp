#include "b17_types.h"
#include "r06_types.h"

extern u8 D_800C9C0C[];
extern s32 D_800D2850;
extern R06V3 D_80115E30[];
extern u8 D_8011FE88[];

s32 **func_002533DC();
void func_00277620();
void func_00277B08();
s32 func_00278090();
void func_002782E4();
void *func_0028FD94();
void *func_0028FDA8();
void *memcpy(void *, const void *, u32);

typedef struct M5Cell { f32 x0, z0, x1, z1; } M5Cell;
typedef struct M5Ent { s32 *a; M5Cell *cell; s32 pad8; } M5Ent;
typedef struct M5Grid {
    u8 pad0[0x1500];
    s32 n;
    u8 pad1504[4];
    M5Ent ent[1];
} M5Grid;

#define MN(a,b) ((a) < (b) ? (a) : (b))
#define MX(a,b) ((a) > (b) ? (a) : (b))
#define CL(x) MX(MN((x), 0xE1), 0x1E)

static inline void clampv(R06VBlk *b, u8 *out) {
    s32 i, n;
    R06Vtx *vp, *vq, *p;
    u8 *d, *o;

    i = 0;
    n = b->count;
    vp = b->v;
    if (i < n) {
        /* The ROM keeps the vertex base in v0 and copies it to the walker register a0 (`move a0,v0`)
           BEFORE `move t0,s6` (out -> walker).  Plain C gives the opposite order, because the walker init is
           a loop.c giv init (always emitted last) and combine folds a plain `vq = vp` copy into it.  The three
           empty asms (a) make vp conflict with a0, (b) keep vq out of v0/v1 (so local-alloc picks a0) and pin the
           order of the two copies, (c) keep the vq copy alive until after `o = out`. */
        __asm__ volatile("" : : : "$4");
        vq = vp;
        __asm__ volatile("" : : : "$2", "$3");
        o = out;
        __asm__ volatile("" : : "r"(vq));
        do {
            p = vq + i;
            d = o;
            o += 4;
            d[0] = CL(p->col[0]);
            d[1] = CL(p->col[1]);
            d[2] = CL(p->col[2]);
            i++;
        } while (i < n);
    }
}

s32 **func_00278530(s32 a0, s32 *h, Box3 *q0, s32 a3, s32 a4, u8 *ctx) {
    u8 sp18[0x100];
    struct { s32 cnt, size; } L;
    s32 ret;
    s32 cnt, cnt2, total, mag, lc;
    s32 i1, i2, i3, i4, i5;
    s32 **blk;
    R06VBlk *dst, *src;
    M5Grid *gp;
    u8 *cp;
    u8 *cp2;
    s32 *wp, *r;
    R06V3 *pt;
    R06Vtx *vp;
    volatile s32 *hdr;
    f32 x, y, z;
    s32 c, cc, ix, iy, iz;
    R06VBlk *msrc;
    s32 msz;

    cp = 0;
    ret = func_00278090(q0, h, sp18, &L.cnt, ctx);
    src = func_0028FDA8(a0, 0, &L.size);
    cnt = src->count;
    for (i1 = 0; i1 < cnt; i1++) {
        D_80115E30[i1].x = 0;
        D_80115E30[i1].y = 0;
        D_80115E30[i1].z = 0;
    }
    if (ret != 0) {
        blk = func_002533DC(0, L.size + 0x10 + src->count * 4, 0, D_800C9C0C);
        if (blk == 0) return 0;
        mag = 0xDEADBEEF;
        msrc = src;
        hdr = *blk;
        hdr[0] = 1;
        msz = L.size;
        hdr[1] = 0x10;
        hdr[3] = mag;
        hdr[2] = msz + 0x10;
        dst = (R06VBlk *)((u8 *)*blk + hdr[1]);
        cp = (u8 *)*blk + hdr[2];
    } else {
        blk = func_002533DC(0, L.size + 8, 0, D_800C9C0C);
        if (blk == 0) return 0;
        msrc = src;
        ((s32 *)*blk)[0] = 0;
        dst = (R06VBlk *)((u8 *)*blk + 8);
        msz = L.size;
    }
    memcpy(dst, msrc, msz);
    r = func_0028FD94(a0, 1);
    if (r[1] != 0) {
        wp = r + 2;
        pt = D_80115E30;
        for (i2 = 0; i2 < cnt; i2++) {
            c = wp[i2];
            x = pt[i2].x;
            y = pt[i2].y;
            z = pt[i2].z;
            ix = ((c & 0xFF0000) << 8) >> 23;
            iy = ((c << 16) >> 24) * 2;
            iz = (c << 24) >> 23;
            pt[i2].x = x + (f32)ix;
            pt[i2].y = y + (f32)iy;
            pt[i2].z = z + (f32)iz;
        }
    }
    if (D_800D2850 == 0) goto light;
    lc = L.cnt;
    if (lc != 0) goto call620;
    total = 0;
    gp = (M5Grid *)D_8011FE88;
    for (i3 = 0; i3 < gp->n; i3++) {
        total += ((s32 *)func_0028FD94(*gp->ent[i3].a, 2))[1];
    }
    if (total != 0) goto join;
    do {
light:
    func_00277B08(dst, a3, D_80115E30, a4);
    goto join;
call620:
    func_00277620(sp18, lc, dst, a3, D_80115E30, a4);
    } while (0);
join:
    func_002782E4(dst, D_80115E30);
    if (ret != 0) {
        clampv(dst, cp);
    }
    return blk;
}
