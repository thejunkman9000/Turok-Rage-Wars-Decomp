#include "b17_types.h"

f32 func_002BC380(f32); /* sqrtf */
extern f32 D_800C9A94;

void func_00274CEC(VelObj *o) {
    f32 len2, z;

    len2 = o->vel.x * o->vel.x + o->vel.y * o->vel.y + o->vel.z * o->vel.z;
    z = 0.0f;
    if (len2 != 0.0f) {
        len2 = D_800C9A94 / func_002BC380(len2);
        z = o->vel.z * len2;
        o->dir.x = o->vel.x * len2;
        o->dir.y = o->vel.y * len2;
    } else {
        o->dir.x = 0.0f;
        o->dir.y = 0.0f;
    }
    o->dir.z = z;
}
