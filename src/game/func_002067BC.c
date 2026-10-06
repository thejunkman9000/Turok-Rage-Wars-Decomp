#include "p1_types.h"
extern u8 D_8011FE88[];
void func_00285D80(void *p, Actor *actor, s32 c);
void func_002067BC(Actor *actor) {
    actor->flags &= ~0x2000;
    actor->flags &= ~0x100;
    func_00285D80(D_8011FE88, actor, 1);
}
