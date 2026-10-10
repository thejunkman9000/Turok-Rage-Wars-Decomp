#ifndef SHARED_SHARED_FUNC_80286A78_S14_H
#define SHARED_SHARED_FUNC_80286A78_S14_H

#include "types.h"

typedef struct Shared_func_80286A78_S14 Shared_func_80286A78_S14;
struct Shared_func_80286A78_S14 {
    char pad0[0x18];
    s32 * unk18; /* +0x18: src/func_80286A78.c */
};
typedef char Shared_func_80286A78_S14_size_check[(sizeof(Shared_func_80286A78_S14) == 0x1C) ? 1 : -1];

#endif
