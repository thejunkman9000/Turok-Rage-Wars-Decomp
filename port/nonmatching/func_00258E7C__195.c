#include "b13_types.h"

extern f32 D_800C8FE0;
extern f32 D_800C8FE4;

void func_00258E7C(SndMgr *m, f32 v) {
    f32 f;
    f = v;
    if (f > D_800C8FE0) f = D_800C8FE0;
    else if (f < 0.0f) f = 0.0f;
    m->unk2B9C = (s32)(f * D_800C8FE4);
}
