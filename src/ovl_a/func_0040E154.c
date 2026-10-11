#include "o02_types.h"

/* UI node rectangle transform: computes the node's screen rect (r0, 4 words x0,x1,y0,y1) and the clipped rect (r1) */
typedef struct { u8 pad0[0x10]; u8 alpha; u8 pad11; u16 flags; s16 x, y; u16 w, h; s16 ox, oy; f32 sx, sy; } S_node;
typedef struct { s32 ox, oy; u32 flags; f32 sx, sy; u8 alpha; u8 pad15[3]; O02Rect clip; } S_ctx;
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
    s32 t2, t3, cx, cy;

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
    if (c->alpha == 0) {
        return 0;
    }
    if (!(n->flags & 8)) {
        return 0;
    }
    if (c->sx != 1.0f || c->sy != 1.0f || n->sx != 1.0f || n->sy != 1.0f) {
        f32 a, b, d;
        a = (f32)(n->x + n->ox) + (f32)(s16)n->w * 0.5f;
        a = a * c->sx;
        b = (f32)(n->y + n->oy) + (f32)(s16)n->h * 0.5f;
        b = b * c->sy;
        cx = (s32)a;
        c->sx *= n->sx;
        c->sy *= n->sy;
        cy = (s32)b;
        t2 = (s32)((f32)(s16)n->w * c->sx * 0.5f);
        d = (f32)(s16)n->h * c->sy * 0.5f;
        t3 = (s32)d;
        r0->w[0] = cx - t2 + c->ox;
        r0->w[1] = cx + t2 + c->ox;
        r0->w[2] = cy - t3 + c->oy;
        r0->w[3] = cy + t3 + c->oy;
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
    if (f800 && f400) {
        *r1 = *r0;
    } else if (!f800 && !f400) {
        if (sx != 1.0f) {
            r1->w[0] = (s32)((f32)n->x * sx) + c->ox;
        } else {
            r1->w[0] = n->x + c->ox;
        }
        r1->w[1] = r1->w[0] + (s16)n->w;
        if (sy != 1.0f) {
            r1->w[2] = (s32)((f32)n->y * sy) + c->oy;
        } else {
            r1->w[2] = n->y + c->oy;
        }
        r1->w[3] = r1->w[2] + (s16)n->h;
    } else if (f800) {
        r1->w[0] = cx - t2 + c->ox;
        r1->w[2] = cy - t3 + c->oy;
        r1->w[1] = cx + t2 + c->ox;
        r1->w[3] = cy + t3 + c->oy;
    } else {
        r1->w[0] = cx - t6 + n->ox + c->ox;
        r1->w[2] = cy - t7 + n->oy + c->oy;
        r1->w[1] = cx + t6 + n->ox + c->ox;
        r1->w[3] = cy + t7 + n->oy + c->oy;
    }
    if (r1->w[0] < 0) {
        r1->w[0] = 0;
    } else if (D_800E2AB0 < r1->w[0]) {
        return 0;
    }
    if (r1->w[1] < 0) {
        return 0;
    }
    if (D_800E2AB0 < r1->w[1]) {
        r1->w[1] = D_800E2AB0;
    }
    if (r1->w[2] < 0) {
        r1->w[2] = 0;
    } else if (D_800E2AB4 < r1->w[2]) {
        return 0;
    }
    if (r1->w[3] < 0) {
        return 0;
    }
    if (D_800E2AB4 < r1->w[3]) {
        r1->w[3] = D_800E2AB4;
    }
    if (r1->w[1] <= r1->w[0]) {
        r1->w[1] = r1->w[0] + 1;
    }
    if (r1->w[3] <= r1->w[2]) {
        r1->w[3] = r1->w[2] + 1;
    }
    c->ox = r0->w[0];
    c->oy = r0->w[2];
    c->clip = *r0;
    return 1;
}
