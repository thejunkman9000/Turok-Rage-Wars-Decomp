#include "b08_types.h"

typedef struct LightFx {
    u8 pad0[0x520];
    u8 rgb[3];
    u8 pad523[1];
    u8 old[3];
} LightFx;

void func_002720EC(Vec3f *v);

extern u32 D_800D2980;
extern u8 D_800D0EE0[];
extern u8 D_800D0EE2[];
extern u8 D_800D0EEA[];
extern u8 D_800D0EEC[];
extern u8 D_800D0EF1;
extern u8 D_800D0EF2;

void func_00233DEC(LightFx *o) {
    Vec3f v;
    f32 a;
    f32 b;
    u8 *p;
    u8 *w1;
    u8 *w2;
    u8 *q;
    u8 *t;
    s32 i;
    s32 idx;
    u32 c;
    u32 hi;
    f32 one;
    f32 one2;

    one = 1.0f;
    one2 = one;
    i = 0;
    hi = 0x80000000;
    p = D_800D0EE0;
    idx = 2;
    for (; i < 3; i++) {
        a = one2 * (sinf(one * (f32)D_800D2980 * ((f32)idx * 4.0f) * 0.017453294f) * 16.0f) + 16.0f + 48.0f;
        w1 = p;
        if (a >= 2147483648.0f) goto big1;
        c = (s32)a;
        goto end1;
    big1:
        c = (u32)(s32)(a - 2147483648.0f) | hi;
    end1:
        w1[0] = c;
        D_800D0EE2[idx] = c;
        b = sinf(one * (f32)D_800D2980 * ((f32)idx * 4.0f) * 0.017453294f) * 64.0f + 255.0f - 64.0f - 1.0f;
        w2 = p;
        if (b >= 2147483648.0f) goto big2;
        c = (s32)b;
        goto end2;
    big2:
        c = (u32)(s32)(b - 2147483648.0f) | hi;
    end2:
        p++;
        w2[8] = c;
        D_800D0EEA[idx] = c;
        idx++;
        q = D_800D0EEC;
    }
    v.x = sinf((f32)(D_800D2980 * 6) * 0.017453294f);
    v.y = sinf((f32)(D_800D2980 << 3) * 0.017453294f);
    v.z = cosf((f32)(D_800D2980 * 10) * 0.017453294f);
    func_002720EC(&v);
    v.x = v.x * 120.0f;
    v.y = v.y * 120.0f;
    v.z = v.z * 120.0f;
    t = q + 4;
    *t = (u32)v.x;
    D_800D0EF1 = (u32)v.y;
    D_800D0EF2 = (u32)v.z;
    o->old[0] = o->rgb[0] = (u32)(sinf(one * (f32)D_800D2980 * 2.0f * 0.06981318f) * 64.0f + 128.0f) & 0xF8;
    o->old[1] = o->rgb[1] = (u32)(sinf(one * (f32)D_800D2980 * 0.20943953f) * 64.0f + 128.0f) & 0xF8;
    o->old[2] = o->rgb[2] = (u32)(sinf(one * (f32)D_800D2980 * 0.2792527f) * 64.0f + 128.0f) & 0xF8;
}
