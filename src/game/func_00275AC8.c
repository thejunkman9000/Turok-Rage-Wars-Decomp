#include "b17_types.h"

extern f32 D_800C9ADC;

typedef union IF32 { s32 i; f32 f; } IF32;

void func_00275AC8(IF32 *p) {
    p[0].f = (f32)p[0].i * D_800C9ADC;
    p[1].f = (f32)p[1].i * D_800C9ADC;
    p[2].f = (f32)p[2].i * D_800C9ADC;
    p[3].f = (f32)p[3].i * D_800C9ADC;
}
