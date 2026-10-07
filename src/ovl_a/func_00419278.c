#include "o03_types.h"
extern u32 D_800E32DC;
extern O3Dl *D_80110634;
void func_00419278(u32 color) {
    u32 rgb;
    if (color != D_800E32DC) {
        D_800E32DC = color;
        rgb = ((color >> 16) << 24) | ((color & 0xFF00) << 8) | ((color & 0xFF) << 8);
        O3_PUSH(0xFB000000, rgb);
        O3_PUSH(0xFA000000, rgb | (color >> 24));
    }
}
