#include "r05_types.h"

extern const f32 D_800C9180;

void *func_0028FD94(void *t, s32 i);

#define FLOORI(x) (((x) >= 0.0f) ? (s32)(x) : (((f32)(s32)(x) == (x)) ? (s32)(x) : (s32)(x) - 1))
#define CEILI(x) (((x) <= 0.0f) ? (s32)(x) : ((((f32)(s32)(x)) == (x)) ? 0 : 1) + (s32)(x))

void func_0025E5D0(R05Anim *a, s32 idx, f32 time, f32 *out)
{
    void *root;
    void *blk;
    R05CurveCfg *cfg;
    f32 scale;
    f32 n;
    f32 frac;
    f32 w;
    s16 sel;
    f32 *t0;
    u32 ua;
    s32 i0;
    s32 i1;
    s32 k;
    s32 *v2;
    u8 *tab;

    root = *a->data;
    blk = func_0028FD94(root, 5);
    cfg = func_0028FD94(blk, 0);
    tab = func_0028FD94(root, 1);
    scale = cfg->scale;
    sel = *(s16 *)(tab + idx * 4 + 8);
    n = cfg->n;
    time = time * scale;
    if (sel == -1) {
        v2 = func_0028FD94(root, 2);
        *(R05Vec3i *)out = *(R05Vec3i *)((u8 *)v2 + (idx * *v2 + 8));
        return;
    }
    t0 = func_0028FD94(func_0028FD94(blk, 1), sel);
    frac = time - (f32)FLOORI(time);
    ua = a->loopStart;
    if (ua == 0xFFFF) {
        ua = 0;
    }
    i0 = FLOORI(time);
    i1 = i0 + 1;
    if (n <= (f32)i0) {
        i0 = CEILI((f32)ua * scale);
        i1 = i0 + 1;
    }
    k = 0;
    if (n <= (f32)i1) {
        i1 = CEILI((f32)ua * scale);
    }
    w = D_800C9180 - frac;
    do {
        out[k] = w * t0[i0 * 4 + k] + frac * t0[i1 * 4 + k];
        k++;
    } while (k < 3);
}
