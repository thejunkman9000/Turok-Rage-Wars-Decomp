#include "b02_types.h"

f32 func_0027272C(void *a, void *b);
s32 func_0020C078(B2Mgr *m, s32 a, s32 b, u8 kind, s32 depth, f32 *dist, f32 best);
extern f32 D_800C6E64;

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

s32 func_0020C078(B2Mgr *m, s32 cur, s32 goal, u8 kind, s32 depth, f32 *dist, f32 limit) {
    f32 best = D_800C6E64;
    s32 res = -1;
    s32 i = 0;
    s32 cnt;
    s32 r;
    s32 nb[64];
    s32 ei[64];
    f32 d;
    void *src;
    void *rec;
    B2Edge *e;

    for (; i < m->count; i++) {
        e = getEdge(m, i);
        if (e->a == goal && e->kind == kind) {
            return goal;
        }
    }
    if (depth == 0) {
        return -1;
    }
    src = getRec0(m, cur);
    cnt = adj(m, cur, nb, ei);
    for (i = 0; i < cnt; i++) {
        rec = getRec0(m, nb[i]);
        if (rec != src) {
            d = *dist + func_0027272C(src, rec);
            if (d < limit) {
                r = func_0020C078(m, goal, nb[i], kind, depth - 1, &d, limit);
            } else {
                r = -1;
            }
            if (r != -1 && d < best) {
                best = d;
                res = r;
            }
        }
    }
    if (best < limit) {
        *dist = best;
    }
    return res;
}
