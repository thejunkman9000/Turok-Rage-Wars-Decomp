#include "o02_types.h"
typedef struct { u8 pad[0xA]; s16 a; s16 b; u8 pad2[0x1C-0xE]; } O02Rec;
extern O02Rec *D_80153C10;
s32 func_00411B04(s32 i) {
    return D_80153C10[i].a;
}
