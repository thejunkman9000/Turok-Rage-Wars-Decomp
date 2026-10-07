#include "b03_types.h"

void func_002106E0(ActorB *a, s32 step);
void func_00210964(ActorB *a, s32 step);
s32 func_00210E88(BrainB *b) {
    if (b == NULL) goto L;
    if (b->actor == NULL) goto L;
    if (b->step >= 8) { b->step = 0; L: return 1; }
    func_002106E0(b->actor, b->step);
    func_00210964(b->actor, b->step);
    b->step++;
    return 0;
}
