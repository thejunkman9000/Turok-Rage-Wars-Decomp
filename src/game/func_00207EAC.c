#include "b02_types.h"

void func_00285D80(void *p, B2Actor *actor, s32 on);
extern u8 D_8011FE88[];

void func_00207EAC(B2Actor *actor) {
    func_00285D80(D_8011FE88, actor, 1);
    actor->flags |= 0x100;
}
