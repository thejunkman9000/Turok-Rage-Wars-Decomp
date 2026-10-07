#include "o02_types.h"
typedef struct { u32 w0; u32 w1; } O02Gfx;
extern O02Gfx *D_80110634;
extern s32 D_800E32C0;
extern s32 D_800E32E4;
extern s32 D_80153F6C;
#define GFX(a, b) { O02Gfx *_g = D_80110634++; _g->w0 = (a); _g->w1 = (b); }
void func_00416D74(s32 mode) {
    if (mode != D_800E32C0) {
        D_800E32C0 = mode;
        if (D_800E32E4 == 0) {
            D_800E32E4 = 1;
            GFX(0xE7000000, 0);
        }
        GFX(0xE3000A01, 0);
        switch (mode) {
        case 1:
            if (D_80153F6C) {
                GFX(0xFC12B225, 0xFF67DBED);
            } else {
                GFX(0xFC12FE25, 0xFFFFFDFE);
            }
            break;
        case 2:
            if (D_80153F6C) {
                GFX(0xFC12FE25, 0xFFFFF7FB);
            } else {
                GFX(0xFC12FE25, 0xFFFFFDFE);
            }
            break;
        case 3:
            GFX(0xFC12FE25, 0xFFFFFDFE);
            break;
        case 4:
            if (D_80153F6C) {
                GFX(0xFC121824, 0xFF33FFFF);
            } else {
                GFX(0xFC127E24, 0xFFFFFDFE);
            }
            break;
        case 5:
            if (D_80153F6C) {
                GFX(0xFCFFFFFF, 0xFFFE793C);
            } else {
                GFX(0xFCFFFFFF, 0xFFFE7D3E);
            }
            break;
        }
    }
}
