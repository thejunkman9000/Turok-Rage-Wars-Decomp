#include "b07_types.h"

extern u8 D_8013B1A8[];

void func_00268C7C(void *tbl, s32 id);

void func_0022E880(s32 a0, s32 *p)
{
    if (*p != 0) {
        func_00268C7C(D_8013B1A8, *p);
        *p = 0;
    }
}
