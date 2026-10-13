#include "o05_types.h"

typedef struct { u8 pad[8]; void *f8; } O05WdA;
typedef struct { u8 pad[0x38]; void *f38; } O05Wd;
extern O05Lobby *D_800E54A4;
O05WdA *func_0040ECB0(void *p, s32 id);
void func_0040E9D0(void *w, s32 a);
void *func_0041B87C(void *p, s32 idx);
s32 func_00264634(s32 i);

void func_auto_00433D38(s32 k) {
    s32 i;
    s32 id;
    O05WdA *w;
    O05Wd *o;
    for (i = 0; i < 4; i++) {
        switch (i) {
        case 0:
            id = 0x296;
            break;
        case 1:
            id = 0x298;
            break;
        case 2:
            id = 0x29A;
            break;
        default:
            id = 0x29C;
            break;
        }
        w = func_0040ECB0(D_800E54A4->h.f0, id);
        if (func_00264634(i) == 1) {
            func_0040E9D0(w, 0);
        } else {
            func_0040E9D0(w, 1);
        }
        o = w->f8;
        if (k != -1 && w == func_0041B87C(D_800E54A4->h.f4, k)) {
            o->f38 = &D_800E54A4->plr[k].rec[D_800E54A4->plr[k].fAEC];
        } else {
            o->f38 = 0;
        }
    }
}
