#include "b15_types.h"

typedef struct B15Own { u8 pad[0x16D4]; s32 unk16D4; } B15Own;
void func_0022B10C(void *a, u16 v);
void func_00271FD8(Vec3f *out, void *a, void *b);
extern f32 D_800C9574;

void func_002688E4(Actor *act, B15Src *src, s32 c, Vec3f pos, B15Pair k) {
    B15Own *o;
    Vec3f v;
    f32 r;
    f32 d;

    if (*(u8 *)act == 1 && (act->flags & 0x300000)) {
        o = (B15Own *)act->owner;
        if (o->unk16D4 != 0) {
            r = k.a * D_800C9574;
            func_00271FD8(&v, (u8 *)o + 8, (u8 *)src + 8);
            r = r * r;
            d = v.x * v.x + v.y * v.y + v.z * v.z;
            if (!(r < d)) {
                func_0022B10C(o, (s32)(((r - d) / r) * k.b));
            }
        }
    }
}
