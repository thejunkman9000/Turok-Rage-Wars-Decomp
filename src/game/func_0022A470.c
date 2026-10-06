#include "b06_types.h"

extern f32 D_800C7DD4;

Plr *func_0022A470(PlrGroup *g, Vec3f p) {
    Plr *a;
    Plr *best = NULL;
    f32 min = D_800C7DD4;
    f32 dx, dy, dz, d;
    for (a = g->head; a != NULL; a = a->next) {
        dx = a->pos.x - p.x;
        dy = a->pos.y - p.y;
        dz = a->pos.z - p.z;
        d = dx * dx + dy * dy + dz * dz;
        if (d < min) {
            min = d;
            best = a;
        }
    }
    return best;
}
