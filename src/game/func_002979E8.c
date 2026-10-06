#include "b21_types.h"

s32 func_002979E8(B21Plane *pl, Vec3f *p) {
    s32 i;
    for (i = 0; i < 6; i++) {
        if (!(pl[i].x * p->x + pl[i].y * p->y + pl[i].z * p->z <= pl[i].w)) {
            return 0;
        }
    }
    return 1;
}
