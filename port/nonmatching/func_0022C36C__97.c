#include "b07_types.h"
extern u8 D_801462DE;
extern f32 D_800C7E28;
extern f32 D_800C7E2C;
extern s32 D_800E28D0;
extern s32 D_800E28D4;
void func_002AA224(u8 a0);
void func_002ABC18(s32 a0, s32 a1, s16 a2, s16 a3, f32 a4, f32 a5, s32 a6);
void func_0022C36C(Actor *actor, u8 *obj)
{
    f32 c, d, sx, sy;
    func_002AA224(D_801462DE);
    sy = AT(f32, obj, 0x2A0);
    sx = AT(f32, obj, 0x29C);
    c = sx / (f32)D_800E28D0;
    d = sy / (f32)D_800E28D4;
    func_002ABC18(0x201, (s32)AT(f32, actor, 0x7BC),
                  (s16)(AT(f32, obj, 0x2A4) + sx + c * D_800C7E28),
                  (s16)(AT(f32, obj, 0x2A8) + sy + d * D_800C7E28),
                  c, d * D_800C7E2C, 1);
}
