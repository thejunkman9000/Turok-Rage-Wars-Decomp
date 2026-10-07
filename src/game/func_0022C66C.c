#include "b07_types.h"
extern f32 D_800C7E38;
extern f32 D_800C7E3C;
extern f32 D_800C7E40;
extern f32 D_800C7E44;
extern f32 D_800C7E48;
void func_0022C66C(u8 *p)
{
    f32 a = D_800C7E38;
    f32 b = D_800C7E3C;
    f32 c = D_800C7E40;
    f32 d = D_800C7E44;
    f32 e = D_800C7E48;
    AT(s32, p, 0xB4) = 0;
    AT(s32, p, 0x08) = 0;
    AT(s32, p, 0xB8) = 0;
    AT(s32, p, 0x04) = -1;
    AT(s32, p, 0x00) = -1;
    AT(s32, p, 0xA8) = 0;
    AT(s32, p, 0x9C) = 0;
    AT(s32, p, 0xA4) = 0;
    AT(f32, p, 0xAC) = a;
    AT(f32, p, 0xB0) = b;
    AT(f32, p, 0x90) = c;
    AT(f32, p, 0x94) = d;
    AT(f32, p, 0x98) = c;
    AT(f32, p, 0xA0) = e;
}
