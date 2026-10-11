#include "b21_types.h"

typedef struct B21Hook {
    void (*fn)(B21Game *);
    s32 b;
    s32 c;
} B21Hook;

extern s32 D_80146D68;
extern B21Hook D_800D29D8[];
extern s32 D_800E28D8;
extern OSViMode D_800D8560;
extern OSViMode D_800D87E0;
extern f32 D_auto_800C5410;
void osViSetMode(OSViMode *mode);
void func_00245690(void);
void func_0025E234(s32 a);
void func_00264874(s32 a);

void func_auto_0029499C(B21Game *g) {
    if (g->unk26DD0 != 0) {
        OSViMode *m = &D_800D87E0;
        if (D_800E28D8 == 0) {
            m = &D_800D8560;
        }
        osViSetMode(m);
        osViSetYScale(D_auto_800C5410);
        osViSetSpecialFeatures(2);
    }
    if (D_80146D68 == 2 && g->unk26DD0 == 0) {
        s32 v = g->unk26DBC;
        g->unk26DB0 = 0;
        g->unk26DB8 = v;
        func_00245690();
        func_0025E234(-1);
        func_00264874(0);
        if (D_800D29D8[g->unk26DB8].fn != NULL) {
            D_800D29D8[g->unk26DB8].fn(g);
        }
    }
}
