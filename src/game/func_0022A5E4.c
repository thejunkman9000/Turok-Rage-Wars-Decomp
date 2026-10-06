#include "p1_types.h"
Actor *func_0022A5E4(ActorGroup *g, u32 idx) {
    Actor *a = NULL;
    s32 i = 0;
    if (idx < 8) {
        for (a = g->head; a != NULL; a = a->next, i++) {
            if (i == idx) {
                return a;
            }
        }
    }
    return a;
}
