#include "b07_types.h"

typedef struct B07Row24 {
    s16 unk0;
    u8 pad2[0x16];
} B07Row24;

extern B07Row24 D_800CE8DC[];
extern u8 D_801462D5[];
extern ActorRow400 D_80102B00[];
extern u8 D_80145040[];
extern u8 D_80145088[];
extern s32 D_800D70E8;
extern f32 D_800C80BC;

s32 func_00222A80(Actor *actor, s32 weapon);
s32 func_0022F95C(Actor *actor);
s32 func_0022F54C(void *row, s32 idx);
void func_0025DF54(s32 id);
s32 func_0022A590(void *a, Actor *actor);
void func_002398F8(void *a, void *b, s32 c, s32 d, f32 e);
s32 func_002301E4(Actor *actor, ActorState *state);
void func_00214178(Actor *actor, ActorState *state, s32 id);

void func_0022B1A8(Actor *owner, s32 a1);

void func_002321B8(Actor *actor, ActorState *state)
{
    ActorState *st = state;
    Actor *owner = actor->owner;
    s32 kind = D_800CE8DC[AT(s16, owner, 0x650)].unk0;
    s32 ok;
    s32 v;
    s32 res;

    if (func_00222A80(owner, AT(s16, owner, 0x62E)) == 0) {
        AT(s16, owner, 0x770) = func_0022F95C(owner);
    }
    if (AT(u32, owner, 0x6AC) & 0x4000) {
        if (AT(f32, owner, 0x11D8) > 0) {
            ok = 0;
        } else if (owner->unk1450 != 0) {
            ok = 1;
        } else if (D_801462D5[0] != 1) {
            ok = 1;
        } else {
            res = func_0022F54C(&D_80102B00[owner->unk5D4], AT(s16, owner, 0x62E));
            if (res == 0) {
                func_0025DF54(0xD4D);
                if (AT(void *, owner, 0x5DC) != NULL) {
                    v = func_0022A590(D_80145040, owner);
                    func_002398F8(D_80145088, AT(void *, owner, 0x5DC), D_800D70E8, v, D_800C80BC);
                }
            }
            ok = res;
        }
        if (ok != 0) {
            AT(s32, st, 0x14C) = 1;
            if (AT(u32, owner, 0x6B0) & 0x2000) {
                func_0022B1A8(owner, 0);
                AT(s32, st, 0x150) = 1;
            }
            goto check;
        }
    }
    if (AT(s32, st, 0x14C) != 0) {
        if (AT(s32, st, 0x150) == 0) {
            func_0022B1A8(owner, 1);
            AT(s32, st, 0x14C) = 0;
        } else {
            AT(s32, st, 0x150) = 0;
            AT(s32, st, 0x14C) = 0;
        }
    }
check:
    if (func_002301E4(actor, st) == 0 && !(actor->flags & 0x400)) {
        func_00214178(actor, st, kind);
    }
}
