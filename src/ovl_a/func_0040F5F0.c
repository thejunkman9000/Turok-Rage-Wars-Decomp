#include "o02_types.h"
typedef struct { u8 pad[0x14]; u16 v; } S_func_0040F5F0;
s32 func_0040F5F0(S_func_0040F5F0 *a, S_func_0040F5F0 *b) {
    return a->v - b->v;
}
