#include "p1_types.h"
extern f32 D_800C6E90;
TimedNode *func_0020D28C(TimedList *list) {
    TimedNode *n;
    TimedNode *best;
    f32 min;
    min = D_800C6E90;
    best = NULL;
    for (n = list->head; n != NULL; n = n->next) {
        if (n->unk28 == 1 && (n->unk24 < min || min == D_800C6E90)) {
            best = n;
            min = n->unk24;
        }
    }
    if (best != NULL) {
        best->unk28 = 0;
    }
    return best;
}
