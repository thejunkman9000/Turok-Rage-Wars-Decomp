#include "o02_types.h"
typedef struct { u32 w0; u32 w1; } O02Gfx;
extern O02Gfx *D_80110634;
extern u32 D_800E32D8;
extern s32 D_800E32E4;
#define GFX(a, b) { O02Gfx *_g = D_80110634++; _g->w0 = (a); _g->w1 = (b); }
s32 func_004173FC(s32 mode, u32 tex) {
    u32 sz;
    u32 t = tex;
    s32 ret = 1;
    if (D_800E32D8 != t) {
        D_800E32D8 = t;
        if (D_800E32E4 == 0) {
            D_800E32E4 = 1;
            GFX(0xE7000000, 0);
        }
        ret = 0;
        if (mode == 4) {
            sz = 0x0703C000;
            goto emit;
        } else if (mode == 8) {
            sz = 0x073FC000;
emit:
            GFX(0xE3001001, 0x8000);
            GFX(0xFD100000, t);
            GFX(0xE8000000, 0);
            GFX(0xF5000100, 0x07000000);
            GFX(0xE6000000, 0);
            GFX(0xF0000000, sz);
            GFX(0xE7000000, 0);
        } else if (mode == 0x10) {
            GFX(0xE3001001, 0);
        }
    }
    return ret;
}
