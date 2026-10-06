#include "b06_types.h"

extern s32 D_800CE3E8[];
extern ActorRow400 D_80102B10[];
extern u8 D_801462D5;
s32 func_0022ACA8(Plr *a, s32 i) {
    s32 v;
    u8 g;
    s32 *d;
    if (i == -1) {
        return 0;
    }
    g = D_801462D5;
    if (g != 1) {
        d = a->unk18->unk108;
        v = d[i];
    } else {
        v = D_800CE3E8[i];
        if (a->unk1450 == 0) {
            if (i == 0) {
                v += B6F(&D_80102B10[a->unk5D4], u8, 5);
            } else if (i == g) {
                v += B6F(&D_80102B10[a->unk5D4], u8, 6);
            } else if (i == 2) {
                v += B6F(&D_80102B10[a->unk5D4], u8, 4);
            }
        }
    }
    return v;
}
