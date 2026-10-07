#include "o01_types.h"

void func_002537D8(s32 a, s32 b);

void func_00405CDC(s32 *a) {
    s32 i;
    s32 *p;
    if (a[1] != 0) {
        func_002537D8(0, a[1]);
    }
    if (a[2] != 0) {
        func_002537D8(0, a[2]);
    }
    if (a[6] != 0) {
        func_002537D8(0, a[6]);
    }
    if (a[7] != 0) {
        func_002537D8(0, a[7]);
    }
    p = a;
    for (i = 0; i < 3; i++) {
        if (p[3] != 0) {
            func_002537D8(0, p[3]);
        }
        p++;
    }
    a[0] = 0;
    a[1] = 0;
    a[2] = 0;
    a[6] = 0;
    a[7] = 0;
    for (i = 0; i < 3; i++) {
        a[3 + i] = 0;
    }
}
