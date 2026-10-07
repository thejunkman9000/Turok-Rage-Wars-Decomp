#include "m03_types.h"

typedef struct M03FCtx {
    /* 0x00 */ u8 pad0[0x40];
    /* 0x40 */ u32 *flags;
} M03FCtx;
typedef struct M03FDef { s32 type; } M03FDef;
typedef struct M03FEnt {
    /* 0x00 */ f32 pts[24];
    /* 0x60 */ f32 f60;
    /* 0x64 */ u8 pad64;
    /* 0x65 */ u8 b65;
    /* 0x66 */ u8 pad66[6];
    /* 0x6C */ u32 mask;
} M03FEnt;
typedef struct M03FTbl { s32 stride; s32 count; } M03FTbl;
typedef struct M03FObj {
    /* 0x000 */ u8 pad0[1];
    /* 0x001 */ s8 b1;
    /* 0x002 */ u8 pad2[0x16];
    /* 0x018 */ M03FDef *def;
    /* 0x01C */ u8 pad1C[0x34];
    /* 0x050 */ f32 f50;
    /* 0x054 */ f32 f54;
    /* 0x058 */ f32 f58;
    /* 0x05C */ u8 pad5C[0x18];
    /* 0x074 */ u8 m74[0x40];
    /* 0x0B4 */ u8 padB4[4];
    /* 0x0B8 */ u8 *mtbl;
    /* 0x0BC */ u8 padBC[8];
    /* 0x0C4 */ s32 wC4;
    /* 0x0C8 */ u8 padC8[8];
    /* 0x0D0 */ s32 wD0;
    /* 0x0D4 */ u8 padD4[0x14];
    /* 0x0E8 */ f32 bb0;
    /* 0x0EC */ f32 bb1;
    /* 0x0F0 */ f32 bb2;
    /* 0x0F4 */ f32 bb3;
    /* 0x0F8 */ f32 bb4;
    /* 0x0FC */ f32 bb5;
    /* 0x100 */ u8 pad100[0x7C];
    /* 0x17C */ u32 mask;
} M03FObj;

extern u8 D_800C87F8[];
s32 func_0023DA90(M03FCtx *c, f32 *box, s32 *out);
void func_0023F740(M03FCtx *c, f32 *box, M03FObj *o, s32 a2, f32 *pts, M03FEnt *e, s32 i);
s32 *func_0024BFC4(M03FObj *o, s32 idx);
s32 *func_002518DC(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, u8 *h, s32 i);
void func_002536F4(s32 a, s32 *p);
void func_00270980(void *m, u8 *src);
void func_002729B4(void *m, void *in, f32 *out, s32 n);
void func_002734EC(void *m, f32 a, f32 b, f32 c);
M03FTbl *func_0028FD94(s32 n, s32 i);

void func_0023FD08(M03FCtx *c, M03FObj *o, s32 a2, f32 *box) {
    f32 out[24];
    f32 pts[24];
    M03V3 ctr;
    f32 m[16];
    f32 bx[6];
    s32 tmp;
    s32 n;
    s32 flag;
    s32 i;
    s32 big;
    s32 *h;
    s32 *h2;
    M03FTbl *t;
    M03FEnt *e;
    f32 k;
    f32 sc;
    f32 r;
    f32 mx;
    f32 *nb;
    f32 *bb;
    s32 type;
    s32 off;
    s16 *bone;
    f32 *op;

    flag = 0;
    if ((*c->flags & 0x20000) && ((type = o->def->type, type == 1) || type == 4)) {
        flag = 1;
    }
    big = 0;
    if (o->mtbl != 0) {
        h = func_0024BFC4(o, o->b1);
    } else {
        h = 0;
    }
    if (h != 0) {
        mx = o->f54;
        if (!(o->f50 <= mx)) {
            mx = o->f50;
        }
        sc = o->f58;
        if (!(mx <= sc)) {
            sc = mx;
        }
        t = func_0028FD94(*h, 5);
        n = t->count;
        i = 0;
        if (n > 0) {
            k = 1.5f;
            do {
                e = (M03FEnt *)((u8 *)t + (i * t->stride + 8));
                if (e->mask & o->mask) {
                    if (flag != 0) {
                        type = e->b65 & 3;
                        big = 0;
                        if (type < 4) {
                            big = (u32)~type >> 31;
                        }
                    }
                    bone = (s16 *)(o->mtbl + (i << 6));
                    ctr.x = bone[12];
                    ctr.y = bone[13];
                    ctr.z = bone[14];
                    r = e->f60 * sc + 1.0f;
                    if (big != 0) {
                        r *= k;
                    }
                    bx[0] = ctr.x - r;
                    bx[1] = ctr.y - r;
                    bx[2] = ctr.z - r;
                    bx[3] = ctr.x + r;
                    bx[4] = ctr.y + r;
                    bx[5] = ctr.z + r;
                    if (box[0] < bx[3] && bx[0] < box[3] && box[2] < bx[5] && bx[2] < box[5] && box[1] < bx[4] &&
                        bx[1] < box[4] && func_0023DA90(c, bx, &tmp) != 0) {
                        func_00270980(m, o->mtbl + (i << 6));
                        if (big != 0) {
                            func_002734EC(m, k, k, k);
                        }
                        func_002729B4(m, e, out, 8);
                        func_0023F740(c, box, o, a2, out, e, i);
                    }
                }
                i++;
            } while (i < n);
        }
        func_002536F4(0, h);
        return;
    }
    h2 = func_002518DC(0, o->wC4, o->wC4, o->wD0, 4, 0, 0, D_800C87F8, 1);
    bb = &o->bb0;
    if (h2 != 0) {
        nb = (f32 *)func_0028FD94(*h2, 0);
        pts[0] = nb[0];
        pts[1] = nb[1];
        pts[2] = nb[2];
        pts[3] = nb[3];
        pts[4] = nb[1];
        pts[5] = nb[2];
        pts[6] = nb[3];
        pts[7] = nb[1];
        pts[8] = nb[5];
        pts[9] = nb[0];
        pts[10] = nb[1];
        pts[11] = nb[5];
        pts[12] = nb[0];
        pts[13] = nb[4];
        pts[14] = nb[2];
        pts[15] = nb[3];
        pts[16] = nb[4];
        pts[17] = nb[2];
        pts[18] = nb[3];
        pts[19] = nb[4];
        pts[20] = nb[5];
        pts[21] = nb[0];
        pts[22] = nb[4];
        pts[23] = nb[5];
        func_002729B4(o->m74, pts, out, 8);
        func_002536F4(0, h2);
    } else {
        out[0] = o->bb0;
        op = out;
        op[1] = bb[1];
        op[2] = bb[2];
        op[3] = bb[3];
        op[4] = bb[1];
        op[5] = bb[2];
        op[6] = bb[3];
        op[7] = bb[1];
        op[8] = bb[5];
        op[9] = o->bb0;
        op[10] = bb[1];
        op[11] = bb[5];
        op[12] = o->bb0;
        op[13] = bb[4];
        op[14] = bb[2];
        op[15] = bb[3];
        op[16] = bb[4];
        op[17] = bb[2];
        op[18] = bb[3];
        op[19] = bb[4];
        op[20] = bb[5];
        op[21] = o->bb0;
        op[22] = bb[4];
        op[23] = bb[5];
    }
    func_0023F740(c, box, o, a2, out, 0, -1);
}
