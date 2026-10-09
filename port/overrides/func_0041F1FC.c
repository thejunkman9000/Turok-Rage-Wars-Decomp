#include "o03_types.h"
extern int fprintf(void *, const char *, ...); extern void *__acrt_iob_func(unsigned);
extern O3Row D_800E3A50[17];
s32 func_0041F1FC(s32 key) {
    s32 i, found, res;
    res = 0;
    found = 0;
    for (i = 0; i < 17 && found == 0; i++) {
        if (D_800E3A50[i].f0 == key) {
            found = 1;
            res = i;
        }
    }
    fprintf(__acrt_iob_func(2), "func_0041F1FC(key=%d) -> %d\n", key, res);
    return res;
}
