#include "o03_types.h"
typedef struct { u8 pad[4]; s16 w; s16 h; } O3TexH;
extern O3TexH *D_800E32A4;
extern O3Dl *D_80110634;
void func_004192F8(s32 x0, s32 y0, s32 x1, s32 y1, f32 s0, f32 t0, f32 s1, f32 t1) {
    O3Dl *c;
    f32 fw, fh;
    s32 dsdx, dtdy;
    if (D_800E32A4->w != 0) {
        if (D_800E32A4->h != 0 && x0 != x1 && y0 != y1) {
            fw = (f32)(D_800E32A4->w << 10);
            fh = (f32)(D_800E32A4->h << 10);
            dsdx = (s32)((s1 - s0) * fw) / ((x1 - x0) + 1);
            dtdy = (s32)((t1 - t0) * fh) / ((y1 - y0) + 1);
            c = D_80110634++;
            c->w0 = (((((x1 + 1) * 4) & 0xFFF) << 12) | ((((y1 + 1) * 4) & 0xFFF) | 0xE4000000));
            c->w1 = ((((x0 * 4) & 0xFFF) << 12) | ((y0 * 4) & 0xFFF));
            c = D_80110634++;
            c->w0 = 0xE1000000;
            c->w1 = ((((s32)(s0 * fw) >> 5) << 16) | (((s32)(t0 * fh) >> 5) & 0xFFFF));
            c = D_80110634++;
            c->w0 = 0xF1000000;
            c->w1 = ((dsdx << 16) | (dtdy & 0xFFFF));
        }
    }
}
