#include "b07_types.h"

void func_002266E4(Actor *actor);

void func_0022C5CC(ActorGroup *group)
{
    Actor *p;

    for (p = group->head; p != NULL; p = p->next) {
        AT(u8, p->stats, 0x8F) = 0;
        func_002266E4(p);
    }
}
