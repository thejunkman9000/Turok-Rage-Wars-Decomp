#include "b07_types.h"
extern f32 D_800C7F14;
extern f32 D_800C7F18;
extern f32 D_800C7F1C;
f32 func_002752CC(void *o, s32 a, s32 b);
f32 func_00275E44(void *o, s32 a, s32 b);
void func_0025E460(f32 v);
void func_0022EA2C(u8 *o, u8 *p)
{
    s32 n;
    f32 d;
    if (o != NULL && p != NULL && (AT(u16, o, 0x2) & 0x40)) {
        n = func_002752CC(o, AT(s32, p, 0x0), AT(s32, p, 0x8)) - func_00275E44(o, AT(s32, p, 0x0), AT(s32, p, 0x8));
        if ((f32)n < D_800C7F14) {
            func_0025E460(D_800C7F1C - (f32)n * D_800C7F18);
        } else {
            func_0025E460(0);
        }
    } else {
        func_0025E460(0);
    }
}
