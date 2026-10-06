#include "b21_types.h"

s32 func_00297A48(B21Plane *pl, s32 n, Vec3f *pts) {
    s32 i;
    s32 j;
    s32 found;
    for (i = 0; i < 6; i++) {
        found = 0;
        for (j = 0; j < n; j++) {
            if (pl[i].x * pts[j].x + pl[i].y * pts[j].y + pl[i].z * pts[j].z <= pl[i].w) {
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
