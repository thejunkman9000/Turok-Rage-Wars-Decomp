#include "b14_types.h"
typedef struct { s32 type; u8 pad4[0x10]; f32 f14; } B14Src;
typedef struct { B14Src *src; f32 f4; f32 f8; } B14Smp;
extern f32 D_800C940C;
extern f32 D_800C9410;


f32 func_00264F00(B14Smp *o) {
B14Src *s = o->src;
    switch (s->type) {
    case 0:
        return (f32)((u8 *)s + (s32)(o->f4 * D_800C940C / s->f14))[4] * D_800C9410;
    case 1:
        return o->f8;
    default:
        return 0.0f;
    }
}
