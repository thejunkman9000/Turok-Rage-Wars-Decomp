#ifndef RW_FUNC_8022B69C_DE_LAYOUT_H
#define RW_FUNC_8022B69C_DE_LAYOUT_H
#include "types.h"

typedef struct {
    char pad0[0x170];
    char unk170;
    char pad170[0x174 - 0x170 - sizeof(char)];
    s32 unk174;
    char pad174[0x12C0 - 0x174 - sizeof(s32)];
    f32 unk12C0;
} func_8022B68C_S1;

#endif
