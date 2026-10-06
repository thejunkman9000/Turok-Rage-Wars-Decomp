#include "b14_types.h"
typedef struct { u8 b[4]; } Q4;
extern Q4 D_8010FBE0[];
s32 func_00264634(s32 i) {
    return ((D_8010FBE0[i].b[3] >> 3) ^ 1) & 1;
}
