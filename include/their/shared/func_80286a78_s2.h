#ifndef SHARED_SHARED_FUNC_80286A78_S2_H
#define SHARED_SHARED_FUNC_80286A78_S2_H

#include "types.h"

typedef struct Shared_func_80286A78_S2 Shared_func_80286A78_S2;
struct Shared_func_80286A78_S2 {
    char pad0[0x5D8];
    struct Shared_func_80286A78_S6 * unk5D8; /* +0x5D8: src/func_80286A78.c */
    char pad5DC[0xE78];
    s32 unk1454; /* +0x1454: src/func_80286A78.c */
};
typedef char Shared_func_80286A78_S2_size_check[(sizeof(Shared_func_80286A78_S2) == 0x1458) ? 1 : -1];

#endif
