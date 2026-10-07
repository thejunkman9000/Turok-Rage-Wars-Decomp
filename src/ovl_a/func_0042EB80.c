#include "o04_types.h"
extern s32 D_8015402C;
void func_0042EB80(s32 a, s32 b) {
    s32 *p = &D_8015402C;
    *p = b;
    p[-1] = a;
}
