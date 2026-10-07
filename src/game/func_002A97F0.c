#include "p4_types.h"
extern P4Gfx *D_80110634;
extern s32 D_8014D3D0;
void *func_002ABDAC(void);
#define P4_GFX(w0v, w1v) { P4Gfx *_g = D_80110634++; _g->words.w0 = (w0v); _g->words.w1 = (w1v); }
void func_002A97F0(void) {
    void *tex = func_002ABDAC();
    if (tex != NULL) {
        D_8014D3D0 = 2;
        P4_GFX(0xFD900000, (u32)tex);
        P4_GFX(0xF5900100, 0x0700C040);
        P4_GFX(0xE6000000, 0);
        P4_GFX(0xF3000000, 0x0701F800);
        P4_GFX(0xE7000000, 0);
        P4_GFX(0xF5800300, 0x0000C040);
        P4_GFX(0xF2000000, 0x0003C01C);
    }
}
