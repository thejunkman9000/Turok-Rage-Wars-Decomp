#include "b07_types.h"

void func_0022C59C(ActorGroup *group)
{
    Actor *p;

    for (p = group->head; p != NULL; p = p->next) {
        if (AT(u8, p->stats, 0x90) == 1) {
            AT(u8, p->stats, 0x90) = 0;
        }
    }
}
