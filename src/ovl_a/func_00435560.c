#include "o05_types.h"
s32 func_00405160(s32 a, s32 *p);
s32 func_004050CC(s32 a, s32 *p);
s32 func_00435600(void);
s32 func_004057EC(s32 a);

s32 func_00435560(s32 a, s32 *out) {
    s32 v[2];
    s32 r;
    s32 x;
    *out = 0;
    r = func_00405160(a, &v[0]);
    if (r == 0) {
        r = func_004050CC(a, &v[1]);
        if (r == 0) {
            x = func_004057EC(func_00435600());
            if (v[1] == 0 || v[0] < x) {
                *out = 0;
            } else {
                *out = 1;
            }
        }
    }
    return r;
}
