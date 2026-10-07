#include "b10_types.h"

extern B10Ctl *D_800E2830;
extern s32 D_800E28D0;
extern s32 D_800E28D4;
extern const f32 D_800C88B0;
extern const f32 D_800C88B4;
extern const f32 D_800C88B8;
extern const f32 D_800C88BC;
extern s32 D_8013B878[];
void func_002A94E8(void);
void func_002ABB58(f32 x, f32 y);
void func_002A9F18(B10Ent *e, s32 x, s32 y, s32 a, s32 b, s32 c, f32 sx, f32 sy);

void func_002453C4(void) {
    s32 half;
    s32 y;
    s32 i;
    s32 step;
    f32 fx;
    f32 fy;
    f32 k;
    f32 t;
    if (D_800E2830->f1E0 > 0) {
        half = D_800E28D0 / 2;
        func_002A94E8();
        fx = (f32)(D_800E28D0 / 284);
        fy = (f32)(D_800E28D4 / 222);
        step = 26;
        if (D_800E28D4 >= 0xDF) {
            k = D_800C88B0;
            fx = fx * k;
            y = 0xB4;
        } else {
            k = D_800C88B4;
            fx = fx * k;
            y = 0x6E;
        }
        fy = fy * k;
        func_002ABB58(fx, fy);
        D_8013B878[0] = 1;
        D_8013B878[1] = 1;
        for (i = 0; i < D_800E2830->f1E0; i++) {
            func_002A9F18(&D_800E2830->ent[i], half, y, 0xFF, 1, 1, D_800C88B8, D_800C88B8);
            t = (f32)step * fy;
            fy = (f32)(D_800E28D4 / 222) * D_800C88BC;
            y = (s32)((f32)y + t);
            func_002ABB58((f32)(D_800E28D0 / 284) * D_800C88BC, fy);
        }
    }
}
