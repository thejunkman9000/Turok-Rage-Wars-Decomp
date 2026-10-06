#include "p2_types.h"

s32 func_0024DFB8(Actor *a) {
    ActorInfo *info = a->info;

    if (info->kind == 1) {
        return a->f174 <= 0 || (info->f4C & 0x800) != 0;
    }
    return 0;
}