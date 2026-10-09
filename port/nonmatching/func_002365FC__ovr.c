extern int fprintf(void *, const char *, ...); extern void *__acrt_iob_func(unsigned);
#include "b08_types.h"

typedef struct TargetObj {
    u8 pad0[0x29C];
    f32 unk29C;
    f32 unk2A0;
    f32 unk2A4;
    f32 unk2A8;
} TargetObj;

s32 func_00264B8C();

extern f32 D_80103224;

static inline f32 approach(f32 x, f32 target, f32 step) {
    if (func_00264B8C() != 0) {
        x = target;
    }
    if (x < target) {
        x += step;
        D_80103224 = 30.0f;
        if (target < x) {
            x = target;
        }
    } else if (target < x) {
        x -= step;
        D_80103224 = 30.0f;
        if (x < target) {
            x = target;
        }
    }
    return x;
}

void func_002365FC(TargetObj *o, f32 a, f32 b, f32 c, f32 d) {
    { static f32 l29c = -1.f, la = -1.f; if (o->unk29C != l29c || a != la) { fprintf(__acrt_iob_func(2), "viewport approach: unk29C=%f -> target %f (unk2A0=%f -> %f) snap=%d\n", (double)o->unk29C, (double)a, (double)o->unk2A0, (double)b, func_00264B8C()); l29c = o->unk29C; la = a; } }
    o->unk29C = approach(o->unk29C, a, 16.0f);
    o->unk2A0 = approach(o->unk2A0, b, 16.0f);
    o->unk2A4 = approach(o->unk2A4, c, 16.0f);
    o->unk2A8 = approach(o->unk2A8, d, 16.0f);
}
