#include "b01_types.h"

typedef struct B01Evt6 {
    u8 pad0[6];
    u16 unk6;
} B01Evt6;

extern u8 D_8011FE88[];
void func_002065C0(B01Actor *actor, B01State *state, u16 arg);
void func_002472E0(B01Actor *actor);
void func_00285D80(void *mgr, B01Actor *actor, s32 flag);

void func_0020676C(B01Actor *actor, B01State *state, B01Evt6 *evt) {
    func_002065C0(actor, state, evt->unk6);
    actor->flags |= 0x2100;
    func_002472E0(actor);
    func_00285D80(D_8011FE88, actor, 0);
}
