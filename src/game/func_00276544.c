#include "b17_types.h"

void func_00276580(Rect4 *r, s32 n, Vec3f *pts);

void func_00276544(Rect4 *r, s32 n, Vec3f *pts) {
    if (n != 0) {
        r->x0 = r->x1 = pts->x;
        r->z0 = r->z1 = pts->z;
        func_00276580(r, n - 1, pts + 1);
    }
}
