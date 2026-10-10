#include "o04_types.h"
#include "q03_types.h"
extern O04ModeS4690 *D_800E4690;
extern Q03Cfg D_801462C8[];
extern Q03Ent D_80146398[];
u8 *func_00425E50(s32 a, s32 b, s32 c);
s32 func_00265670(void *p, s32 a);
void func_002656A8(void *p, s32 a, s32 b);
void func_00427F50(s32 a) {
    u8 *r;
    s32 s0;
    s32 s1;
    s32 t;
    switch (D_801462C8->unkD) {
    case 1:
        r = func_00425E50(a, 0, D_801462C8->ent[D_800E4690->unkA5C].f80);
        break;
    case 2:
        r = func_00425E50(a, 1, 0);
        break;
    case 3:
        r = func_00425E50(a, 3, 0);
        break;
    case 4:
        r = func_00425E50(a, 2, 0);
        break;
    default:
        r = func_00425E50(a, 0, D_80146398[D_800E4690->unkA5C].f80);
        break;
    }
    t = r[1];
    if (t > 0) {
        s0 = t - 1;
        if (func_00265670(D_800E4690->unkA74, s0) == 0) {
            func_002656A8(D_800E4690->unkA79, s0, 1);
        }
    }
    for (s1 = 0; s1 < 3; s1++) {
        t = (r + s1)[2];
        if (t > 0) {
            if (func_00265670(D_800E4690->unkA74, t - 1) == 0) {
                func_002656A8(D_800E4690->unkA79, t - 1, 1);
            }
        }
    }
}
