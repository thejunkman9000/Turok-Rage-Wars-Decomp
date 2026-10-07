#include "b01_types.h"

extern u8 D_8011FE88[];
void func_002671B0(Actor *a, Actor *b, s32 kind, Vec3f pos, B01Pair extra);
void func_00285D80(void *mgr, Actor *actor, s32 flag);

void func_00204F10(Actor *actor) {
    B01Pair extra;
    extra.a = 0;
    func_002671B0(actor, actor, 7, B01_POS(actor), extra);
    func_00285D80(D_8011FE88, actor, 0);
}
