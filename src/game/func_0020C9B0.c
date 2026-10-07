#include "b02_types.h"

void *func_0020C9B0(B2Mgr *ref, s32 idx) {
    B2Pool *pool = ref->pool8;

    return &pool->data[idx * pool->elemSize];
}
