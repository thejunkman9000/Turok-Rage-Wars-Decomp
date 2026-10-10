#ifndef SHARED_SHARED_FUNC_80286A78_S3_H
#define SHARED_SHARED_FUNC_80286A78_S3_H

#include "types.h"

typedef struct Shared_func_80286A78_S3 Shared_func_80286A78_S3;
struct Shared_func_80286A78_S3 {
    char pad0[0x78];
    u8 unk78; /* +0x78: src/func_80286A78.c */
    char pad79[0x18];
    u8 unk91; /* +0x91: src/func_80286A78.c */
};
typedef char Shared_func_80286A78_S3_size_check[(sizeof(Shared_func_80286A78_S3) == 0x92) ? 1 : -1];

#endif
