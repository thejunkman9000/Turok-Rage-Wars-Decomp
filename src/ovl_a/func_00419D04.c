#include "o03_types.h"
s32 func_00274544(void);
#define RND(n) (func_00274544() % (n))
#define CLAMP255(x) ((x) < 0 ? 0 : ((x) >= 256 ? 255 : (x)))
void func_00419D04(O3A *o, s32 n) {
    s32 i;
    o->flag = 0;
    o->idx = 0;
    if (n > 0) {
        o->count = n;
    } else {
        o->count = RND(5) + 1;
    }
    for (i = 0; i < o->count; i++) {
        o->cnts[i] = RND(3) + 1;
        o->vals[i] = CLAMP255(-(RND(40) + 30) + (s32)o->base);
    }
}
