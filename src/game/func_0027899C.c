#include "b17_types.h"

extern s32 D_800D2978;
extern s8 D_800D2854[];

#define CLAMP255(v) if ((v) >= 0x100) (v) = 255; if ((v) < 0) (v) = 0

void func_0027899C(VtxBlk *b, u8 *rgb) {
    s32 i;
    s32 k;
    s32 v;
    s32 t;
    B17Vtx *p;
    B17Vtx *end;
    u8 *c;
    u32 f;

    i = 0;
    t = D_800D2978;
    if (!(t & 1)) {
        p = b->v;
        end = p + b->count;
        if (p != end) do {
            f = p->flag;
            if (f & 0x70) {
                k = D_800D2854[(t + ((f & 0x70) >> 2)) & 0x3F];
                k = k >> ((f & 0xC) >> 2);
                c = (u8 *)(((u32)rgb) + (i * 4));
                v = k + c[0];
                CLAMP255(v);
                p->col[0] = v;
                v = k + c[1];
                CLAMP255(v);
                p->col[1] = v;
                v = k + c[2];
                CLAMP255(v);
                p->col[2] = v;
            }
            p++;
            i++;
        } while (p != end);
    }
}
