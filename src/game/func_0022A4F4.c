#include "b06_types.h"

extern f32 D_800C7DD8;

Plr *func_0022A4F4(PlrGroup *g, Vec3f p, Plr *skip) {
    Plr *a;
    Plr *best = NULL;
    f32 min = D_800C7DD8;
    f32 dx, dy, dz, d;
    for (a = g->head; a != NULL; a = a->next) {
        if (a->unk5E4 != 0 && a != skip) {
            dx = a->pos.x - p.x;
            dy = a->pos.y - p.y;
            dz = a->pos.z - p.z;
            d = dx * dx + dy * dy + dz * dz;
            if (d < min) {
                min = d;
                best = a;
            }
        }
    }
    return best;
}
