#include "b12_types.h"

extern B12Mgr D_80103F70;
void func_00255E78(B12List *l, B12Node *n);

void func_00254A70(s32 unused, B12Node *n) {
    func_00255E78(&D_80103F70.lists[0], n);
    if (n->flags & 0x1000) {
        func_00255E78(&D_80103F70.lists[1], n);
    }
    if (D_80103F70.cur == n) {
        D_80103F70.cur = 0;
    }
    n->flags = 0;
    D_80103F70.stk[D_80103F70.cnt] = n;
    D_80103F70.cnt++;
}
