#include "b19_types.h"
s32 *func_0028FD94(s32, s32);
void func_00289790(B19Owner *ow, B19Vec3 *p, B19Item **out, s32 *nout) {
    B19Ent12 *found = 0;
    s32 i;
    s32 n = 0;
    s32 cnt;
    B19Set *set;
    f32 x, z;
    B19Rng *b;
    B19Item *it, *base;
    B19Aabb *bb;
    s32 cnt2;
    x = p->x; cnt = ow->nent; z = p->z;
    for (i = 0; i < cnt; i++) {
        b = ow->ent[i].box;
        if (b->x1 < x) continue;
        if (x < b->x0) continue;
        if (b->z1 < z) continue;
        if (z < b->z0) continue;
        found = &ow->ent[i];
        break;
    }
    if (found == 0) {
        *nout = 0;
        return;
    }
    set = (B19Set *)func_0028FD94(*(s32 *)found->pp, 2); base = set->it; cnt2 = set->cnt;
    for (i = 0; i < cnt2; i++) {
        it = base + i;
        bb = &it->bb;
        if (bb->mx[0] > p->x && bb->mx[1] > p->y && bb->mx[2] > p->z && it->bb.mn[0] <= p->x && bb->mn[1] <= p->y && bb->mn[2] <= p->z) {
            out[n] = it;
            n++;
            if (n == 10) break;
        }
    }
    *nout = n;
}
