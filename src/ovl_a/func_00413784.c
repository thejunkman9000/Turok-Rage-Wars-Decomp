#include "o02_types.h"
typedef struct { u8 pad[1]; u8 v; } S_func_00413784;
s32 func_00413784(S_func_00413784 *p) {
    return (p->v >> 1) & 1;
}
