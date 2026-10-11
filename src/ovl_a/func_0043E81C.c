#include "s1009_types.h"
extern s32 D_800E5E48;
extern f32 D_00450854[];
extern f32 D_801462E8;
extern s32 func_0044252C(S10Menu *a, s32 cur, s32 step, s32 lo, s32 hi, s32 wrap);
extern s32 func_002643C0(void *p);
extern s32 func_0026439C(void *p);
#define MXC(a, b) ((a) < (b) ? (b) : (a))
#define MNB(a, b) ((a) < (b) ? (a) : (b))
s32 func_0043E81C(void *a, S10Menu *m) {
    f32 v;
    D_800E5E48 = func_0044252C(m, D_800E5E48, 1, 0, 0xF, 0);
    if (func_002643C0(m->ctrl) || func_0026439C(m->ctrl)) {
        func_0044252C(m, D_800E5E48, 1, 0, 0xF, 0);
    }
    v = D_00450854[D_800E5E48] + 1.0f;
    v = MNB(2.0f, MXC(v, 0.5f));
    D_801462E8 = v;
    return 0;
}
