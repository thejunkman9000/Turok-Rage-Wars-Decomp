#include "b23_types.h"

void *func_002A0470(void *dst, void *src, u32 n);

void *func_002A1724(void *dst, void *src, u32 n) {
    void *r = dst;
    if (n != 0) {
        r = func_002A0470(dst, src, n);
    }
    return r;
}
