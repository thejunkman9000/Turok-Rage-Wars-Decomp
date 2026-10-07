#include "b02_types.h"

static inline B2Edge *getEdge(B2Mgr *m, s32 idx) {
    B2Pool *pool = m->pool8;

    return (B2Edge *)&pool->data[idx * pool->elemSize];
}

s32 func_0020CCE8(B2Mgr *m, s32 key, s32 *outV, s32 *outI) {
    s32 k;
    s32 cnt;
    B2Edge *e;

    cnt = k = 0;
    for (; k < m->count; k++) {
        e = getEdge(m, k);
        if (e->a == key) {
            outV[cnt] = e->b;
            outI[cnt] = k;
            cnt++;
        }
        if (e->b == key) {
            outV[cnt] = e->a;
            outI[cnt] = k;
            cnt++;
        }
    }
    return cnt;
}
