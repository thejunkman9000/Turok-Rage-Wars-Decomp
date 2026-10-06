#include "b24_types.h"

void func_002A72AC(Emit *e) {
    EmitNode *n;
    f32 acc;
    if (e->unk4C > 0.0f) {
        n = e->list;
        acc = 0.0f;
        while (n != NULL) {
            n->unkA8 = acc / e->unk4C;
            acc += n->unkAC;
            n = n->next;
        }
    }
}
