#include "b02_types.h"

s32 func_0020D1CC(B2Mgr *m, s32 i, s32 j) {
    B2Pool *pool = m->unk10;

    return (&pool->data[0] + (i * m->unk4 + j) * pool->elemSize)[0];
}
