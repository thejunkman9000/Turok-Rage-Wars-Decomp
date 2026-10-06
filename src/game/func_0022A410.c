#include "p1_types.h"
extern GameFlags D_801468A0[];
Actor *func_0022A410(ActorGroup *g) {
    Actor *a;
    if (D_801468A0->unk54 != 0 && D_801468A0->unk68 != 0) {
        return NULL;
    }
    for (a = g->head; a != NULL; a = a->next) {
        if (a->stats->unk8F == 1) {
            return a;
        }
    }
    return NULL;
}
