#include "b23_types.h"

s32 func_002A2DE4(StateObj *o) {
    SubNode *n = o->list;

    o->unk5C = 2;
    o->unk48 = 0;
    for (; n != 0; n = n->next) {
        if (n->unkE != 8) {
            n->unk10 = 0x64;
        }
    }
    return 0;
}
