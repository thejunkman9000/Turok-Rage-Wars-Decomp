#include "b11_types.h"

extern u8 D_8011FE88[];
extern f32 D_800C8C3C;
s32 func_0028CF48(void *a, u16 b);
s32 func_0028B370(void *a, u16 b);
s32 func_00285F28(void *a, s32 b);
void func_00246690(s32 a, u16 b, u16 c, s32 d, s32 e, s32 f, s32 g, f32 h, Vec3f i, s32 j, Vec3f k, Vec3f l, s32 m);

void func_0024B398(s32 arg0, B11Spawn *p) {
    Vec3f z;
    s32 s2;
    s32 s1;
    s32 a3;
    u8 t;
    s32 e;
    f32 fs0;
    s2 = func_0028CF48(D_8011FE88, p->u22);
    if (p->u20 == 0xFFFF) {
        s1 = 0;
    } else {
        s1 = func_0028B370(D_8011FE88, p->u20);
    }
    fs0 = p->s24 * D_800C8C3C;
    z.x = z.y = z.z = 0.0f;
    a3 = func_00285F28(D_8011FE88, arg0);
    func_00246690(arg0, p->u1C, p->u1E, p->unk0, s2, p->u27 == 0xFF ? -1 : p->u27, s1, fs0, p->v4, p->u26, p->v10, z, a3);
}
