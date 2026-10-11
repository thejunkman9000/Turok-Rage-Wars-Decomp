#include "b21_types.h"

extern f32 D_800CA564;
extern f32 D_800CA568;
extern s32 D_800E28D0;
extern s32 D_800E28D4;
void func_00293100(B21Game *g, u8 *col, s32 a, s32 b, s32 c, s32 d);

void func_00293378(B21Game *g) {
    u8 col[4];
    f32 t;
    s32 v;
    col[0] = 0;
    col[1] = 0;
    col[2] = 0;
    t = g->unk26DC4;
    if (t < 0.0f) goto c255;
    if (D_800CA564 < t) { v = 0; goto done; }
    if (t < 0.0f) { c255: v = 255; } else { v = ~(s32)(t * D_800CA568); }
    done:;
    col[3] = v;
    func_00293100(g, col, 0, 0, D_800E28D0, D_800E28D4);
}
