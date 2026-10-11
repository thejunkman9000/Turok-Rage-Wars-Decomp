#include "b09_types.h"

typedef struct B09Blk32 { s32 w[8]; } B09Blk32;
extern B09Blk32 D_80103230;

void func_0023C8C4(B09Blk32 *dst) {
    *dst = D_80103230;
}
