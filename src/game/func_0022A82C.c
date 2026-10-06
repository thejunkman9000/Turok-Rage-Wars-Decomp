#include "b06_types.h"

Actor *func_0022A82C(ActorGroup *g) {
    Actor *a;
    for (a = g->head; a != NULL; a = a->next) {
        if (a->stats->unk8F == 1 || B6F(a->stats, u8, 0x90) == 1) {
            return a;
        }
    }
    return a;
}
