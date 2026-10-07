#include "b02_types.h"

f32 func_0027272C(void *a, void *b);
s32 func_0020C078(B2Mgr *m, s32 a, s32 b, u8 kind, s32 depth, f32 *dist, f32 best);
extern f32 D_800C6E60;

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

s32 func_0020BE7C(B2Mgr *m, s32 a, u8 kind, s32 depth) {
    s32 res = -1;
    s32 i;
    s32 cnt;
    s32 r;
    s32 nb[64];
    s32 ei[64];
    f32 best = D_800C6E60;
    f32 dist;
    void *src;
    B2Edge *e;

    for (i = 0; i < m->count; i++) {
        e = getEdge(m, i);
        if (e->a == a) {
            if (e->kind == kind) {
                return a;
            }
        }
    }
    src = getRec0(m, a);
    cnt = adj(m, a, nb, ei);
    for (i = 0; i < cnt; i++) {
        dist = func_0027272C(src, getRec0(m, nb[i]));
        r = func_0020C078(m, a, nb[i], kind, depth - 1, &dist, best);
        if (r != -1) {
            best = dist;
            res = r;
        }
    }
    return res;
}
