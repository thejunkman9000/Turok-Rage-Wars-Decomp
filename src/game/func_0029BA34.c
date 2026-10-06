#include "b22_types.h"
extern SndAux *D_8014D0B0;
void func_0029BA34(void)
{
    s32 i, j;
    for (i = 0; i < 16; i++) {
        for (j = 0; j < 4; j++) {
            D_8014D0B0->tbl[i][j] = 0;
        }
    }
}
