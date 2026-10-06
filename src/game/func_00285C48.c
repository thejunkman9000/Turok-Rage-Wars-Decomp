#include "b19_types.h"
u32 __osDisableInt(void);
void __osRestoreInt(u32);
s32 func_00264E10(void *);
void func_00255E78(void *, void *);
void func_00255CB4(void *, void *);
void func_00285C48(B19Pool *pool) {
    u32 mask = __osDisableInt();
    B19Spawn *n;
    B19Spawn *next;
    s32 r;
    for (n = (B19Spawn *)pool->head; n != 0; n = next) {
        next = *(B19Spawn **)((u8 *)n + 4);
        r = 0;
        if (func_00264E10((u8 *)n + 0x20) || func_00264E10((u8 *)n + 0x2C)) r = 1;
        if (r) {
            if (n->link != 0) *n->link = 0;
            func_00255E78(&pool->head, n);
            func_00255CB4(pool, n);
        }
    }
    __osRestoreInt(mask);
}
