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
    register f32 a asm("$f5");
    register f32 c asm("$f5");
    register f32 b asm("$f3");
    register f32 d asm("$f3");
    register f32 ax asm("$f1");
    register f32 ay asm("$f2");
    register f32 m1 asm("$f6");
    register f32 m2 asm("$f4");
    register f32 x asm("$f0");
    register f32 y asm("$f1");
    func_002AA224(D_801462DE);
    a = AT(f32, obj, 0x29C);
    ax = a * D_800C7E20;
    b = AT(f32, obj, 0x2A0);
    ay = b * D_800C7E20;
    c = a / (f32)D_800E28D0;
    m1 = c * D_800C7E24;
    d = b / (f32)D_800E28D4;
    m2 = d * D_800C7E24;
    x = AT(f32, obj, 0x2A4) + ax - m1;
    y = AT(f32, obj, 0x2A8) + ay - m2;
    func_002ABC18(0x1FB, 0, (s16)x, (s16)y, c, d, 1);
}
