#include "b07_types.h"

extern f32 D_800C8138;
extern f32 D_800C813C;
extern s32 D_801450B8;
extern u8 *D_800D052C[];

void func_002227D0(Actor *actor, Actor *state, s32 kind);
void func_0021A9A4(Actor *owner, s32 id);
void func_00214178(Actor *actor, ActorState *state, s32 id);
void func_0022AE90(Actor *owner, s32 id);
void func_0022AF64(Actor *owner, s32 id);

void func_002331EC(Actor *actor, ActorState *state)
{
    Actor *owner = actor->owner;
    Actor *o2;

    if (AT(s32, state, 0x13C) == 2) {
        func_002227D0(owner, owner, 2);
        return;
    }
    AT(f32, state, 0x64) = D_800C8138;
    if (owner->unk1450 == 0 && D_801450B8 == 1) {
        func_0021A9A4(actor->owner, 0x3FB);
    } else {
        func_0021A9A4(actor->owner, 0x4CD);
    }
    func_00214178(actor, state, 4);
    func_0022AE90(owner, 0x977);
    func_0022AF64(owner, 0x974);
    o2 = actor->owner;
    AT(f32, state, 0x130) = AT(f32, D_800D052C[AT(s16, o2, 0x62E)], 0x18) * D_800C813C;
    if (AT(s16, o2, 0x62E) == 8 && o2->unk11C0 == 0) {
        func_0022AF64(o2, 0xA3C);
    }
}
