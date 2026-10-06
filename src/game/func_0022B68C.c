#include "p2_types.h"
extern f32 D_800CE3E4;
void func_00216488(s32 *out, s32 a, u8 *b, f32 c, s32 d, s32 e);
void func_00219A40(Player *p, void *a, s32 *b);

void func_0022B68C(Player *p, f32 d, s32 a) {
    s32 buf[6]; f32 x = p->f12C0 - d; f32 t = D_800CE3E4; if (!(x <= t)) t = x; p->f12C0 = t; if (t <= D_800CE3E4) { func_00216488(buf, a, p->f174 + 0x1900, 25.599998f, 0x80, 0); func_00219A40(p, &p->f170, buf); }
}
