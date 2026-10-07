#include "b14_types.h"
typedef struct { s32 type; f32 f4; u8 b8; u8 b9; u8 pad[0xA]; f32 f14; } B14SrcDef;
typedef struct { B14SrcDef *def; f32 f4; f32 f8; } B14Timer;
f32 func_00274B00(f32 a, f32 b);
extern f32 D_80146CFC;
extern f32 D_800C9400;
extern f32 D_800C9404;
extern f32 D_800C9408;

s32 func_00264E10(B14Timer *o) {
    B14SrcDef *d = o->def;
    switch (d->type) {
    case 0:
        o->f4 += D_800C9400 / D_80146CFC;
        if (!(d->f14 <= o->f4)) {
            return 0;
        }
        return 1;
    case 1:
        o->f4 -= D_800C9404 / D_80146CFC;
        if (o->f4 <= 0.0f) {
            o->f4 += d->f4;
            o->f8 = func_00274B00(d->b8 * D_800C9408, d->b9 * D_800C9408);
        }
        return 0;
    default:
        return 0;
    }
}
