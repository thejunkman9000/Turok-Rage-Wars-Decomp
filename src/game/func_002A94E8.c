#include "b24_types.h"

extern DlCmd *D_80110634;
extern s32 D_8014D3D0;
extern f32 D_800CB140;
extern s32 D_8013B878[];
s32 func_002ABDAC(void);
s32 func_00268CE0(s32);
s32 func_0026925C(s32);
void func_002ABB2C(s32, s32, s32, s32, s32, s32);
void func_002ABB58(f32, f32);

#define PUSH(a, b) { DlCmd *_g = D_80110634++; _g->w0 = (a); _g->w1 = (b); }

void func_002A94E8(void) {
    s32 tex;
    tex = func_002ABDAC();
    if (tex != 0) {
        PUSH(0xE7000000, 0)
        PUSH(0xE3000A01, 0x100000)
        func_00268CE0(0x1A);
        func_0026925C(0x15);
        D_8014D3D0 = 0;
        PUSH(0xD7000002, 0x80008000)
        PUSH(0xE3001001, 0)
        PUSH(0xE3000C00, 0)
        PUSH(0xE3001201, 0x2000)
        PUSH(0xFD900000, tex)
        PUSH(0xF5900000, 0x07000000)
        PUSH(0xE6000000, 0)
        PUSH(0xF3000000, 0x0708F800)
        PUSH(0xE7000000, 0)
        PUSH(0xF5800400, 0)
        PUSH(0xF2000000, 0x5C05C)
        PUSH(0xF5800000, 0x01000000)
        PUSH(0xF2000000, 0x0103C03C)
        func_002ABB2C(0x8C, 0x8C, 0x8C, 0x8C, 0x8C, 0x8C);
        func_002ABB58(D_800CB140, D_800CB140);
        D_8013B878[0] = 2;
        D_8013B878[1] = 2;
    }
}
