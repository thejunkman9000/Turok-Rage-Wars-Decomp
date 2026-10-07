#include "o02_types.h"
typedef struct { s32 v; u8 pad[0x30]; } S_func_00413688;
extern S_func_00413688 D_800E2B28[];
s32 func_00413688(u8 *p) {
    return D_800E2B28[*p].v;
}
