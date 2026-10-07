#include "b13_types.h"

extern f32 D_800C8FE0;
extern f32 D_800C8FE4;

void func_00258E7C(SndMgr *m, f32 v) {
    f32 r;
    if (D_800C8FE0 < v) {
        r = v;
        goto b0;
    }
    r = 0.0f;
    if (v < 0.0f) {
        goto c0;
    }
    do {
        r = v;
    } while (0);
b0:
    if (D_800C8FE0 < r) {
        r = D_800C8FE0;
    }
c0:
    m->unk2B9C = (s32)(r * D_800C8FE4);
}