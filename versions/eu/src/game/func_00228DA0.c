#include "b06_types.h"

void func_00271FA4(Vec3f *out, Vec3f *a, Vec3f *b);
void func_00271FD8(Vec3f *out, Vec3f *a, Vec3f *b);
void func_0027200C(Vec3f *out, Vec3f *a, f32 s);
void func_002720EC(Vec3f *v);
extern const f32 D_800C7D04;
extern f32 D_800C7D08;
extern f32 D_800C7D0C;
extern f32 D_800C7D10;
extern f32 D_800D2988;

void func_00228DA0(PlrGroup *g, AimB6 *b) {
    Plr *a;
    s32 any = 0;
    s32 c;
    Vec3f t;
    Vec3f v;
    f32 d2;
    f32 f;
    f32 d;
    for (a = g->head; a != NULL; a = a->next) {
        if (a->unk5D0 != 0) {
            c = 0;
            if (a->unk11FC > 0.0f) {
                c = 1;
            }
            if (c != 0) {
                func_00271FD8(&t, &a->unk1200, &b->pos);
                d2 = t.x * t.x + t.y * t.y + t.z * t.z;
                func_002720EC(&t);
                any = 1;
                if (D_800C7D08 < d2) {
                    f = D_800C7D0C / d2;
                    if (D_800D2988 < D_800C7D04) {
                        f = f * D_800D2988;
                    }
                    if (a->unk120C == 0) {
                        f = -f;
                    }
                    v = b->aim;
                    func_002720EC(&v);
                    d = t.x * v.x + t.y * v.y + t.z * v.z;
                    if (d < 0.0f) {
                        d = -d;
                    }
                    d = d + D_800C7D04;
                    d = d * D_800C7D10;
                    func_0027200C(&t, &t, f * d);
                }
                func_00271FA4(&b->aim, &b->aim, &t);
            }
        }
    }
    if (any != 0) {
        t = b->aim;
        func_002720EC(&t);
        b->out = t;
    }
}
