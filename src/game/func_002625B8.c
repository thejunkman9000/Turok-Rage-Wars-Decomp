#include "b14_types.h"
void *func_002604BC(void *p);
u8 *func_0028FD94(void *tree, s16 id);
u8 *func_002625B8(void *p) {
    return func_0028FD94(func_002604BC(p), 4) + 8;
}
