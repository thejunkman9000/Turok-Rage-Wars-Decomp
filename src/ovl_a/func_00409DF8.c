#include "o01_types.h"

typedef struct O01Sub20 {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ s8 unk4;
    /* 0x05 */ u8 pad5[0xAB];
    /* 0xB0 */ u32 unkB0;
} O01Sub20;
typedef struct O01Obj {
    /* 0x00 */ u8 pad0[0x1C];
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ O01Sub20 *unk20;
} O01Obj;
extern s32 D_800E28CC;
extern s32 D_80146D60;

s32 func_00409DF8(O01Obj *a) {
    if ((a->unk20->unkB0 & 0x1000) != 0) {
        if (D_800E28CC == 0) {
            D_80146D60 = 1;
            D_800E28CC = 1;
        }
    }
    return D_80146D60;
}
