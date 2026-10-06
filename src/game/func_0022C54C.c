#include "b07_types.h"
Actor *func_0022C54C(ActorGroup *group, u32 n)
{
    Actor *p = NULL;
    s32 i = 0;
    if (n < 8) {
        for (p = group->head; p != NULL; p = p->next) {
            if (AT(u8, p->stats, 0x90) == 0) {
                if (i == n) {
                    return p;
                }
                i++;
            }
        }
    }
    return p;
}
