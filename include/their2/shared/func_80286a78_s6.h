#ifndef SHARED_SHARED_FUNC_80286A78_S6_H
#define SHARED_SHARED_FUNC_80286A78_S6_H

#include "types.h"

typedef struct Shared_func_80286A78_S6 Shared_func_80286A78_S6;
struct Shared_func_80286A78_S6 {
    char pad0[0x80];
    s8 unk80; /* +0x80: src/func_80286A78.c */
};
typedef char Shared_func_80286A78_S6_size_check[(sizeof(Shared_func_80286A78_S6) == 0x81) ? 1 : -1];

#endif
