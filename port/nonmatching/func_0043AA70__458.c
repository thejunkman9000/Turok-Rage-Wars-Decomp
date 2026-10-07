#include "o05_types.h"

typedef struct { u32 w0; u32 w1; } O05Gfx;
typedef struct { s32 x0, y0; s32 x1, y1; } O05Scis;
extern O05L2 *D_800E59E0;
extern O05Gfx *D_80110634[];
extern s32 D_800D15E0;
extern f32 D_800D15E4[];
extern f32 D_800D15F0;
extern O05Scis D_800E41C0[];
extern s32 D_800E28D0;
extern s32 D_800E28D4;
void func_0041C864(void *p);
s32 func_00439EA8(void *p);
void func_004399D0(void *p);

s32 func_0043AA70(s32 a, s32 b, s32 ev) {
    s32 i;
    O05Gfx *g;
    f32 sc;
    if (ev == 1) {
        if (D_800E59E0->f1358 == 3) {
            sc = 4.0f;
            D_800D15E0 = 0;
            D_800D15E4[0] = D_800D15E4[1] = D_800D15E4[2] = D_800D15E4[3] = 255.0f;
            for (i = 0; i < 4; i++) {
                if ((u32)(D_800E59E0->row[i].f4A8 - 1) < 2) {
                    g = D_80110634[0];
                    g->w0 = 0xED000000 | (((s32)((f32)D_800E41C0[i].x0 * sc) & 0xFFF) << 12) | ((s32)((f32)D_800E41C0[i].y0 * sc) & 0xFFF);
                    g->w1 = (((s32)((f32)D_800E41C0[i].x1 * sc) & 0xFFF) << 12) | ((s32)((f32)D_800E41C0[i].y1 * sc) & 0xFFF);
                    D_80110634[0] = g + 1;
                    func_0041C864(&D_800E59E0->row[i]);
                }
            }
            g = D_80110634[0]++;
            g->w0 = 0xED000000;
            g->w1 = (((s32)((f32)(D_800E28D0 - 1) * 4.0f) & 0xFFF) << 12) | ((s32)((f32)(D_800E28D4 - 1) * 4.0f) & 0xFFF);
            for (i = 0; i < 4; i++) {
                s32 f = D_800E59E0->row[i].f4A8;
                if (f == 1) {
                    if (func_00439EA8((u8 *)D_800E59E0 + 0x1370 + i * 0xC0) != 0) {
                        D_800D15E0 = f;
                        D_800D15F0 = 150.0f;
                        func_004399D0((u8 *)D_800E59E0 + 0x1370 + i * 0xC0);
                        D_800D15E0 = 0;
                        D_800D15F0 = 255.0f;
                    }
                }
            }
        }
    }
    return 0;
}
