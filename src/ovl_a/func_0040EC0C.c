#include "o02_types.h"
typedef struct S_func_0040EC0C { struct S_func_0040EC0C *next; u8 pad[0x12-4]; u16 flags; } S_func_0040EC0C;
s32 func_0040EC0C(S_func_0040EC0C *n) {
    s32 f = 0;
    while (n) {
        f |= n->flags;
        n = n->next;
    }
    return f & 1;
}
