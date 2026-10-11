#include "b19_types.h"
extern s32 D_8014694C;
u32 __osDisableInt(void);
void __osRestoreInt(u32);
s32 func_00245788(void);
f32 sqrtf(f32);
f32 func_00264F00(void *);
static inline f32 func_002859A0(B19Spawn *s, B19Vec3 p) {
    f32 dx = p.x - s->pos.x;
    f32 dy = p.y - s->pos.y;
    f32 dz = p.z - s->pos.z;
    f32 d = sqrtf(dx * dx + dy * dy + dz * dz);
    f32 k;
    if (d == 0.0f || s->f18 == 0.0f) {
        k = 1.0f;
    } else {
        k = 0.0f;
        if (d < s->f18) k = 1.0f - d / s->f18;
    }
    k = k * s->f1C;
    return k * func_00264F00(&s->h20) * func_00264F00(&s->h2C);
}
f32 func_002856B0(B19PoolF *pool, B19Vec3 p) {
    f32 total = pool->total;
    f32 v;
    B19Spawn *n;
    u32 mask = __osDisableInt();
    if (D_8014694C == 1 || func_00245788() != 0) {
        total = 0.0f;
    } else {
        for (n = pool->head; n != 0; n = n->next) {
            total += func_002859A0(n, p);
        }
    }
    __osRestoreInt(mask);
    if (!(1.0f < total)) {
        v = 0.0f;
        if (total < 0.0f) goto done;
    }
    v = total;
    if (1.0f < v) v = 1.0f;
done:
    return v;
}
