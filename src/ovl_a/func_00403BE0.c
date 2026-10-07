#include "o01_types.h"

typedef struct O01G {
    /* 0x00 */ u8 pad0[0x34];
    /* 0x34 */ s32 unk34;
    /* 0x38 */ u8 pad38[0x3C];
    /* 0x74 */ s32 unk74;
} O01G;
extern O01G D_8011FE88[];
extern u8 D_800E0B2C[];
void *func_0028FE1C(s32 *tbl, u8 *base, s32 idx, s32 *size);
s32 *func_002518DC(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, void *g, void *h, s32 i);

s32 *func_00403BE0(void) {
    s32 size;
    s32 *r;
    s32 *p = func_0028FE1C((s32 *)D_8011FE88->unk74, (u8 *)D_8011FE88->unk34, 0, &size);
    if (p != 0) {
        r = func_002518DC(0, (s32)p, (s32)p, size, 0x33, 0, 0, D_800E0B2C, 1);
    } else {
        r = 0;
    }
    return r;
}
