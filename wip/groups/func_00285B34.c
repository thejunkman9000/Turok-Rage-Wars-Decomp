#include "b19_types.h"
extern u8 D_8011FE88[];
u32 __osDisableInt(void);
void __osRestoreInt(u32);
void func_00255E78(void *, void *);
void func_00255CB4(void *, void *);
void *func_0028CE54(void *, s32);
void func_00264E00(void *, void *);
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
