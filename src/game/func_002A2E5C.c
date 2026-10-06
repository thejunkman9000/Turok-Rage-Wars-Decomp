#include "b23_types.h"

void func_0025DF54(s32 a);

s32 func_002A2E5C(StateObj *o) {
    SubNode *n;

    o->unk5C = 2;
    o->unk48 = 0;
    func_0025DF54(0xE74);
    n = o->list;
    for (; n != 0; n = n->next) {
        if (n->unkE != 8) {
            n->unk10 = 100;
        }
    }
    return 0;
}
