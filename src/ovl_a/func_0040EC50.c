#include "o02_types.h"
typedef struct S_func_0040EC50 { struct S_func_0040EC50 *next; u8 pad[0x12-4]; u16 flags; } S_func_0040EC50;
s32 func_0040EC50(S_func_0040EC50 *n) {
    u32 f = 0;
    while (n) {
        f |= n->flags;
        n = n->next;
    }
    return (f >> 8) & 1;
}
