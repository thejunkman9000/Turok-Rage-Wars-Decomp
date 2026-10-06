#include "b08_types.h"

typedef struct ObjWave {
    s32 type;
    u8 pad4[8];
    f32 unkC;
    f32 unk10;
} ObjWave;

extern f32 D_800C865C;

f32 func_00274B00(f32 a, f32 b);

f32 func_00239D0C(ObjWave *o) {
    switch (o->type) {
    case 1:
        return sinf(o->unk10 * D_800C865C) * o->unkC;
    case 0:
        return func_00274B00(-o->unkC, o->unkC);
    default:
        return 0.0f;
    }
}
