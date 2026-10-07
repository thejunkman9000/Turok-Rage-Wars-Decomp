#include "b04_types.h"
extern f32 D_800C72C0, D_800C72C4;
f32 func_00274640(f32);
typedef struct { u8 pad0[8]; f32 x; u8 pad0C[4]; f32 z; u8 pad14[0x58]; f32 unk6C; } B04Av;
f32 func_00216F44(B04Av *o, Vec3f v) {
    f32 dx, dz, len, s, c, q, r;
    dx = v.x - o->x;
    dz = v.z - o->z;
    len = sqrtf(dx * dx + dz * dz);
    if (len != 0.0f) {
        s = sinf(o->unk6C);
        c = cosf(o->unk6C); c = -c;
        q = ((dx * -s) + (dz * c)) / len;
        if (q > D_800C72C0) q = D_800C72C0;
        else if (q < D_800C72C4) q = D_800C72C4;
        else if (q > D_800C72C0) q = D_800C72C0;
        r = func_00274640(q);
        if (!((c * dx + s * dz) > 0.0f))
            r = -r;
        return r;
    }
    return 0.0f;
}
