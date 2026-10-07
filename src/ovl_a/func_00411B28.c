#include "o02_types.h"
typedef struct { u8 pad[0xC]; s16 v; u8 pad2[0x1C-0xE]; } S_func_00411B28;
extern S_func_00411B28 *D_80153C10;
s32 func_00411B28(s32 i) {
    return D_80153C10[i].v;
}
