#include "r05_types.h"

extern const f32 D_800C92E8;
extern const f32 D_800C92EC;
extern const f32 D_800C9318;

s32 func_00253294(void *p);
void *func_0028FD94(void *t, s32 i);

#define FLOORI(x) (((x) >= 0.0f) ? (s32)(x) : (((f32)(s32)(x) == (x)) ? (s32)(x) : (s32)(x) - 1))
#define CEILI(x) (((x) <= 0.0f) ? (s32)(x) : ((((f32)(s32)(x)) == (x)) ? 0 : 1) + (s32)(x))

void func_00261EB8(R05Anim *a, R05AnimOut *o)
{
    s32 ok;
    s32 s0;
    s32 i0;
    s32 i1;
    f32 t;
    f32 n;
    void *s1;
    void *s2;
    void *root;
    u32 uc;
    f32 scale;

    if (a->data == 0) {
        ok = 0;
    } else {
        ok = func_00253294(a->data) != 0;
    }
    if (ok) {
        root = *a->data;
        s1 = func_0028FD94(root, 1);
        s2 = func_0028FD94(root, 5);
        func_0028FD94(s2, 0);
        s0 = a->loopStart;
        t = a->time;
        n = (f32)a->count;
        scale = D_800C92E8;
        o->unk0 = (s32)s1 + 8;
        o->unk4 = (s32)func_0028FD94(root, 2) + 8;
        o->unk8 = (s32)func_0028FD94(s2, 1);
        o->unkC = (s32)func_0028FD94(s2, 2);
        o->frac = t - (f32)FLOORI(t);
        if (s0 == 0xFFFF) {
            s0 = 0;
            i0 = FLOORI(t);
            if (n <= (f32)i0) {
                i0 = 0;
            }
            i1 = i0 + 1;
            if (n <= (f32)i1) {
                i1 = 0;
            }
        } else {
            i0 = FLOORI(t);
            if (n - D_800C92EC <= (f32)i0) {
                uc = a->loopStart;
                i0 = CEILI((f32)uc * scale);
            }
            i1 = i0 + 1;
            if (n - D_800C9318 <= (f32)i1) {
                uc = a->loopStart;
                i1 = CEILI((f32)uc * scale);
            }
        }
        o->off0 = i0 * 4;
        o->off1 = i1 * 4;
        i0 = FLOORI(t);
        i1 = i0 + 1;
        if (n <= (f32)i0) {
            i0 = CEILI((f32)s0 * scale);
            i1 = i0 + 1;
        }
        if (n <= (f32)i1) {
            i1 = CEILI((f32)s0 * scale);
            o->off2 = i0 * 4;
        } else {
            o->off2 = i0 * 4;
        }
        o->off3 = i1 * 4;
    }
}