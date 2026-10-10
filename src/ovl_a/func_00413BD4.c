#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_80413728.h"
#include "types.h"
/* Writes a 0xAARRGGBB colour to the pixel at (x, y) of the current target image D_80153D58:
   converts the colour to the format's packed value like func_80413CE0_de, then stores it and the
   index x + y * width for the format's store hook D_80153CD4 and calls it. */



extern func_8022BECC_S2 *D_80153D58;
extern s32 D_80153C6C;
extern u32 D_80153C74;
extern u32 D_8014DA10;
extern u32 D_8014DA14;
extern u32 D_8014DA18;
extern u32 D_8014DA1C;




extern void (*D_80153CD4)(void);

void func_80413B54_de(s32 x, s32 y, u32 color) {
    u32 r;
    u32 g;
    u32 b;
    u32 a;

    r = (color >> 16) & 0xFF;
    g = (color & 0xFF00) >> 8;
    b = color & 0xFF;
    a = color >> 24;
    if (D_8014DA1C == 0) {
        a = 0xFF;
    }
    if (D_8014DA30 < 0) {
        r = (r >> -D_8014DA30) & D_8014DA10;
    } else {
        r = (r << D_8014DA30) & D_8014DA10;
    }
    if (D_8014DA34 < 0) {
        g = (g >> -D_8014DA34) & D_8014DA14;
    } else {
        g = (g << D_8014DA34) & D_8014DA14;
    }
    if (D_8014DA38 < 0) {
        b = (b >> -D_8014DA38) & D_8014DA18;
    } else {
        b = (b << D_8014DA38) & D_8014DA18;
    }
    if (D_8014DA3C < 0) {
        a = (a >> -D_8014DA3C) & D_8014DA1C;
    } else {
        a = (a << D_8014DA3C) & D_8014DA1C;
    }
    D_80153C74 = r | g | b | a;
    D_80153C6C = x + y * D_80153D58->unk8;
    D_80153CD4();
}
