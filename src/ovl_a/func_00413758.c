#include "o02_types.h"
typedef struct { s32 v; u8 pad[0x30]; } S_func_00413758;
extern S_func_00413758 D_800E2B40[];
s32 func_00413758(u8 *p) {
    return (D_800E2B40[*p].v != 0);
}
