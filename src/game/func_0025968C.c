#include "b13_types.h"

void func_0025B718(SndVoice *v, SndMgr *m, s32 idx);

void func_0025968C(SndNode *n, SndMgr *m) {
    n->link.next = &n->link;
    n->link.prev = &n->link;
    func_0025B718(&n->body, m, -1);
}
