#include "o02_types.h"
typedef struct { u8 pad[0x49C]; } U;
extern U *D_80153C28;
typedef struct { s8 pad[8]; struct { s8 a, b, c, d, e, f, g, h; } e[1]; } V;
s32 func_00411C28(u8 a, s32 i) {
    return ((V *)&D_80153C28[i])->e[a].b;
}
