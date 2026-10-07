#include "o02_types.h"
typedef struct S_func_0040EBE8 { struct S_func_0040EBE8 *next; u8 pad[0x12-4]; u16 flags; } S_func_0040EBE8;
s32 func_0040EBE8(S_func_0040EBE8 *n) {
    u32 f = 0;
    while (n) {
        f |= n->flags;
        n = n->next;
    }
    return (f >> 3) & 1;
}
