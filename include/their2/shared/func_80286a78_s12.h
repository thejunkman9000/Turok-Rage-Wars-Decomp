#ifndef SHARED_SHARED_FUNC_80286A78_S12_H
#define SHARED_SHARED_FUNC_80286A78_S12_H

#include "types.h"

typedef struct Shared_func_80286A78_S12 Shared_func_80286A78_S12;
struct Shared_func_80286A78_S12 {
    char pad0[0x4];
    s32 unk4; /* +0x4: src/func_80286A78.c */
    u8 address8; /* +0x8: src/func_80286A78.c */
    char pad9[0x3];
};
typedef char Shared_func_80286A78_S12_size_check[(sizeof(Shared_func_80286A78_S12) == 0xC) ? 1 : -1];

#endif
