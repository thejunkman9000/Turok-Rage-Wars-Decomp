#ifndef SHARED_SHARED_FUNC_80286A78_S7_H
#define SHARED_SHARED_FUNC_80286A78_S7_H

#include "types.h"

typedef struct Shared_func_80286A78_S7 Shared_func_80286A78_S7;
struct Shared_func_80286A78_S7 {
    s32 unk0; /* +0x0: src/func_80286A78.c */
    s32 unk4; /* +0x4: src/func_80286A78.c */
    s32 unk8; /* +0x8: src/func_80286A78.c */
    s32 unkC; /* +0xC: src/func_80286A78.c */
    s32 unk10; /* +0x10: src/func_80286A78.c */
    s32 unk14; /* +0x14: src/func_80286A78.c */
};
typedef char Shared_func_80286A78_S7_size_check[(sizeof(Shared_func_80286A78_S7) == 0x18) ? 1 : -1];

#endif
