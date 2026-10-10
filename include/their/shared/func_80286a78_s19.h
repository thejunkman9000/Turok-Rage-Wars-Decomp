#ifndef SHARED_SHARED_FUNC_80286A78_S19_H
#define SHARED_SHARED_FUNC_80286A78_S19_H

#include "types.h"

typedef struct Shared_func_80286A78_S19 Shared_func_80286A78_S19;
struct Shared_func_80286A78_S19 {
    s32 unk0; /* +0x0: src/func_80286A78.c */
    char pad4[0x24];
    s16 unk28; /* +0x28: src/func_80286A78.c */
    char pad2A[0x2];
};
typedef char Shared_func_80286A78_S19_size_check[(sizeof(Shared_func_80286A78_S19) == 0x2C) ? 1 : -1];

#endif
