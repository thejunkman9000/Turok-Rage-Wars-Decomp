#include "b23_types.h"

s32 func_002A2FB8(StateObj *o, s32 a1, u32 a2, s32 a3) {
    if ((a2 >> 16) == 3 && a3 < 8 && a3 >= 6) {
        o->unk5C = 2;
        o->unk48 = 0;
    }
    return 0;
}
