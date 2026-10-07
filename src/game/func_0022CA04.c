#include "b07_types.h"

extern f32 D_800C7E50;
extern f32 D_800C7E54;
extern s32 D_8013B2BC;
extern B07Game D_801468A0[];

void *func_0024E690(ActorState *state);
void func_0024E6C8(void *p, Vec3f *out);
void func_00271FA4(void *out, void *a, Vec3f *b);
void func_0025DE74(s32 id, f32 x, f32 y, f32 z, void *src, s32 a5);

void func_0022CA04(Actor *actor, ActorState *state)
{
    f32 k = D_800C7E50;
    void *p;
    Vec3f v;

    if (D_8013B2BC == 0x1DB1) {
        k = D_800C7E54;
    }
    AT(f32, state, 0x20) = k * AT(f32, AT(u8 *, state, 0x18), 0x20);
    p = func_0024E690(state);
    if (p != NULL) {
        func_0024E6C8(p, &v);
        func_00271FA4((u8 *)state + 0x1C, (u8 *)state + 0x1C, &v);
    }
    if (AT(u8, actor->stats, 0x8F) == 1) {
        if (D_801468A0->unk54 != 0) {
            switch (D_801468A0->unk70) {
            case 0:
                func_0025DE74(0x18A1, AT(f32, actor, 0x8), AT(f32, actor, 0xC), AT(f32, actor, 0x10),
                              (u8 *)actor + 8, -1);
                break;
            case 1:
                func_0025DE74(0x1969, AT(f32, actor, 0x8), AT(f32, actor, 0xC), AT(f32, actor, 0x10),
                              (u8 *)actor + 8, -1);
                break;
            case 2:
                func_0025DE74(0x1905, AT(f32, actor, 0x8), AT(f32, actor, 0xC), AT(f32, actor, 0x10),
                              (u8 *)actor + 8, -1);
                break;
            }
        }
    }
}
