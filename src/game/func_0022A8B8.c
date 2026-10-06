#include "p1_types.h"
void func_0022A8B8(ActorGroup *g, f32 v) {
    Actor *a = g->head;
    while (a != NULL) {
        a->unk670 = v;
        a = a->next;
    }
}
