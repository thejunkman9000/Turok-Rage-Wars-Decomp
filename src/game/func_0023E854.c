#include "b09_types.h"

s32 func_0023E854(B09Obj *a, B09Obj *b) {
    s32 r = 0;
    if (*(f32 *)&a->v18C.x == *(f32 *)&b->v48.x && *(f32 *)&a->v18C.y == *(f32 *)&b->v48.y &&
        *(f32 *)&a->v18C.z == *(f32 *)&b->v48.z) {
        r = 1;
    }
    return r;
}
