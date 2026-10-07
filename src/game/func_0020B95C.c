#include "b02_types.h"

f32 func_0027272C(void *a, void *b);

static inline void *getRec0(B2Mgr *m, s32 idx) {
    B2Pool *pool = m->pool0;

    return &pool->data[idx * pool->elemSize];
}

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

s32 func_0020B95C(B2Mgr *m, s32 a, s32 goal, s32 *out, s32 mode) {
    u8 *src;
    s32 i;
    s32 j;
    s32 k;
    s32 cnt;
    B2Edge *e;
    void *rj;
    void *ri;
    f32 d;
    s32 t;

    if (goal != -1) {
        src = getRec0(m, goal);
    } else {
        src = NULL;
    }
    k = 0;
    cnt = 0;
    for (; k < m->count; k++) {
        e = getEdge(m, k);
        if (mode != 0) {
            if (e->b == a) {
                out[cnt] = e->a;
                cnt++;
            }
            if (e->a == a) {
                if (isBi(e->kind)) {
                    out[cnt] = e->b;
                    cnt++;
                }
            }
            if (goal != -1 && e->a == a && e->b == goal && src != NULL && (*(u16 *)(src + 0xC) & 2)) {
                out[cnt] = goal;
                cnt++;
            }
        } else {
            if (e->a == a && e->kind != 6) {
                out[cnt] = e->b;
                cnt++;
            }
            if (e->b == a) {
                if (isBi(e->kind)) {
                    out[cnt] = e->a;
                    cnt++;
                }
            }
        }
    }
    if (goal == -1) {
        return cnt;
    }
    if (src != NULL) {
        for (i = 0; i < cnt - 1; i++) {
            for (j = i + 1; j < cnt; j++) {
                ri = getRec0(m, out[i]);
                rj = getRec0(m, out[j]);
                d = func_0027272C(src, ri);
                if (func_0027272C(src, rj) < d) {
                    t = out[i];
                    out[i] = out[j];
                    out[j] = t;
                }
            }
        }
    }
    return cnt;
}
