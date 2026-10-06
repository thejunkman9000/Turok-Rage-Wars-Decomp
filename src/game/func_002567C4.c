#include "b12_types.h"

void func_002567C4(P3Lock *l) {
    l->count = 0;
    osCreateMesgQueue(&l->q, &l->buf, 1);
}
