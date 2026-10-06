#include "b04_types.h"
f32 func_00215868(void *, s32, s32, s32, void *, f32);
void func_00217074(void *, f32);
extern f32 D_800C72B8;
extern f32 D_800D2988;
typedef struct { u8 pad0[8]; s32 x, y, z; } B04Tg;
void func_002168B8(void *o, s32 a1, B04Tg *t, f32 lim) {
    f32 r, v, a;
    if (t != NULL) {
        r = func_00215868(o, t->x, t->y, t->z, t, D_800C72B8);
        v = r;
        if (lim < r) r = lim;
        else if (r < -lim) r = -lim;
        r = r * D_800D2988;
        a = r;
        if (a < 0.0f) a = -a;
        if (v < 0.0f) {
            if (-v < a) goto blk;
        } else if (v < a) {
blk:
            r = v;
        }
        func_00217074(o, r);
    }
}
