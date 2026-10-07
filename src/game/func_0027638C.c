#include "b17_types.h"

void func_0027638C(TNode *n, f32 val, u16 id) {
    if (n->id == id) {
        if (n->s0->v != val || n->s1->v != val || n->s2->v != val) {
            n->s0->v = val;
            n->s1->v = val;
            n->s2->v = val;
            if (n->c0) {
                func_0027638C(n->c0, val, id);
            }
            if (n->c1) {
                func_0027638C(n->c1, val, id);
            }
            if (n->c2) {
                func_0027638C(n->c2, val, id);
            }
        }
    }
}
