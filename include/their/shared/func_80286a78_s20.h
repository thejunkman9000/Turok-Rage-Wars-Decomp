#ifndef SHARED_SHARED_FUNC_80286A78_S20_H
#define SHARED_SHARED_FUNC_80286A78_S20_H

#include "types.h"

typedef struct Shared_func_80286A78_S20 Shared_func_80286A78_S20;
struct Shared_func_80286A78_S20 {
    char pad0[0x8];
    u8 address8; /* +0x8: src/func_80286A78.c */
    char pad9[0x144B];
    void * unk1454; /* +0x1454: src/func_80286A78.c */
    char pad1458[0x288];
    void * unk16E0; /* +0x16E0: src/func_80286A78.c */
};
typedef char Shared_func_80286A78_S20_size_check[(sizeof(Shared_func_80286A78_S20) == 0x16E4) ? 1 : -1];

#endif
