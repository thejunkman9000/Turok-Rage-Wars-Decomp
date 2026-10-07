#include "b02_types.h"

s32 func_00274544(void);

s32 func_0020DD04(B2Info *info) {
    s32 a;
    s32 b;
    s32 c;
    s32 t1;
    s32 t2;
    s32 total;
    s32 r;
    s32 v;

    a = (s32)info->unk2C;
    b = (s32)info->unk30;
    c = (s32)info->unk34;
    t1 = 0;
    if (a > 0) {
        t1 = a;
    }
    t2 = 0;
    if (b > 0) {
        t2 = t1 + b;
    }
    total = a + b + c;
    if (total != 0) {
        v = func_00274544() % total + 1;
        if (t1 >= v) {
            return 5;
        }
        if (t2 >= v) {
            return 4;
        }
        return 3;
    }
    return 3;
}
