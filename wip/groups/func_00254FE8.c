#include "b12_types.h"

extern B12Mgr D_80103F70;

B12Node *func_00254FE8(s32 unused, B12List *l, B12Node **out) {
    B12Node *n = (B12Node *)l->tail;
    if (*out == 0) {
        for (; n; n = n->link18) {
            if (!(n->flags & 0x702)) {
                if ((D_80103F70.stamp - n->unk10) >= 5) {
                    return n;
                }
                *out = n;
                break;
            }
        }
    }
    for (; n; n = n->link18) {
        if (!(n->flags & 0x702) && !((D_80103F70.stamp - n->unk10) < 5)) {
            return n;
        }
    }
    return 0;
}
