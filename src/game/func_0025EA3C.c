#include "r05_types.h"

extern const f32 D_800C9184;

void *func_0028FD94(void *t, s32 i);
void func_00270B1C(f32 *out, f32 t, void *a, void *b);

#define FLOORI(x) (((x) >= 0.0f) ? (s32)(x) : (((f32)(s32)(x) == (x)) ? (s32)(x) : (s32)(x) - 1))
#define CEILI(x) (((x) <= 0.0f) ? (s32)(x) : ({ s32 _c = ((((f32)(s32)(x)) == (x)) ? 0 : 1); _c + (s32)(x); }))

void func_0025EA3C(R05Anim *a, s32 idx, f32 time, f32 *out)
{
    void *root;
    void *blk;
    R05CurveCfg *cfg;
    f32 scale;
    f32 n;
    f32 frac;
    s16 sel;
    void *keys;
    u32 ua;
    s32 i0;
    s32 i1;
    u8 *tab;
    u8 *p;
    s32 *v2;
    s32 off;
    u32 ub;

    root = *a->data;
    blk = func_0028FD94(root, 5);
    cfg = func_0028FD94(blk, 0);
    tab = func_0028FD94(root, 1);
    scale = cfg->scale;
    sel = *(s16 *)(tab + (idx << 2) + 0xA);
    n = cfg->n;
    time = time * scale;
    if (sel == -1) {
        v2 = func_0028FD94(root, 2);
        off = idx * *v2 + 8;
        p = (u8 *)v2 + off;
        out[0] = (f32)*(s16 *)(p + 0xC) * D_800C9184;
        out[1] = (f32)*(s16 *)(p + 0xE) * D_800C9184;
        out[2] = (f32)*(s16 *)(p + 0x10) * D_800C9184;
        out[3] = (f32)*(s16 *)(p + 0x12) * D_800C9184;
        return;
    }
    keys = func_0028FD94(func_0028FD94(blk, 2), sel);
    if (a->loopStart == 0xFFFF) {
        i0 = FLOORI(time);
        if (n <= (f32)i0) {
            i0 = 0;
        }
        i1 = i0 + 1;
        if (n <= (f32)i1) {
            i1 = 0;
        }
    } else {
        i0 = FLOORI(time);
        if (n - 1.0f <= (f32)i0) {
            ua = a->loopStart;
            i0 = CEILI((f32)ua * scale);
        }
        i1 = i0 + 1;
        if (n - 1.0f <= (f32)i1) {
            ub = a->loopStart;
            i1 = CEILI((f32)ub * scale);
        }
    }
    frac = time - (f32)FLOORI(time);
    func_00270B1C(out, frac, (u8 *)keys + i0 * 16, (u8 *)keys + i1 * 16);
}
