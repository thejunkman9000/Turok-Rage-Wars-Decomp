#include "b12_types.h"

extern s32 D_800D2B28;
extern s32 D_800D2B1C;

void func_002551C8(B12Port *p) {
    while (p->q.validCount != 0) {
        osSetThreadPri(&p->thread, D_800D2B28);
    }
    osSetThreadPri(&p->thread, D_800D2B1C);
}
