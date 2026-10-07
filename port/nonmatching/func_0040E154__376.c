#include "o02_types.h"
typedef struct { u8 pad0[0x10]; u8 alpha; u8 pad11; u16 flags; s16 x, y; u16 w, h; s16 ox, oy; f32 sx, sy; } S_node;
typedef struct { s32 ox, oy; u32 flags; f32 sx, sy; u8 alpha; u8 pad15[3]; O02Rect clip; } S_ctx;
extern f32 D_800E10D0;
extern f32 D_800E10D4;
extern f32 D_800E10D8;
extern f32 D_800E10DC;
extern s32 D_800E2AB0;
extern s32 D_800E2AB4;
s32 func_0040E154(O02Rect *r0, O02Rect *r1, S_node *n, S_ctx *c) {
    u32 fl = n->flags;
    u32 cf = c->flags;
    f32 sx = c->sx;
    f32 sy = c->sy;
    s32 f800 = (u16)(fl & 0x800);
    s32 f400 = (u16)(fl & 0x400);
    s32 t6 = ((s16)n->w) >> 1;
    s32 t7 = ((s16)n->h) >> 1;
    s32 t0, t1, t2, t3, cx, cy;
    s32 v;
    if (!(cf & 0x4000)) {
        c->flags = cf | (fl & 0x140);
    }
    c->flags = c->flags | (n->flags & 0x609);
    if (n->alpha < 0xFF) {
        c->alpha = c->alpha * n->alpha / 255;
    }
    if (c->flags & 1) {
        c->alpha = c->alpha >> 1;
    }
    if (c->alpha == 0) return 0;
    if (!(n->flags & 8)) return 0;
    if (c->sx != D_800E10D0 || c->sy != D_800E10D0 || n->sx != D_800E10D0 || n->sy != D_800E10D0) {
        f32 a = ((f32)(n->x + n->ox) + (f32)(s16)n->w * D_800E10D4) * c->sx;
        f32 nsx = c->sx * n->sx;
        f32 b;
        f32 nsy;
        f32 d;
        b = ((f32)(n->y + n->oy) + (f32)(s16)n->h * D_800E10D4) * c->sy;
        c->sx = nsx;
        nsy = c->sy * n->sy;
        c->sy = nsy;
        t0 = (s32)a;
        t1 = (s32)b;
        t2 = (s32)((f32)(s16)n->w * nsx * D_800E10D4);
        d = (f32)(s16)n->h * nsy * D_800E10D4;
        r0->w[0] = t0 - t2 + c->ox;
        r0->w[1] = t0 + t2 + c->ox;
        t3 = (s32)d;
        r0->w[2] = t1 - t3 + c->oy;
        r0->w[3] = t1 + t3 + c->oy;
    } else {
        r0->w[0] = c->ox + n->x + n->ox;
        r0->w[2] = c->oy + n->y + n->oy;
        r0->w[1] = r0->w[0] + (s16)n->w - 1;
        r0->w[3] = r0->w[2] + (s16)n->h - 1;
        t2 = ((s16)n->w) >> 1;
        t3 = ((s16)n->h) >> 1;
    }
    cx = (s32)((f32)(n->x + (s16)n->w / 2) * sx);
    cy = (s32)((f32)(n->y + (s16)n->h / 2) * sy);
    if (f800) {
        if (f400) {
            r1->w[0] = r0->w[0];
            r1->w[1] = r0->w[1];
            r1->w[2] = r0->w[2];
            r1->w[3] = r0->w[3];
        } else {
            r1->w[0] = cx - t2 + c->ox;
            r1->w[2] = cy - t3 + c->oy;
            r1->w[1] = cx + t2 + c->ox;
            r1->w[3] = cy + t3 + c->oy;
        }
    } else {
        if (!f400) {
            if (sx != D_800E10D8) {
                v = (s32)((f32)n->x * sx) + c->ox;
            } else {
                v = n->x + c->ox;
            }
            r1->w[0] = v;
            r1->w[1] = r1->w[0] + (s16)n->w;
            if (sy != D_800E10DC) {
                v = (s32)((f32)n->y * sy) + c->oy;
            } else {
                v = n->y + c->oy;
            }
            r1->w[2] = v;
            r1->w[3] = r1->w[2] + (s16)n->h;
        } else {
            r1->w[0] = cx - t6 + n->ox + c->ox;
            r1->w[2] = cy - t7 + n->oy + c->oy;
            r1->w[1] = cx + t6 + n->ox + c->ox;
            r1->w[3] = cy + t7 + n->oy + c->oy;
        }
    }
    if (r1->w[0] < 0) {
        r1->w[0] = 0;
    } else if (D_800E2AB0 < r1->w[0]) {
        return 0;
    }
    if (r1->w[1] < 0) return 0;
    if (D_800E2AB0 < r1->w[1]) r1->w[1] = D_800E2AB0;
    if (r1->w[2] < 0) {
        r1->w[2] = 0;
    } else if (D_800E2AB4 < r1->w[2]) {
        return 0;
    }
    if (r1->w[3] < 0) return 0;
    if (D_800E2AB4 < r1->w[3]) r1->w[3] = D_800E2AB4;
    if (r1->w[0] >= r1->w[1]) r1->w[1] = r1->w[0] + 1;
    if (r1->w[2] >= r1->w[3]) r1->w[3] = r1->w[2] + 1;
    c->ox = r0->w[0];
    c->oy = r0->w[2];
    c->clip.w[0] = r0->w[0];
    c->clip.w[1] = r0->w[1];
    c->clip.w[2] = r0->w[2];
    c->clip.w[3] = r0->w[3];
    return 1;
}
