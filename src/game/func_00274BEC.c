#include "p3_types.h"

typedef struct {
    P3Vec3 p0;     /* 0x00 */
    P3Vec3 p1;     /* 0x0C */
    P3Vec3 d;      /* 0x18 */
    u8 pad24[0x30 - 0x24];
    f32 n0;        /* 0x30 */
    f32 n1;        /* 0x34 */
    f32 n2;        /* 0x38 */
} P3Seg;

void func_00274BEC(P3Seg *s, P3Vec3 *a, P3Vec3 *b) {
    s->p0 = *a;
    s->p1 = *b;
    s->d.x = b->x - a->x;
    s->d.y = b->y - a->y;
    s->d.z = b->z - a->z;
    s->n0 = s->d.z;
    s->n1 = 0.0f;
    s->n2 = -s->d.x;
}
