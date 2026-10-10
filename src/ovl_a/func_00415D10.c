#include "span_16E000/code_804143D8.h"
#include "types.h"
#include "common/types_8a8189af7b05.h"
#include "span_16E000/code_804143D8.h"
#include "gfx.h"
#include "gbi.h"
#include "decomp/argb_color.h"
#include "abi.h"
#include "span_C76B0/data.h"
#include "common/unused.h"
#include "n64sdk.h"

extern Gfx *D_80110634;
extern Triple D_80153F60;
extern void func_802A1898_de(s32 *, s32 *, s32 *, s32 *);

/* Clips a screen rectangle to the viewport func_802A1898_de reports, interpolating the four corner
   colours along each clipped edge, then writes the corners into vertices 0-3 with gSPModifyVertex
   (screen position, colour rotated to RGBA, texture coordinates 0) and draws them as an outline of
   four lines, or as two triangles when D_80153F60.y is set. */
/* Sets vertex index's screen position, colour and texture coordinates. */
static inline void put_vertex(s32 index, s32 x, s32 y, u32 color) {
    Gfx *g;

    g = D_80110634++;
    gSPModifyVertex(g, index, G_MWO_POINT_XYSCREEN, (x << 18) | ((y & 0xFFFF) << 2));
    g = D_80110634++;
    gSPModifyVertex(g, index, G_MWO_POINT_RGBA, (color << 8) | (color >> 24));
    g = D_80110634++;
    gSPModifyVertex(g, index, G_MWO_POINT_ST, 0);
}

void func_00415D10(f32 x, f32 y, f32 w, f32 h, u32 col0, u32 col1, u32 col2, u32 col3) {
    s32 left;
    s32 top;
    s32 right_edge;
    s32 bottom_edge;
    f32 right;
    f32 bottom;
    f32 t;
    f32 edge;
    ArgbColor *c0 = (ArgbColor *)&col0;
    ArgbColor *c1 = (ArgbColor *)&col1;
    ArgbColor *c2 = (ArgbColor *)&col2;
    ArgbColor *c3 = (ArgbColor *)&col3;

    right = (x + w) - 1.0f;
    bottom = (y + h) - 1.0f;
    func_802A1898_de(&left, &top, &right_edge, &bottom_edge);
    if ((f32)right_edge < x || (f32)bottom_edge < y || right < (f32)left || bottom < (edge = (f32)top)) {
        return;
    }
    if (y < edge) {
        t = (bottom - edge) / h;
        y = edge;
        c0->r = (u32)(c2->r - (c2->r - c0->r) * t);
        c0->g = (u32)(c2->g - (c2->g - c0->g) * t);
        c0->b = (u32)(c2->b - (c2->b - c0->b) * t);
        c0->a = (u32)(c2->a - (c2->a - c0->a) * t);
        c1->r = (u32)(c3->r - (c3->r - c1->r) * t);
        c1->g = (u32)(c3->g - (c3->g - c1->g) * t);
        c1->b = (u32)(c3->b - (c3->b - c1->b) * t);
        c1->a = (u32)(c3->a - (c3->a - c1->a) * t);
    }
    edge = (f32)bottom_edge;
    if (edge < bottom) {
        t = (edge - y) / h;
        bottom = edge;
        c2->r = (u32)(c0->r + (c2->r - c0->r) * t);
        c2->g = (u32)(c0->g + (c2->g - c0->g) * t);
        c2->b = (u32)(c0->b + (c2->b - c0->b) * t);
        c2->a = (u32)(c0->a + (c2->a - c0->a) * t);
        c3->r = (u32)(c1->r + (c3->r - c1->r) * t);
        c3->g = (u32)(c1->g + (c3->g - c1->g) * t);
        c3->b = (u32)(c1->b + (c3->b - c1->b) * t);
        c3->a = (u32)(c1->a + (c3->a - c1->a) * t);
    }
    edge = (f32)left;
    if (x < edge) {
        t = (right - edge) / w;
        x = edge;
        c0->r = (u32)(c1->r - (c1->r - c0->r) * t);
        c0->g = (u32)(c1->g - (c1->g - c0->g) * t);
        c0->b = (u32)(c1->b - (c1->b - c0->b) * t);
        c0->a = (u32)(c1->a - (c1->a - c0->a) * t);
        c2->r = (u32)(c3->r - (c3->r - c2->r) * t);
        c2->g = (u32)(c3->g - (c3->g - c2->g) * t);
        c2->b = (u32)(c3->b - (c3->b - c2->b) * t);
        c2->a = (u32)(c3->a - (c3->a - c2->a) * t);
    }
    edge = (f32)right_edge;
    if (edge < right) {
        t = (edge - x) / w;
        right = edge;
        c1->r = (u32)(c0->r + (c1->r - c0->r) * t);
        c1->g = (u32)(c0->g + (c1->g - c0->g) * t);
        c1->b = (u32)(c0->b + (c1->b - c0->b) * t);
        c1->a = (u32)(c0->a + (c1->a - c0->a) * t);
        c3->r = (u32)(c2->r + (c3->r - c2->r) * t);
        c3->g = (u32)(c2->g + (c3->g - c2->g) * t);
        c3->b = (u32)(c2->b + (c3->b - c2->b) * t);
        c3->a = (u32)(c2->a + (c3->a - c2->a) * t);
    }
    right += 1.0f;
    bottom += 1.0f;
    put_vertex(0, x, y, col0);
    put_vertex(1, x, bottom, col2);
    put_vertex(2, right, bottom, col3);
    put_vertex(3, right, y, col1);
    if (D_80153F60.y == 0) {
        gSPLine3D(D_80110634++, 0, 1, 0);
        gSPLine3D(D_80110634++, 1, 2, 0);
        gSPLine3D(D_80110634++, 2, 3, 0);
        gSPLine3D(D_80110634++, 3, 0, 0);
    } else {
        gSP2Triangles(D_80110634++, 0, 1, 2, 0, 2, 3, 0, 0);
    }
}
