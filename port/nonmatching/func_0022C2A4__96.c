#include "b07_types.h"
extern u8 D_801462DE;
extern f32 D_800C7E20;
extern f32 D_800C7E24;
extern s32 D_800E28D0;
extern s32 D_800E28D4;
void func_002AA224(u8 a0);
void func_002ABC18(s32 a0, s32 a1, s16 a2, s16 a3, f32 a4, f32 a5, s32 a6);
void func_0022C2A4(s32 a0, u8 *obj)
{
    f32 ax, ay, c, d, x, y;
    func_002AA224(D_801462DE);
    ax = AT(f32, obj, 0x29C) * D_800C7E20;
    ay = AT(f32, obj, 0x2A0) * D_800C7E20;
    c = AT(f32, obj, 0x29C) / (f32)D_800E28D0;
    d = AT(f32, obj, 0x2A0) / (f32)D_800E28D4;
    x = AT(f32, obj, 0x2A4) + ax - c * D_800C7E24;
    y = AT(f32, obj, 0x2A8) + ay - d * D_800C7E24;
    func_002ABC18(0x1FB, 0, (s16)x, (s16)y, c, d, 1);
}
