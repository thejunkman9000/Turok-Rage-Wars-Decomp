#include "p1_types.h"

extern DlCmd *D_80110634;
extern u8 D_800D14B0[];
extern u8 D_800D2F18[];
extern u8 D_801469A0[];
extern f32 D_800CB020;
void func_0026D8F8(void);
void func_00296FF8(void);

#define GFX(a, b) { DlCmd *_g = D_80110634++; _g->w0 = (a); _g->w1 = (b); }

typedef struct Dead28 {
    u8 pad[0x90];
    s32 a, b, c, d, e;
    f32 f;
    s32 g;
} Dead28;

void func_002A6488(void *dl) {
    Dead28 z;
    z.a = 0;
    z.b = 0;
    z.c = 0;
    z.e = 0;
    z.f = D_800CB020;
    z.g = 0;
    GFX(0xE7000000, 0)
    GFX(0xE3000A01, 0x100000)
    GFX(0xFD900000, (u32)D_800D14B0)
    GFX(0xF5900000, 0x07080200)
    GFX(0xE6000000, 0)
    GFX(0xF3000000, 0x0707F400)
    GFX(0xE7000000, 0)
    GFX(0xF5880400, 0x00080200)
    GFX(0xF2000000, 0x0003C03C)
    GFX(0xFA00FFFF, 0xC8000096)
    GFX(0xDE000000, (u32)D_800D2F18)
    GFX(0xDA380003, (u32)dl)
    GFX(0x01004008, (u32)D_801469A0)
    GFX(0x06000204, 0x00040600)
    func_0026D8F8();
    func_00296FF8();
}
