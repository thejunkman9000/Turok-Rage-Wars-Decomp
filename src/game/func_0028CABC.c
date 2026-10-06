#include "b20_types.h"
Entity *func_0028CABC(Level *lv, Entity *ref, s32 a, s32 type, s32 needFlag) {
    s32 i = 0;
    Entity *best = 0;
    f32 bestd = 3.4028235e+38f;
    s32 n = lv->numEntities;
    Entity *e;
    while (i < n) {
        e = &lv->entities[i];
            if (e != ref
                && (a == -1 || e->unkE4 == a)
                && (type == -1 || e->def->type == type)
                && (needFlag == 0 || e->unk174 != 0)) {
            f32 dx = ref->pos.x - e->pos.x;
            f32 dy = ref->pos.y - e->pos.y;
            f32 dz = ref->pos.z - e->pos.z;
            f32 d = dx * dx + dy * dy + dz * dz;
            if (d < bestd) {
                bestd = d;
                best = e;
            }
        }
        i++;
    }
    return best;
}
