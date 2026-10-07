#include "b17_types.h"

extern s32 D_800D2978;
extern s8 D_800D2854[];

#define CLAMP255(v) if ((v) >= 0x100) (v) = 255; if ((v) < 0) (v) = 0

void func_0027899C(VtxBlk *b, u8 *rgb) {
    s32 i, k, v, t;
    B17Vtx *p, *end;
    u32 f;

    i = 0;
    t = D_800D2978;
    if (!(t & 1)) {
        end = b->v + b->count;
        for (p = b->v; p != end; p++, i++) {
            f = p->flag;
            if (f & 0x70) {
                k = D_800D2854[(t + ((f & 0x70) >> 2)) & 0x3F] >> ((f & 0xC) >> 2);
                v = k + rgb[i * 4];
                CLAMP255(v);
                p->col[0] = v;
                v = k + rgb[i * 4 + 1];
                CLAMP255(v);
                p->col[1] = v;
                v = k + rgb[i * 4 + 2];
                CLAMP255(v);
                p->col[2] = v;
            }
        }
    }
}
