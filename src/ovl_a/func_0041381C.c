#include "o02_types.h"
typedef struct { s32 w[13]; } O02Tbl;
extern O02Tbl D_800E2B20[];
void func_0041381C(s32 i, O02Tbl *dst) {
    *dst = D_800E2B20[i];
}
