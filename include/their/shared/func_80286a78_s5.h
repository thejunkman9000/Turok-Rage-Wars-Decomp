#ifndef SHARED_SHARED_FUNC_80286A78_S5_H
#define SHARED_SHARED_FUNC_80286A78_S5_H

#include "types.h"

typedef struct Shared_func_80286A78_S5 Shared_func_80286A78_S5;
struct Shared_func_80286A78_S5 {
    char pad0[0x84];
    u8 address84; /* +0x84: src/func_80286A78.c */
    char pad85[0xF];
    u8 unk94; /* +0x94: src/func_80286A78.c */
};
typedef char Shared_func_80286A78_S5_size_check[(sizeof(Shared_func_80286A78_S5) == 0x95) ? 1 : -1];

#endif
