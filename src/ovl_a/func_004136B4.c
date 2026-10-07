#include "o02_types.h"
typedef struct { s32 v; u8 pad[0x30]; } S_func_004136B4;
extern S_func_004136B4 D_800E2B2C[];
s32 func_004136B4(u8 *p) {
    return D_800E2B2C[*p].v;
}
