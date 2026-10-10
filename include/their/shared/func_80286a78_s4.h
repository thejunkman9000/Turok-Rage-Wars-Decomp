#ifndef SHARED_SHARED_FUNC_80286A78_S4_H
#define SHARED_SHARED_FUNC_80286A78_S4_H

#include "types.h"

typedef struct Shared_func_80286A78_S4 Shared_func_80286A78_S4;
struct Shared_func_80286A78_S4 {
    char pad0[0x98];
    s32 unk98; /* +0x98: src/func_80286A78.c */
};
typedef char Shared_func_80286A78_S4_size_check[(sizeof(Shared_func_80286A78_S4) == 0x9C) ? 1 : -1];

#endif
