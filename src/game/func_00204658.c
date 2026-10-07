#include "b01_types.h"

extern s32 D_800CD4C0;
extern s32 D_8011FE88[];
extern u8 D_8013BA80[];
void func_00278DE8(B01Actor *actor, s32 flags, B01Actor *actor2);
void func_00285D80(void *mgr, B01Actor *actor, s32 flag);
void func_002A6D28(void *p, B01Actor *actor);

void func_00204658(B01Actor *actor) {
    B01Def *def = actor->def;
    func_00285D80(D_8011FE88, actor, 1);
    if (D_800CD4C0 == 0) {
        func_00278DE8(actor, 0x80000, actor);
    }
    func_002A6D28(D_8013BA80, actor);
    if (D_8011FE88[0] != 4) {
        actor->flags |= 0x8000000;
        if (def->flags14 & 2) {
            actor->flags &= ~0x2000;
            actor->flags &= ~0x100;
        }
        if (actor->def->unk28 == 0) {
            actor->flags &= ~0x100;
        }
    }
}
