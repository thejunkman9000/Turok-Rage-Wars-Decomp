#include "b09_types.h"

extern f32 D_800D2988;
extern f32 D_800C86E0;
extern f32 D_800D2994;
extern f32 D_800C86E4;
extern const f32 D_800C86E8;
extern const f32 D_800C86EC;

s32 func_0023B708(B09Emitter *e, s32 mask, f32 f2, s32 flag, f32 f4, u8 *ctx) {
    B09EDef *def = e->def;
    f32 x;
    f32 step;
    f32 t;
    if (e->mask & mask) {
        f32 up = e->f208;
        up += def->f20 * D_800D2988;
        if (D_800C86E0 < up) {
            up = D_800C86E0;
        }
        e->f208 = up;
    } else {
        f32 dn;
        if (e->f208 == 0.0f) {
            return 1;
        }
        dn = e->f208 - def->f20 * D_800D2988;
        dn = (dn < 0.0f) ? 0.0f : dn;
        e->f208 = dn;
    }
    e->f20C = e->f20C + D_800D2988 * def->f10 * e->f214;
    step = D_800D2988 * D_800D2994 * def->f8;
    t = e->f1C + step * D_800C86E4;
    e->f1C = t;
    if (D_800C86E8 < t) {
        e->f1C = t - D_800C86E8;
    }
    t = e->f20 + step * D_800C86EC;
    e->f20 = t;
    if (D_800C86E8 < t) {
        e->f20 = t - D_800C86E8;
    }
    x = def->f14 + e->f21C;
    if (flag != 0 && *(s32 *)(ctx + 0x24) == 0) {
        x += f4;
    } else {
        u8 b = def->flags29;
        if (b & 1) {
            x += *(f32 *)(ctx + 0x12C) * def->f1C;
        } else if (b & 2) {
            x += f2;
        }
    }
    e->key = x;
    return 0;
}
