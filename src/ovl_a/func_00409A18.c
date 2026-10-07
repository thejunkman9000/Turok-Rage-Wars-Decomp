#include "o01_types.h"

typedef struct O01Save {
    /* 0x0 */ u16 w[4];
    /* 0x8 */ u8 b0;
    /* 0x9 */ u8 b1;
    /* 0xA */ u8 b2;
    /* 0xB */ u8 b3;
} O01Save;
typedef struct O01SaveSrc {
    /* 0x00 */ u16 w[4];
    /* 0x08 */ u8 pad8[0x78];
    /* 0x80 */ u8 b0;
    /* 0x81 */ u8 pad81[3];
    /* 0x84 */ u8 tail[8];
} O01SaveSrc;
typedef struct O01Actor {
    /* 0x000 */ u8 pad0[0x5D8];
    /* 0x5D8 */ O01SaveSrc *save;
} O01Actor;
extern O01Save D_80153738;
extern u8 D_80153744[8];

void func_00409A18(O01Actor *a) {
    O01SaveSrc *p = a->save;
    s32 i;
    D_80153738.b0 = p->b0;
    D_80153738.w[0] = p->w[0];
    D_80153738.w[1] = p->w[1];
    D_80153738.w[2] = p->w[2];
    D_80153738.w[3] = p->w[3];
    D_80153738.b1 = 0;
    D_80153738.b2 = 0;
    D_80153738.b3 = 0;
    for (i = 0; i < 8; i++) {
        D_80153744[i] = p->tail[i];
    }
}
