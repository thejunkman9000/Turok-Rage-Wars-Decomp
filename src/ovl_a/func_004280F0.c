#include "o04_types.h"
typedef struct { u8 pad0[0x80]; s8 unk80; u8 pad81[0x96 - 0x81]; } O04Ent96l;
extern O04ModeS4690 *D_800E4690;
extern s32 D_8015402C;
extern O04Cfg D_801462C8[];
extern O04GFlags D_801468A0[];
extern O04Ent96l D_80146398[];
u8 *func_00425E50(s32 a, s32 b, s32 c);
s32 func_00265670(void *p, s32 a);
void func_004280F0(void) {
    u8 *r;
    s32 idx;
    s32 i;
    s32 t;
    O04Cfg *cfg;
    D_800E4690->unkA44 = D_8015402C;
    if (D_8015402C >= 0x25) {
        D_800E4690->unkA44 = 0;
    }
    if (func_00265670(D_800E4690->unkA74, D_800E4690->unkA44) == 0) {
        return;
    }
    if (D_801468A0->unkA8 == 0) {
        return;
    }
    cfg = (O04Cfg *)((u8 *)D_801468A0 - 0x5D8);
    switch (cfg->unkD) {
    case 1:
        r = func_00425E50(D_800E4690->unkA44, 0, ((O04Ent96l *)((u8 *)cfg + 0xD0))[D_800E4690->unkA5C].unk80);
        break;
    case 2:
        r = func_00425E50(D_800E4690->unkA44, 1, 0);
        break;
    case 3:
        r = func_00425E50(D_800E4690->unkA44, 3, 0);
        break;
    case 4:
        r = func_00425E50(D_800E4690->unkA44, 2, 0);
        break;
    default:
        r = func_00425E50(D_800E4690->unkA44, 0, D_80146398[D_800E4690->unkA5C].unk80);
        break;
    }
    idx = 0;
    t = r[1];
    if (t > 0) {
        idx = t - 1;
    } else {
        for (i = 0; i < 3; i++) {
            t = (r + i)[2];
            if (t > 0) {
                idx = t - 1;
                break;
            }
        }
    }
    if (idx >= 0x25) {
        idx = 0;
    }
    D_800E4690->unkA44 = idx;
}
