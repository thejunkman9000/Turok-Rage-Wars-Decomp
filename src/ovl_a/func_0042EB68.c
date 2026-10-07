#include "o04_types.h"
extern s32 D_80154024;
void func_0042EB68(s32 a) {
    s32 *p = &D_80154024;
    *p = 1;
    p[-1] = a;
}
