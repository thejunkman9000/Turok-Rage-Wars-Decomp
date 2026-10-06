#include "b14_types.h"
void *func_002604BC(void *p);
s32 *func_0028FD94(void *tree, s16 id);
s32 func_002625E4(void *p) {
    return func_0028FD94(func_002604BC(p), 4)[1];
}
