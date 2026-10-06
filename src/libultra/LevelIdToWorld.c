#include "common.h"

s32 LevelIdToWorld(s32 id) {
    if (id == 1999 || id == 2999 || id == 3999 || id == 4999 || id == 5999 || id == 6999 || id == 99) return 0;
    if ((u32)(id - 1000) < 1000) return 1;
    if ((u32)(id - 2000) < 1000) return 2;
    if ((u32)(id - 3000) < 1000) return 3;
    if ((u32)(id - 4000) < 1000) return 4;
    if ((u32)(id - 5000) < 1000) return 5;
    if ((u32)(id - 6000) < 1000) return 6;
    return -1;
}
