#include "o02_types.h"
typedef struct { s32 w[11]; } S_h2c;
typedef struct {
    S_h2c h;                       /* 0x00: node header, copied to the cell */
    u8 pad2C[0x44 - 0x2C];
    s32 *cells;                    /* 0x44 */
    u8 b48, b49, b4A, b4B, b4C, b4D, b4E, b4F, b50, b51, b52, b53, b54, b55, b56, b57;
    s32 *colw;                     /* 0x58 */
    s32 *rowh;                     /* 0x5C */
} S_grid;
typedef struct {
    S_h2c h;
    u8 b2C, b2D, b2E, b2F;
    u8 pad30[8];
    s32 f38;
    u8 pad3C[0x14 - 0x3C + 0x3C];
} S_cell;
typedef struct {
    u8 pad0[0x14];
    u16 f14, f16, f18, f1A;
    u8 pad1C[0x2C - 0x1C];
    u8 b2C, b2D, b2E, b2F;
    u8 pad30[8];
    s32 f38;
} S_cell2;
void func_0041234C(S_grid *g, S_cell2 *cell, u32 row, u32 col) {
    s32 *p;
    s32 c, r, ci, ri, sx, sy, n, i;
    u8 lim, lim2;
    *(S_h2c *)cell = g->h;
    cell->b2C = g->b54;
    cell->b2D = g->b55;
    lim = g->b51;
    if (col < lim) {
        c = col;
        cell->b2C = g->b52;
        cell->b2D = g->b53;
        ci = -1;
        if (c != 0) ci = c - 1;
    } else {
        ci = -1;
        c = (col - lim) + g->b4F;
        if (lim != 0) ci = col;
    }
    lim = g->b50;
    if (row < lim) {
        r = row;
        cell->b2C = g->b52;
        cell->b2D = g->b53;
        ri = -1;
        if (r != 0) ri = r - 1;
    } else {
        ri = -1;
        r = (row - lim) + g->b4E;
        if (lim != 0) ri = row;
    }
    sy = sx = 0;
    n = ci;
    if (g->b51 < ci) n = g->b51;
    if (ci != -1) {
        i = 0;
        if (i < n) {
            do {
                sx += g->colw[i];
                i++;
            } while (i < n);
        }
    }
    n = ri;
    if (g->b50 < ri) n = g->b50;
    if (ri != -1) {
        i = 0;
        if (i < n) {
            do {
                sy += g->rowh[i];
                i++;
            } while (i < n);
        }
    }
    lim = g->b51;
    if (lim < ci) sx += (ci - lim) * g->colw[lim - 1];
    lim2 = g->b50;
    if (lim2 < ri) sy += (ri - lim2) * g->rowh[lim2 - 1];
    if (col < lim) {
        cell->f18 = ((u16 *)g->colw)[col * 2 + 1];
    } else {
        cell->f18 = ((u16 *)g->colw)[lim * 2 - 1];
    }
    if (row < g->b50) {
        cell->f1A = ((u16 *)g->rowh)[row * 2 + 1];
    } else {
        cell->f1A = ((u16 *)g->rowh)[g->b50 * 2 - 1];
    }
    cell->f38 = g->cells[(r * g->b4B + c) * 2];
    if (r == g->b4C && c == g->b4D) {
        cell->b2E = g->b56;
        cell->b2F = g->b57;
    } else {
        cell->b2E = cell->b2C;
        cell->b2F = cell->b2D;
    }
    cell->f14 += sx;
    cell->f16 += sy;
}
