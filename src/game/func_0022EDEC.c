#include "b07_types.h"

extern s32 D_80146910;

void func_0025DE74(s32 id, f32 x, f32 y, f32 z, void *src, s32 a5);
void func_00218464(void *p);
void func_00214178(void *a, void *b, s32 c);
void func_0021B1E4(Actor *actor, s32 a1, s32 a2, s32 a3);
void func_002266E4(Actor *actor);

void func_0022EDEC(Actor *actor)
{
    AT(u8, actor->stats, 0x8F) = 1;
    switch (D_80146910) {
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
    func_00218464((u8 *)actor + 0x938);
    AT(s32, actor, 0x11B4) = 0;
    func_00214178((u8 *)actor + 0x2E8, (u8 *)actor + 0x458, 1);
    func_0021B1E4(actor, AT(s32, actor, 0x5EC), 0, 1);
    func_002266E4(actor);
}
