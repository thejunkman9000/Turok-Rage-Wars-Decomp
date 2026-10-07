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

s32 **func_00278530(s32 a0, s32 *h, Box3 *q, s32 a3, s32 a4, u8 *ctx) {
    u8 sp18[0x100];
    struct { s32 cnt, size, ret; } L;
    s32 i, cnt, total, k;
    s32 **blk;
    R06VBlk *dst, *src;
    u8 *cols;
    s32 *wp;
    R06V3 *pt;
    R06Vtx *vp;
    s32 *hdr;
    f32 x, y, z;
    s32 w, c, r;

    cols = 0;
    L.ret = func_00278090(q, h, sp18, &L.cnt, ctx);
    src = func_0028FDA8(a0, 0, &L.size);
    cnt = src->count;
    for (i = 0; i < cnt; i++) {
        D_80115E30[i].x = 0;
        D_80115E30[i].y = 0;
        D_80115E30[i].z = 0;
    }
    if (L.ret != 0) {
        blk = func_002533DC(0, L.size + src->count * 4 + 0x10, 0, D_800C9C0C);
        if (blk == 0) return 0;
        hdr = *blk;
        hdr[0] = 1;
        hdr[1] = 0x10;
        hdr[3] = 0xDEADBEEF;
        hdr[2] = L.size + 0x10;
        dst = (R06VBlk *)((u8 *)*blk + hdr[1]);
        cols = (u8 *)*blk + hdr[2];
    } else {
        blk = func_002533DC(0, L.size + 8, 0, D_800C9C0C);
        if (blk == 0) return 0;
        ((s32 *)*blk)[0] = 0;
        dst = (R06VBlk *)((u8 *)*blk + 8);
    }
    memcpy(dst, src, L.size);
    {
        s32 *r = func_0028FD94(a0, 1);
        if (r[1] != 0) {
            wp = r + 2;
            for (i = 0; i < cnt; i++) {
                c = *wp;
                wp++;
                pt = &D_80115E30[i];
                x = pt->x;
                y = pt->y;
                z = pt->z;
                pt->x = x + (f32)(((c & 0xFF0000) << 8) >> 23);
                pt->y = y + (f32)(((c << 16) >> 24) * 2);
                pt->z = z + (f32)((c << 24) >> 23);
            }
        }
    }
    if (D_800D2850 != 0) {
        if (L.cnt == 0) {
            s32 ***hp;
            total = 0;
            hp = (s32 ***)(D_8011FE88 + 0x1508);
            for (i = 0; i < ((R06WTab *)D_8011FE88)->n; i++) {
                total += ((s32 *)func_0028FD94(**hp, 2))[1];
                hp += 3;
            }
            if (total == 0) goto light;
        } else {
            func_00277620(sp18, L.cnt, dst, a3, D_80115E30, a4);
        }
    } else {
    light:
        func_00277B08(dst, a3, D_80115E30, a4);
    }
    func_002782E4(dst, D_80115E30);
    if (L.ret != 0) {
        cnt = dst->count;
        vp = dst->v;
        for (i = 0; i < cnt; i++) {
            u8 *q = cols;
            cols = q + 4;
            c = vp->col[0];
            r = ((u32)c < 0xE1 && (c & 0xFF) < 0x1F) ? 0x1E : ((u32)c < 0xE1 ? c : 0xE1);
            q[0] = r;
            c = vp->col[1];
            r = ((u32)c < 0xE1 && (c & 0xFF) < 0x1F) ? 0x1E : ((u32)c < 0xE1 ? c : 0xE1);
            q[1] = r;
            c = vp->col[2];
            r = ((u32)c < 0xE1 && (c & 0xFF) < 0x1F) ? 0x1E : ((u32)c < 0xE1 ? c : 0xE1);
            q[2] = r;
            vp++;
        }
    }
    return blk;
}