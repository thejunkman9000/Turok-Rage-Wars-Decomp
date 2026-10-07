#include "o02_types.h"
s32 func_0040F508(O02Rect *a, O02Rect *b) {
    s32 ok = 1;
    s32 x0, x1, y0, y1;
    x0 = a->w[0];
    if (x0 < b->w[0]) x0 = b->w[0];
    a->w[0] = x0;
    x1 = a->w[1];
    if (b->w[1] < x1) x1 = b->w[1];
    a->w[1] = x1;
    y0 = a->w[2];
    if (y0 < b->w[2]) y0 = b->w[2];
    a->w[2] = y0;
    y1 = a->w[3];
    if (b->w[3] < y1) y1 = b->w[3];
    a->w[3] = y1;
    if (a->w[1] < a->w[0] + 1) {
        a->w[1] = a->w[0] + 1;
        ok = 0;
    }
    if (a->w[3] < a->w[2] + 1) {
        a->w[3] = a->w[2] + 1;
        ok = 0;
    }
    return ok;
}
