#include "o02_types.h"
typedef struct S_func_00412D20 { u8 pad[0x44]; void *f44; } S_func_00412D20;
void func_00254784(void *p);
s32 func_00412D20(S_func_00412D20 *p) {
    S_func_00412D20 *q = p;
    void *c = q->f44;
    if (c) {
        func_00254784(c);
    }
    func_00254784(q);
    return 0;
}
