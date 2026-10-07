#include "b09_types.h"

s32 func_0023DA90(B09Mover *m, B09Box3 *box, f32 *t) {
    B09V3 p;
    B09V3 *s = &m->v44;
    B09V3 *e = &m->v50;
    f32 tt;

    if (box->maxx >= s->x) {
        if (box->maxy >= s->y) {
            if (box->maxz >= s->z && box->minx <= s->x && box->miny <= s->y && box->minz <= s->z) {
                *t = 0.0f;
                return 1;
            }
        }
    }
    if (s->x != e->x) {
        if (s->x < e->x) {
            tt = (box->minx - s->x) / (e->x - s->x);
        } else {
            tt = (s->x - box->maxx) / (s->x - e->x);
        }
        if (tt < m->qcopy.t) {
            p.y = s->y + tt * m->v5C.y;
            p.z = s->z + tt * m->v5C.z;
            if (box->miny <= p.y && p.y <= box->maxy && box->minz <= p.z && p.z <= box->maxz) {
                *t = tt;
                return 1;
            }
        }
    }
    if (s->y != e->y) {
        if (s->y < e->y) {
            tt = (box->miny - s->y) / (e->y - s->y);
        } else {
            tt = (s->y - box->maxy) / (s->y - e->y);
        }
        if (tt < m->qcopy.t) {
            p.x = s->x + tt * m->v5C.x;
            p.z = s->z + tt * m->v5C.z;
            if (box->minx <= p.x && p.x <= box->maxx && box->minz <= p.z && p.z <= box->maxz) {
                *t = tt;
                return 1;
            }
        }
    }
    if (s->z == e->z) {
        return 0;
    }
    if (s->z < e->z) {
        tt = (box->minz - s->z) / (e->z - s->z);
    } else {
        tt = (s->z - box->maxz) / (s->z - e->z);
    }
    if (!(tt < m->qcopy.t)) {
        return 0;
    }
    p.x = s->x + tt * m->v5C.x;
    p.y = s->y + tt * m->v5C.y;
    if (box->minx <= p.x && p.x <= box->maxx && box->miny <= p.y && p.y <= box->maxy) {
        *t = tt;
        return 1;
    }
    return 0;
}
