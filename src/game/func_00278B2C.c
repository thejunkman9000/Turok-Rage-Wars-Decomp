#include "b17_types.h"

extern SessMgr D_8011FE88[];
SumNode *func_0028FD94(s32 h, s32 n);

s32 func_00278B2C(void) {
    s32 i, sum;
    SessMgr *s = D_8011FE88;

    i = 0;
    sum = 0;
    for (; i < s->count; i++) {
        SumNode *n = func_0028FD94(*s->ent[i].p, 2);
        sum += n->val;
    }
    return sum;
}
