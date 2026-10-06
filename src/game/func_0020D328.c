#include "b02_types.h"

s32 func_0020D328(B2Mgr *m) {
    B2Node *n;

    for (n = m->head; n != NULL; n = n->next) {
        if (n->unk28 == 1) {
            return 1;
        }
    }
    return 0;
}
