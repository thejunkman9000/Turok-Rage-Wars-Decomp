#include "b06_types.h"

void func_00285D00(u8 *p);

void func_0022A870(ActorGroup *g) {
    Actor *a;
    for (a = g->head; a != NULL; a = a->next) {
        func_00285D00(B6F(a, u8 *, 0x698) + 0x140);
        B6F(B6F(a, u8 *, 0x698), s32, 0xD0) = 0;
    }
}
