#include "b13_types.h"

extern f32 D_800D0D10;
extern f32 D_800C908C;

typedef struct Emitter { u8 pad0[0x34]; Vec3f pos; u8 pad40[4]; s8 type; } Emitter;
typedef struct Listener { u8 pad0[0x128]; Vec3f pos; } Listener;

f32 func_0025C388(Emitter *e, Listener *l) {
    f32 t;
    Vec3f *p = &e->pos;
    Vec3f *q = &l->pos;
    f32 d2 = (p->x - q->x) * (p->x - q->x) + (p->y - q->y) * (p->y - q->y) + (p->z - q->z) * (p->z - q->z);
    if (D_800D0D10 <= d2) {
        t = 0.0f;
    } else {
        t = D_800C908C - d2 / D_800D0D10;
    }
    switch (e->type) {
    case 2:
        break;
    case 0:
        t = t * t;
        t = t * t;
    case 1:
        t = t * t;
        break;
    default:
        t = 0.0f;
        break;
    }
    return t;
}
