#include "o02_types.h"
typedef struct { s32 w[13]; } S_func_00412D5C;
extern S_func_00412D5C D_800E2B20[];
s32 func_00412D5C(S_func_00412D5C *p) {
    s32 i;
    for (i = 0; i < 36; i++) {
        if (D_800E2B20[i].w[1] == p->w[1] && D_800E2B20[i].w[2] == p->w[2] && D_800E2B20[i].w[5] == p->w[5] && D_800E2B20[i].w[6] == p->w[6] && D_800E2B20[i].w[7] == p->w[7] && D_800E2B20[i].w[8] == p->w[8]) {
            return i;
        }
    }
    return 0;
}
