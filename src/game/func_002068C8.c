#include "b01_types.h"

extern u8 D_8011FE88[];
void func_402FB4(Actor *actor, s32 arg);
void func_00285D80(void *mgr, Actor *actor, s32 flag);

void func_002068C8(Actor *actor, void *unused, s32 arg) {
    func_402FB4(actor, arg);
    actor->flags |= 0x2100;
    func_00285D80(D_8011FE88, actor, 0);
}
