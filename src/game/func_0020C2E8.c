#include "b02_types.h"

f32 func_00272768(void *a, void *b);
extern const f32 D_800C6E68;
extern const f32 D_800C6E6C;

static inline void *getRec0(B2Mgr *m, s32 idx) {
    B2Pool *pool = m->pool0;

    return &pool->data[idx * pool->elemSize];
}

static inline B2Edge *getEdge(B2Mgr *m, s32 idx) {
    B2Pool *pool = m->pool8;

    return (B2Edge *)&pool->data[idx * pool->elemSize];
}

static inline s32 adj(B2Mgr *m, s32 key, s32 *nb, s32 *ei) {
    s32 k;
    s32 cnt;
    B2Edge *e;

    cnt = k = 0;
    for (; k < m->count; k++) {
        e = getEdge(m, k);
        if (e->a == key) {
            nb[cnt] = e->b;
            ei[cnt] = k;
            cnt++;
        }
        if (e->b == key) {
            nb[cnt] = e->a;
            ei[cnt] = k;
            cnt++;
        }
    }
    return cnt;
}

f32 func_0020C2E8(B2Mgr *m, B2Edge2 *obj) {
    s32 nb[64];
    s32 ei[64];
    f32 best;
    f32 d;
    void *src;
    B2Edge *e;
    s32 i;
    s32 j;
    s32 cnt;
    s32 key;

    best = D_800C6E68;
    src = getRec0(m, obj->id0);
    for (i = 0; i < 64; i++) {
        if (m->slots[i] != -1) {
            d = func_00272768(src, getRec0(m, m->slots[i]));
            if (d < best || best == D_800C6E68) {
                best = d;
            }
        }
    }
    for (i = 0; i < 64; i++) {
        nb[i] = -1;
        ei[i] = -1;
    }
    key = obj->id0;
    cnt = adj(m, key, nb, ei);
    for (j = 0; j < cnt; j++) {
        e = getEdge(m, ei[j]);
        if (e->kind == 9 && e->a == obj->id0) {
            src = getRec0(m, e->b);
            for (i = 0; i < 64; i++) {
                if (m->slots[i] != -1) {
                    d = func_00272768(src, getRec0(m, m->slots[i]));
                    if (d < best || best == D_800C6E6C) {
                        best = d;
                    }
                }
            }
        }
    }
    return best;
}
