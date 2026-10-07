#include "b02_types.h"

B2Cfg *func_0028FD94(void *p, s32 idx);
extern B2Cfg D_800F7D20[22][2];

void func_0020A604(void *p) {
    s32 i;
    s32 j;

    for (i = 0; i < 22; i++) {
        for (j = 0; j < 2; j++) {
            D_800F7D20[i][j] = *func_0028FD94(p, i * 2 + j);
        }
    }
}
