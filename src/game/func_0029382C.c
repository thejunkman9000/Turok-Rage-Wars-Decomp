#include "b21_types.h"

typedef struct B21StateEnt {
    void (*fn)(B21Game *g);
    s32 unk4;
    s32 unk8;
} B21StateEnt;

extern s32 D_800D2974;
extern B21StateEnt D_800D29DC[];
extern s32 D_80146D68;
extern s32 D_800D2984;
void func_00264CD8();
void func_00292910(B21Game *g);

void func_0029382C(B21Game *g) {
    s32 st;
    if (D_800D2974 != 0) {
        D_800D2974 = 0;
    }
    func_00264CD8();
    st = g->unk26DB8;
    if (D_800D29DC[st].fn != NULL) {
        D_800D29DC[st].fn(g);
        st = g->unk26DB8;
    }
    if (st != 20) {
        if (D_80146D68 != 0) {
            D_80146D68--;
            func_00292910(g);
        }
    }
    D_800D2984++;
}
