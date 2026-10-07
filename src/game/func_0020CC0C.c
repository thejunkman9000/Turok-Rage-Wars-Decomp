#include "b02_types.h"

static inline B2Edge *getEdge(B2Mgr *m, s32 idx) {
    B2Pool *pool = m->pool8;

    return (B2Edge *)&pool->data[idx * pool->elemSize];
}

static inline s32 isBi(u8 kind) {
    switch (kind) {
    case 1:
    case 4:
    case 7:
        return 1;
    default:
        return 0;
    }
}

s32 func_0020CC0C(B2Mgr *m, s32 x, s32 y) {
    s32 i;
    B2Edge *e;

    for (i = 0; i < m->count; i++) {
        e = getEdge(m, i);
        if (e->a == x && e->b == y) {
            return i;
        }
        if (e->b == x && e->a == y && isBi(e->kind)) {
            return i;
        }
        if (e->b == x && e->a == y && e->kind == 6) {
            return i;
        }
    }
    return -1;
}
