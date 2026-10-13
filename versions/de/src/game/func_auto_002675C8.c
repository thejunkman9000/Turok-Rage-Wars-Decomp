#include "b15_types.h"

typedef struct B15R {
    u16 a;
    u16 pad;
    s8 b;
    u8 pad2[3];
} B15R;

f32 func_002672E8(B15Src *src);
f32 sqrtf(f32 x);
void func_00271FD8(Vec3f *out, void *a, void *b);
void func_0027200C(Vec3f *out, Vec3f *v, f32 s);
void func_002720EC(Vec3f *v);
extern f32 D_800C9524;
extern f32 D_800C9528;

void func_auto_002675C8(B15Src *act, B15Src *src, B15R k, Vec3f *out) {
    Vec3f q;
    Vec3f v;
    u8 unused[0x4C];

    f32 s;
    f32 d;
    f32 t;

    s = k.a * D_800C9524;
    t = func_002672E8(src);
    out->x = out->y = out->z = 0.0f;
    s = s * t;
    if (*(s32 *)((u8 *)act + 0x174) != 0 && src->type == 2) {
        func_00271FD8((&v), (u8 *)act + 8, (u8 *)src + 8);
        d = sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
        func_002720EC((&v));
        if (!(s <= d)) {
            func_0027200C(out, (&v), k.b * (((s - d) / s) * D_800C9528));
        }
    }
}
