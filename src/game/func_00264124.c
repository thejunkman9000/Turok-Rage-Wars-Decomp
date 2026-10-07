#include "b14_types.h"
extern s32 D_80146894[];
extern s32 D_8013B29C;
extern const f32 D_800C93F8;
extern u8 D_8010EC90[];
f32 func_002856B0(void *p, s32 a, s32 b, s32 c);
void func_00285C48(void *p);
void func_00285D00(void *p);
void func_00264124(B14Ctl *c) {
    B14W3 z;
    s32 *g;
    f32 r;
    f32 d;
    if (c->fC8 != 0) {
        z.a = 0;
        z.b = 0;
        z.c = 0;
        if (c->fCC == 0 || *(g = D_80146894) != 0 || D_8013B29C != 0 || g[-6] != 0xD) {
            c->fD0.i = 0;
            func_00285D00(c->blkA);
        } else {
            func_00285C48(c->blkA);
            r = func_002856B0(D_8010EC90, c->f8, c->fC, c->f10);
            c->fD0.f = r + func_002856B0(c->blkA, z.a, z.b, z.c);
        }
        if (c->fC8 != 0) {
            d = c->fD0.f;
            if (d != 0.0f) {
                c->fD4.f = c->fD4.f + d;
                if (D_800C93F8 <= c->fD4.f) {
                    c->fD4.f = c->fD4.f - D_800C93F8;
                    osMotorStart(&c->pfs);
                    return;
                }
            }
            osMotorStop(&c->pfs);
        }
    }
}
