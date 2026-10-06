#include "b21_types.h"

s32 func_00297AD4(B21Plane *pl, s32 n, Vec3f *pts) {
    s32 i;
    s32 j;
    s32 found;
    B21Plane *p;
    for (i = 0; i < 6; i++) {
        if (i == 2) {
            continue;
        }
        p = &pl[i];
        found = 0;
        for (j = 0; j < n; j++) {
            if (p->x * pts[j].x + p->y * pts[j].y + p->z * pts[j].z <= p->w) {
                found = 1;
                break;
            }
        }
        if (!found) {
            return 0;
        }
    }
    return 1;
}
