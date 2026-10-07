#include "b17_types.h"

extern u32 D_801462C8;
extern u32 D_801462D8;

#define CLAMP255(v) if ((v) >= 0x100) (v) = 255; if ((v) < 0) (v) = 0
#define MN(a, b) ((a) < (b) ? (a) : (b))

void func_002782E4(VtxBlk *b, Vec3f *src) {
    Vec3f t;
    f32 f, x;
    s32 i, n, v;
    B17Vtx *vp;

    f = MN(1.0f, (f32)D_801462D8 * 0.003921568859f);
    vp = b->v;
    n = b->count;
    if (D_801462C8 & 0x4000) {
        for (i = 0; i < n; i++) {
            vp[i].col[0] = 0;
            vp[i].col[1] = 0;
            vp[i].col[2] = 0;
        }
    } else {
        for (i = 0; i < n; i++) {
            t = *src;
            src++;
            x = t.x;
            if (!(x <= 255.0f)) x = 255.0f;
            if (!(5.0f <= x)) x = 5.0f;
            t.x = x * (1.0f - f) + f * 255.0f;
            x = t.y;
            if (!(x <= 255.0f)) x = 255.0f;
            if (!(5.0f <= x)) x = 5.0f;
            t.y = x * (1.0f - f) + f * 255.0f;
            x = t.z;
            if (!(x <= 255.0f)) x = 255.0f;
            if (!(5.0f <= x)) x = 5.0f;
            t.z = x * (1.0f - f) + f * 255.0f;
            if (!(vp[i].flag & 0x80)) {
                v = (s32)t.x;
                CLAMP255(v);
                vp[i].col[0] = v;
                v = (s32)t.y;
                CLAMP255(v);
                vp[i].col[1] = v;
                v = (s32)t.z;
                CLAMP255(v);
                vp[i].col[2] = v;
            }
        }
    }
}
