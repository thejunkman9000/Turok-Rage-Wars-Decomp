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
extern f32 D_800C80A0;
extern f32 D_800C80A4;

s32 func_00222A80(Actor *actor, s32 weapon);
s32 func_0022F95C(Actor *actor);
s32 func_0022F54C(void *row, s32 idx);
void func_0025DF54(s32 id);
s32 func_0022A590(void *a, Actor *actor);
void func_002398F8(void *a, void *b, s32 c, s32 d, f32 e);
s32 func_002301E4(Actor *actor, ActorState *state);
void func_00214178(Actor *actor, ActorState *state, s32 id);
void func_0025DE74(s32 id, f32 x, f32 y, f32 z, void *src, s32 a5);

void func_0023195C(Actor *actor, ActorState *state)
{
    s32 xx;
    Actor *owner = actor->owner;
    s32 kind = D_800CE8DC[AT(s16, owner, 0x650)].unk0;
    s32 ok;
    s32 res;
    s32 v;
    u8 *g;

    AT(s32, state, 0x13C) = 1;
    if (func_00222A80(owner, AT(s16, owner, 0x62E)) == 0) {
        AT(s16, owner, 0x770) = func_0022F95C(owner);
        return;
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
                    xx = D_800D70E8;
                    func_002398F8(D_80145088, AT(void *, owner, 0x5DC), xx, v, D_800C80A0);
                }
            }
            ok = res;
        }
        if (ok != 0) {
            if (owner->unk5E4 != 0) {
                if (AT(s16, owner, 0x5F4) >= 0x19) {
                    func_0025DE74(0x42E, AT(f32, owner, 0x8), AT(f32, owner, 0xC), AT(f32, owner, 0x10),
                                  (u8 *)owner + 8, -1);
                    func_00214178(actor, state, 0xB);
                    return;
                }
                if (AT(u32, owner, 0x6B0) & 0x4000) {
                    func_0025DF54(0xD4D);
                    if (AT(void *, owner, 0x5DC) != NULL) {
                        g = D_80145040;
                        v = func_0022A590(g, owner);
                        xx = D_800D70E8;
                        func_002398F8(g + 0x48, AT(void *, owner, 0x5DC), xx, v, D_800C80A4);
                    }
                }
                return;
            }
        }
    }
    if (func_002301E4(actor, state) == 0 && !(actor->flags & 0x400)) {
        func_00214178(actor, state, kind);
    }
}
