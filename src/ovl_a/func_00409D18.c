#include "o01_types.h"

typedef struct O01Sub3 {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ s8 unk4;
} O01Sub3;
typedef struct O01Obj3 {
    /* 0x00 */ u8 pad0[0x20];
    /* 0x20 */ O01Sub3 *unk20;
} O01Obj3;
extern s32 D_80153784;
extern s32 D_8015375C;
extern s32 D_800E28C8;
s32 func_002645F0(s32 pad);
s32 func_00406178(O01Obj3 *o, s32 pad, s32 z);

static inline s32 O01GetPad(O01Obj3 *o) {
    if (D_8015375C != 0) {
        return D_800E28C8;
    }
    return o->unk20->unk4;
}

s32 func_00409D18(O01Obj3 *a) {
    if (D_80153784 == 0) {
        if (O01GetPad(a) != -1) {
            if (func_002645F0(O01GetPad(a)) != 0) {
                if (func_00406178(a, O01GetPad(a), 0) != 0) {
                    D_80153784 = 1;
                }
            }
        }
    }
    return D_80153784;
}
