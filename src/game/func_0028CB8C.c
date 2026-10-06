#include "b20_types.h"
Entity *func_0028CB8C(Level *lv, Entity *e) {
    s32 i;
    Entity *best;
    f32 bestd;
    s32 n;
    Entity **arr;
    i = 0;
    best = 0;
    n = lv->cnt10A4;
    bestd = 3.4028235e+38f;
    arr = lv->list3;
    for (; i < n; i++) {
        Entity *o = arr[i];
        f32 dx = e->pos.x - o->pos.x;
        f32 dy = e->pos.y - o->pos.y;
        f32 dz = e->pos.z - o->pos.z;
        f32 d = dx * dx + dy * dy + dz * dz;
        if (d < bestd) {
            bestd = d;
            best = o;
        }
    }
    return best;
}
