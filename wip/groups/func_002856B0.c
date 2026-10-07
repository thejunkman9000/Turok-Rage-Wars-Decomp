#include "b19_types.h"
extern s32 D_8014694C;
extern u8 D_8011FE88[];
u32 __osDisableInt(void);
void __osRestoreInt(u32);
s32 func_00245788(void);
f32 sqrtf(f32);
f32 func_00264F00(void *);
void func_00255E78(void *, void *);
void func_00255CB4(void *, void *);
void *func_0028CE54(void *, s32);
void func_00264E00(void *, void *);
void func_00255C40(void *, s32, s32);
s32 func_00264E10(void *);
inline void func_00285880(B19Spawn *d, B19Spec *src, B19Vec3 pos, f32 a, f32 b, B19Spawn **link) {
    d->src = src;
    d->pos = pos;
    d->f18 = a;
    d->f1C = b;
    d->link = link;
    if (link != 0) *link = d;
    func_00264E00((u8 *)d + 0x20, func_0028CE54(D_8011FE88, src->a));
    func_00264E00((u8 *)d + 0x2C, func_0028CE54(D_8011FE88, src->b));
}

inline f32 func_002859A0(B19Spawn *s, B19Vec3 p) {
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

void func_00285930(s32 *a) {
    s32 *p = (s32 *)a[14];
    if (p) *p = 0;
}

void func_00285944(s32 *a, s32 v) { a[14] = v; }

s32 func_00264E10(void *);
s32 func_0028594C(u8 *o) {
    s32 r = 0;
    if (func_00264E10(o + 0x20)) r = 1;
    else if (func_00264E10(o + 0x2C)) r = 1;
    return r;
}

u32 __osDisableInt(void);
void __osRestoreInt(u32);
void func_00255C40(void *, s32, s32);
void func_00255CB4(void *, void *);
void func_00285A94(B19Pool *p, u8 *items, s32 n) {
    u32 mask = __osDisableInt();
    s32 i;
    func_00255C40(p, 0, 4);
    func_00255C40(&p->head, 0, 4);
    for (i = 0; i < n; i++) {
        func_00255CB4(p, items);
        items += 0x3C;
    }
    p->count = 0;
    __osRestoreInt(mask);
}

B19Spawn *func_00285B34(B19Pool *pool, B19Spec *src, B19Vec3 pos, f32 a, f32 b, B19Spawn **link) {
    u32 mask = __osDisableInt();
    B19Spawn *n = *(B19Spawn **)pool;
    if (n != 0) {
        func_00255E78(pool, n);
        func_00255CB4(&pool->head, n);
        func_00285880(n, src, pos, a, b, link);
    }
    __osRestoreInt(mask);
    return n;
}

