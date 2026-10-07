#include "b02_types.h"

void *func_0020C994(B2Mgr *ref, s32 idx) {
    B2Pool *pool = ref->pool0;

    return &pool->data[idx * pool->elemSize];
}
