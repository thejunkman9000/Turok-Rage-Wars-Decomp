#include "b07_types.h"

extern u8 D_800CE7E4[];
extern u8 D_800CE730[];
extern u8 D_800CED30[];
extern f32 D_800C7E68;
extern f32 D_800C7E6C;

void func_002748E0(void *p, f32 a, f32 b);
void func_002231B0(Actor *actor, ActorState *state, void *tbl);
void func_002233CC(Actor *actor, ActorState *state, void *tbl);
s32 func_0024E61C(void *p);
void func_002227D0(Actor *actor, ActorState *state, s32 kind);
f32 func_0024E668(void *p, s32 a);

void func_0022CC24(Actor *actor, ActorState *state)
{
    f32 x;

    func_002748E0((u8 *)actor + 0x72C, 0.0f, 0.25f);
    func_002231B0(actor, state, D_800CE7E4);
    if (!(AT(u32, actor, 0x660) & 0x8000)) {
        func_002233CC(actor, state, D_800CE730);
    }
    x = AT(f32, state, 0x20);
    if (x <= 0.0f) {
        if (func_0024E61C(state) != 0) {
            func_002227D0(actor, state, 2);
        }
        x = AT(f32, state, 0x20);
    }
    if (x <= 0.0f) {
        if (func_0024E668(state, 0) < 0.0f ? -func_0024E668(state, 0) < D_800C7E68
                                          : func_0024E668(state, 0) < D_800C7E6C) {
            if (AT(u8 *, actor, 0x13B4) == D_800CED30) {
                AT(s32, actor, 0x86C) = 0x5E2E;
            } else {
                AT(s32, actor, 0x86C) = 0x7F8;
            }
        }
    }
}
