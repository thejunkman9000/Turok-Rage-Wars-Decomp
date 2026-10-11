#include "r05_types.h"


void *func_0028FD94(void *t, s32 i);
void func_00270B1C(f32 *out, f32 frac, void *p0, void *p1);

#define FLOORI(x) (((x) >= 0.0f) ? (s32)(x) : (((f32)(s32)(x) == (x)) ? (s32)(x) : (s32)(x) - 1))
#define CEILT(v, x) (((x) <= 0.0f) ? (s32)(x) : ({ v = ((((f32)(s32)(x)) == (x)) ? 0 : 1); v + (s32)(x); }))

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
    s32 off;
    R05Vec3i *src;
    s32 *v2;
    u8 *tab;
    f32 *dst;

    root = *a->data;
    blk = func_0028FD94(root, 5);
    cfg = func_0028FD94(blk, 0);
    tab = func_0028FD94(root, 1);
    scale = cfg->scale;
    sel = *(s16 *)(tab + (idx << 2) + 8);
    n = cfg->n;
    time = time * scale;
    if (sel == -1) {
        v2 = func_0028FD94(root, 2);
        off = idx * *v2 + 8;
        *(R05Vec3i *)out = *(R05Vec3i *)((u8 *)v2 + off);
        return;
    }
    t0 = func_0028FD94(func_0028FD94(blk, 1), sel);
    frac = time - (f32)FLOORI(time);
    ua = a->loopStart;
    dst = out;
    if (ua == 0xFFFF) {
        ua = 0;
    }
    i0 = FLOORI(time);
    if (n <= (f32)i0) {
        i0 = CEILT(i0, (f32)ua * scale);
    }
    i1 = i0 + 1;
    if (n <= (f32)i1) {
        i1 = CEILT(i1, (f32)ua * scale);
    }
    k = 0;
    w = 1.0f - frac;
    do {
        f32 r = (1.0f - frac) * t0[i0 * 4 + k] + frac * t0[i1 * 4 + k];
        k++;
        *dst = r;
        dst++;
    } while (k < 3);
}

#define CEILU(v, x) CEILT(v, x)
