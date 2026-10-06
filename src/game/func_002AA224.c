#include "b24_types.h"

extern DlCmd *D_80110634;
extern s32 D_800E28D8;
s32 func_00268CE0(s32);
s32 func_0026925C(s32);

#define GFX(a, b) { DlCmd *_g = D_80110634++; _g->w0 = (a); _g->w1 = (b); }

void func_002AA224(u32 c) {
    GFX(0xE7000000, 0)
    GFX(0xE3000A01, 0x100000)
    func_00268CE0(0x1B);
    func_0026925C(0x19);
    GFX(0xFB000000, c | 0xFFFFFF00)
    GFX(0xD7000002, 0x80008000)
    GFX(0xE3001001, 0)
    GFX(0xE3000C00, 0)
    if (D_800E28D8 == 0) {
        GFX(0xE3001201, 0)
    } else {
        GFX(0xE3001201, 0x2000)
    }
}
