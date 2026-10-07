#include "m05_types.h"

typedef struct M5Shape {
    /* 0x00 */ f32 f0;
    /* 0x04 */ u8 pad4[0x10];
    /* 0x14 */ M5Vec3 pos;
    /* 0x20 */ u8 pad20[0x9B];
    /* 0xBB */ u8 mode;
} M5Shape;

extern f32 D_800C9BB0;
extern f32 D_800C9BB4;
extern f32 D_800C9BB8;
extern f32 D_800C9BBC;
extern f32 D_800C9BC0;
extern f32 D_800C9BC4;
extern f32 D_800D2648[];
extern f32 D_800D274C[];
void func_002720EC(M5Vec3 *);

s32 func_00277198(M5Shape *o, M5Vec3 v, M5Vec3 *out, f32 *res) {
    f32 s = 0.0f;
    if (!(v.x >= D_800C9BB0) && !(v.x <= D_800C9BB4) && !(v.y >= D_800C9BB0) && !(v.y <= D_800C9BB4) &&
        !(v.z >= D_800C9BB0) && !(v.z <= D_800C9BB4)) {
        switch (o->mode) {
        case 0:
            s = v.x * v.x + v.y * v.y + v.z * v.z;
            if (D_800C9BB0 < s) goto fail;
            s = D_800D2648[(s32)(s * D_800C9BB8)];
            break;
        case 2:
            if (v.x <= 0.0f) goto fail;
            s = v.y * v.y + v.z * v.z;
            if (v.x * v.x < s) goto fail;
            s = D_800D274C[(s32)(s * D_800C9BBC)];
            s = s / v.x;
            break;
        case 1:
            { f32 t = v.x; if (t < 0.0f) t = -t; v.x = t; }
            { f32 t = v.y; if (t < 0.0f) t = -t; v.y = t; }
            { f32 t = v.z; if (t < 0.0f) t = -t; v.z = t; }
            s = v.z;
            if (!(v.y <= s)) s = v.y;
            if (!(v.x <= s)) s = v.x;
            break;
        }
        s = D_800C9BC0 - s;
        if (s < o->f0) {
            s = s / o->f0;
        } else {
            s = D_800C9BC0;
        }
        if (o->mode == 1) {
            *out = o->pos;
        } else {
            *out = v;
        }
        func_002720EC(out);
        *res = s;
        return 1;
    }
fail:
    out->y = 0.0f;
    out->z = 0.0f;
    out->x = D_800C9BC4;
    *res = 0.0f;
    return 0;
}
