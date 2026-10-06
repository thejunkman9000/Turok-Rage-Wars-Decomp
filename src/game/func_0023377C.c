#include "p2_types.h"

void func_00273424(void *a, f32 b, s32 c, f32 d);

void func_0023377C(void *a, PlayerEvt *e) {
    if (e->f4 == 6) {
        func_00273424(a, 0.0f, e->f8->f294, 0.0f);
    }
}