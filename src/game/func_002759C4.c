#include "b17_types.h"

void func_002759C4(Box3 *box, s32 n, Vec3f *pts) {
    s32 i;
    Vec3f *p;
    s32 m;

    if (n != 0) {
        box->mn.x = pts->x;
        box->mn.y = pts->y;
        box->mn.z = pts->z;
        box->mx.x = pts->x;
        box->mx.y = pts->y;
        box->mx.z = pts->z;
        m = n - 1;
        pts++;
        for (i = 0; i < m; i++) {
            p = pts + i;
            box->mn.x = !(p->x <= box->mn.x) ? box->mn.x : p->x;
            box->mn.y = !(p->y <= box->mn.y) ? box->mn.y : p->y;
            box->mn.z = !(p->z <= box->mn.z) ? box->mn.z : p->z;
            box->mx.x = !(box->mx.x <= p->x) ? box->mx.x : p->x;
            box->mx.y = !(box->mx.y <= p->y) ? box->mx.y : p->y;
            box->mx.z = !(box->mx.z <= p->z) ? box->mx.z : p->z;
        }
    }
}
