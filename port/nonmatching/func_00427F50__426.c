#include "o04_types.h"
typedef struct { u8 pad0[0x80]; s8 unk80; u8 pad81[0x96 - 0x81]; } O04Ent96l;
extern O04ModeS4690 *D_800E4690;
extern O04Cfg D_801462C8[];
extern O04Ent96l D_80146398[];
u8 *func_00425E50(s32 a, s32 b, s32 c);
s32 func_00265670(void *p, s32 a);
void func_002656A8(void *p, s32 a, s32 b);
void func_00427F50(s32 a) {
    u8 *r;
    s32 s0;
    s32 row;
    s32 s1;
    s32 t;
    row = D_800E4690->unkA5C;
    switch (D_801462C8->unkD) {
    case 1:
        r = func_00425E50(a, 0, ((s8 *)((row * 0x96) + (u8 *)D_801462C8))[0x150]);
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
        r = func_00425E50(a, 0, D_80146398[row].unk80);
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
