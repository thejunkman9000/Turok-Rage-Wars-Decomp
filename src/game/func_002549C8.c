#include "p2_types.h"

extern PoolMgr D_80103F70;
extern PNode **D_80104564;
void func_00255C58(void *l, PNode *n);

PNode *func_002549C8(void *unused, u32 flags) {
    PNode *n;

    if (D_80103F70.cnt == 0) {
        return NULL;
    }
    D_80103F70.cnt--;
    n = D_80104564[D_80103F70.cnt];
    n->fC = 0x800;
    n->f8 = 0;
    n->key = 0;
    n->next = NULL;
    n->prev = NULL;
    n->f14 = 0;
    n->f10 = D_80103F70.f10;
    func_00255C58((u8 *)&D_80103F70 + 0x600, n);
    n->fC |= flags & 0xC;
    return n;
}