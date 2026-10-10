#ifndef SHARED_SHARED_FUNC_80286A78_S13_H
#define SHARED_SHARED_FUNC_80286A78_S13_H

#include "types.h"

typedef struct Shared_func_80286A78_S13 Shared_func_80286A78_S13;
struct Shared_func_80286A78_S13 {
    char pad0[0x1B664];
    s32 unk1B664; /* +0x1B664: src/func_80286A78.c */
};
typedef char Shared_func_80286A78_S13_size_check[(sizeof(Shared_func_80286A78_S13) == 0x1B668) ? 1 : -1];

#endif
