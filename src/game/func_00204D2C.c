#include "b01_types.h"

extern s32 D_8011FE88[];
extern u8 D_8013BA80[];
void func_002671B0(B01Actor *a, B01Actor *b, s32 kind, Vec3f pos, B01Pair extra);
void func_00285D80(void *mgr, B01Actor *actor, s32 flag);
void func_00278DE8(B01Actor *actor, s32 flags, B01Actor *actor2);
void func_002A6D28(void *p, B01Actor *actor);

void func_00204D2C(B01Actor *actor) {
    B01Pair extra;
    extra.a = 0;
    func_00285D80(D_8011FE88, actor, 0);
    func_00278DE8(actor, 0x8000, actor);
    func_002A6D28(D_8013BA80, actor);
    if (D_8011FE88[0] != 4) {
        func_002671B0(actor, actor, 7, actor->pos, extra);
        actor->flags |= 0x8000000;
    }
}
