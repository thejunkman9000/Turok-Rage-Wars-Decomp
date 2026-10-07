#include "o04_types.h"
extern O04Cfg D_801462C8[];
extern u8 D_80145040[];
extern s32 D_80154028;
extern s32 D_80146938;
s32 func_0022804C(void *a);
s32 func_002282C8(void *a);
s32 func_002281CC(void *a);
s32 func_0042D240(void) {
    if (D_801462C8->s24 > 0 && D_801462C8->unk5EC == 0.0f) {
        return 0;
    }
    if (func_0022804C(D_80145040) != 0) {
        return 1;
    }
    switch (D_80154028) {
    case 0:
        if (func_002282C8(D_80145040) != 0) {
            return 3;
        }
        break;
    case 1:
        if (func_002281CC(D_80145040) != 0) {
            return 2;
        }
        break;
    }
    return D_80146938 == 1;
}
