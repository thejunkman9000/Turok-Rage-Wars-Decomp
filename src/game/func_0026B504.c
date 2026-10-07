#include "b15_types.h"
#include "p4_types.h"

u8 *func_0022A404(void *p);
void func_00270770(void *m, s32 a);
void func_00271FD8(f32 *out, void *a, void *b);
void func_002720EC(f32 *v);
void func_00273340(void *m, void *v);
extern f32 D_800C9758;
extern B15Lights1 D_800D1600;
extern s32 D_80110620;
extern P4Gfx *D_80110634;
extern u8 D_80145040[];

s32 func_0026B504(s32 a, B15Lights1 *lights, s32 *flags) {
    f32 v[3];
    f32 q[4];
    f32 m[16];
    P4Gfx *a0;
    P4Gfx *a1;
    P4Gfx *a2;
    P4Gfx *b0;
    P4Gfx *b1;
    P4Gfx *b2;

    if (D_80110620 != 0 && (*flags & 0x8000)) {
        func_00270770(m, a);
        func_00273340(m, q);
        func_00271FD8(v, func_0022A404(D_80145040) + 0x6E8, q);
        func_002720EC(v);
        D_800D1600.l[0].dir[0] = v[0] * D_800C9758;
        D_800D1600.l[0].dir[1] = v[1] * D_800C9758;
        D_800D1600.l[0].dir[2] = v[2] * D_800C9758;
        a0 = D_80110634++;
        a0->words.w0 = 0xDB020000;
        a0->words.w1 = 0x18;
        a1 = D_80110634++;
        a1->words.w0 = 0xDC08060A;
        a1->words.w1 = (u32)&D_800D1600.l[0];
        a2 = D_80110634++;
        a2->words.w0 = 0xDC08090A;
        a2->words.w1 = (u32)&D_800D1600.a;

        return 1;
    }
    if (lights != NULL) {
        b0 = D_80110634++;
        b0->words.w0 = 0xDB020000;
        b0->words.w1 = 0x18;
        b1 = D_80110634++;
        b1->words.w0 = 0xDC08060A;
        b1->words.w1 = (u32)&lights->l[0];
        b2 = D_80110634++;
        b2->words.w0 = 0xDC08090A;
        b2->words.w1 = (u32)lights;
    }
    return 0;
}
