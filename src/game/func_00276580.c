#include "p3_types.h"

/* box = {minX, minZ, maxX, maxZ}; pt = array of xyz points */
void func_00276580(f32 *box, s32 n, f32 *pt) {
    s32 i;
    for (i = 0; i < n; i++) {
        f32 *p = pt + i * 3;
        box[0] = !(p[0] <= box[0]) ? box[0] : p[0];
        box[1] = !(p[2] <= box[1]) ? box[1] : p[2];
        box[2] = !(box[2] <= p[0]) ? box[2] : p[0];
        box[3] = !(box[3] <= p[2]) ? box[3] : p[2];
    }
}
