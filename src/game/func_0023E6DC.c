#include "b09_types.h"

extern f32 D_800D0644;
extern f32 D_800C87B8;
extern f32 D_800C87BC;
f32 sqrtf(f32);
f32 func_00241718(B09Quad *, f32, f32);
void func_0027200C(B09V3 *, B09V3 *, f32);

void func_0023E6DC(B09Body *b, B09Quad *q) {
    f32 y0;
    f32 dy;
    f32 dx;
    f32 dz;
    f32 num;
    f32 den;
    f32 s;
    f32 k;
    register f32 xq __asm__("$f4");
    B09V3 *v;
    B09V3 *w;
    y0 = func_00241718(q, b->f44, b->f4C);
    dy = (func_00241718(q, b->f50, b->f58) + D_800D0644 * D_800C87B8) - y0;
    dx = b->f50 - b->f44;
    dz = b->f58 - b->f4C;
    num = dx * dx + dz * dz;
    den = num + dy * dy;
    if (den == 0.0f) {
        b->f54 = y0;
        return;
    }
    s = sqrtf(num / den);
    v = &b->v74;
    w = v;
    xq = y0 + s * dy;
    b->f54 = xq;
    b->f50 = b->f44 + s * (b->f50 - b->f44);
    b->f58 = b->f4C + s * (b->f58 - b->f4C);
    k = b->def->f10;
    if (D_800C87BC < k) {
        k = 0.0f;
    } else {
        k = D_800C87BC - k;
    }
    func_0027200C(v, w, k);
}
