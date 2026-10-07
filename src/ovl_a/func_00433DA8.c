#include "o05_types.h"

typedef struct { u8 pad[8]; void *f8; } O05WdA;
typedef struct { u8 pad[0x38]; void *f38; } O05Wd;
extern O05Lobby *D_800E54A4;
extern O05Rec D_80102B00[];
O05WdA *func_0040ECB0(void *p, s32 id);
void func_0040E9D0(void *w, s32 a);
void *func_0041B87C(void *p, s32 idx);

void func_00433DA8(s32 k) {
    s32 i;
    s32 id;
    O05WdA *w;
    O05Wd *o;
    for (i = 0; i < 4; i++) {
        switch (i) {
        case 0:
            id = 0x28B;
            break;
        case 1:
            id = 0x28D;
            break;
        case 2:
            id = 0x28F;
            break;
        default:
            id = 0x291;
            break;
        }
        w = func_0040ECB0(D_800E54A4->h.f0, id);
        func_0040E9D0(w, 0);
        o = w->f8;
        if (k != -1 && w == func_0041B87C(D_800E54A4->h.f4, k)) {
            o->f38 = &D_800E54A4->plr[k].rec[D_800E54A4->plr[k].fAEC];
        } else if (D_80102B00[i].bD >= 0) {
            o->f38 = &D_80102B00[i];
        } else {
            o->f38 = 0;
        }
    }
}
