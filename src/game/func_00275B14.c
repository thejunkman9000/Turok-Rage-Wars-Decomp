#include "b17_types.h"

void func_00275B14(TriDst *d, TriSrc *s, Rec16 *verts, s32 unused, Rec32 *edges) {
    s32 i;

    d->w0 = s->w0;
    d->w2 = s->w2;
    d->p1C = s->p10;
    for (i = 0; i < 3; i++) {
        d->v[i] = verts + s->vi[i];
        if (s->ei[i] == 0xFFFF) {
            d->e[i] = 0;
        } else {
            d->e[i] = edges + s->ei[i];
        }
    }
}
