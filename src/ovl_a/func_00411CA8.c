#include "o02_types.h"
typedef struct { u8 pad0[0x48C]; struct { u8 pad[0xA]; s16 fA; s16 fC; s16 fE; s16 f10; } *p; u8 pad1[0x49C-0x490]; } S_func_00411CA8;
extern S_func_00411CA8 *D_80153C28;
s32 func_00411CA8(s32 i) {
    return D_80153C28[i].p->fE;
}
