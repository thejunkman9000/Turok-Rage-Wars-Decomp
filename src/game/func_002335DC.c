#include "b08_types.h"

typedef struct Ptr168 {
    u8 pad0[0x168];
    f32 unk168;
} Ptr168;

typedef struct PlayerA {
    u8 pad0[0x698];
    Ptr168 *unk698;
} PlayerA;

void func_002748E0(f32 *p, f32 a, f32 b);

extern f32 D_800C8148;
extern f32 D_800C814C;
extern f32 D_800C8150;
extern f32 D_800C8154;
extern f32 D_800C8158;
extern f32 D_800C815C;
extern f32 D_800C8160;
extern f32 D_800C8164;
extern s32 D_800CF518;

void func_002335DC(Actor *actor, ActorState *state) {
    PlayerA *p;
    Ptr168 *q;
    s32 c;

    p = (PlayerA *)actor->owner;
    if (*(s8 *)&state->pad34 == 5) {
        func_002748E0(&state->unk128.f, (f32)D_800CF518 * D_800C8148, 0.4f);
    } else {
        func_002748E0(&state->unk128.f, 0.0f, 0.4f);
    }
    q = p->unk698;
    if (!((state->unk128.f < 0.0f) ? (D_800C8150 < -state->unk128.f * D_800C814C) : (D_800C8158 < state->unk128.f * D_800C8154))) {
        if (state->unk128.f < 0.0f) {
            q->unk168 = -state->unk128.f * D_800C815C;
        } else {
            q->unk168 = state->unk128.f * D_800C8160;
        }
    } else {
        q->unk168 = D_800C8164;
    }
}
