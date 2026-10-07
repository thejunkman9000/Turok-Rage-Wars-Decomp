#include "q04_types.h"
typedef struct { u8 pad0[2]; s16 unk2; s16 unk4; u8 pad6[6]; Q04Item *unkC; s32 unk10; u8 pad14[0x30 - 0x14]; f32 unk30; u8 pad34[0x40 - 0x34]; void *unk40; } Q04W;
typedef struct { u8 pad[0x29C]; f32 unk29C; f32 unk2A0; f32 unk2A4; f32 unk2A8; } Q04V;
typedef struct { u8 pad[8]; u32 unk8; } Q04B;
extern void func_0043F69C(Q04Item *it, void *info);
extern void func_002AB9E4(void);
extern void func_002A8DD4(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h, s32 i, s32 j);
extern s32 D_800E28D0;
extern s32 D_800E28D4;
void func_00441D50(Q04W *a, Q04B *b, s32 c) {
    struct { s32 f, w, h, g; } sz;
    struct { s32 f, x0, x1, y0, y1; } r;
    Q04Info info;
    Q04V *cam;
    s32 i, v, v2, v3, v4;
    f32 base, half, t, y0, k;
    u32 al;
    cam = a->unk40;
    switch (b->unk8 & 0x3FE0) {
    case 0x20: r.x0 = 0x400; r.x1 = -0x400; r.y0 = 0x400; r.y1 = -0x400; break;
    case 0x40: r.x0 = 0x400; r.x1 = -0x400; r.y0 = 0x400; r.y1 = -0x400; break;
    case 0x200: r.x0 = 0x400; r.x1 = -0x400; r.y0 = 0x400; r.y1 = -0x400; break;
    default: r.x0 = 0x400; r.x1 = -0x400; r.y0 = 0x400; r.y1 = -0x400; break;
    }
    info.f4 = 0; info.f8 = 0; info.x0 = 0; info.x1 = 0; info.y0 = 0; info.y1 = 0;


    for (i = 0; i < a->unk10; i++) {
        func_0043F69C(a->unkC + i, &info);
        v = info.x0; if (r.x0 < v) v = r.x0; r.x0 = v;
        v2 = info.x1; if (v2 < r.x1) v2 = r.x1; r.x1 = v2;
        v3 = info.y0; if (r.y0 < v3) v3 = r.y0; r.y0 = v3;
        v4 = info.y1; if (v4 < r.y1) v4 = r.y1; r.y1 = v4;



    }
    sz.w = r.x1 - r.x0;
    sz.h = r.y1 - r.y0;
    if (sz.w >= 0 && sz.h >= 0) {
        base = cam->unk2A4 + cam->unk29C * 0.5f + (f32)a->unk2;
        sz.w = D_800E28D0;
        half = (f32)(D_800E28D0 / 2);
        r.x0 = (s32)(base - half);
        r.x1 = (s32)(base + half);
        t = (f32)D_800E28D4 * 0.21621622f;
         k = (D_800E28D4 < 0xDF) ? 9.0f : 13.0f; 
        t = t - k;
        if (c != 0) y0 = (cam->unk2A8 + (f32)D_800E28D4 + (f32)a->unk4) - t;
        else y0 = cam->unk2A8 + (f32)a->unk4;
        r.y0 = (s32)y0;
        r.y1 = (s32)((f32)r.y0 + t);
        sz.h = r.y1 - r.y0;
        func_002AB9E4();
        al = (u32)(a->unk30 * 192.0f);
        func_002A8DD4(r.x0, r.y0, r.x1, r.y1, 1, 0, 0, 0, 0, al & 0xFF);
    }
}
