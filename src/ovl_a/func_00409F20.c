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
extern s32 D_8015375C;
extern s32 D_800E28C8;

s32 func_00409F20(O01Obj *a, s32 *out) {
    s32 v;
    s32 r;
    if (D_8015375C != 0) {
        v = D_800E28C8;
        r = 0;
    } else {
        v = a->unk20->unk4;
        r = a->unk1C;
    }
    *out = v;
    return r;
}
