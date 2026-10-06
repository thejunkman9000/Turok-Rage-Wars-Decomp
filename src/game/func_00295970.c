#include "common.h"

typedef struct B21Cnt {
    s32 unk0;
    s32 unk4;
} B21Cnt;

extern s32 D_800D2AF0;
extern B21Cnt D_8014AEC0;

void func_00295970(void) {
    if (D_800D2AF0++ >= 3) {
        s32 t = D_8014AEC0.unk0;
        D_8014AEC0.unk4 = 1;
        D_800D2AF0 = 0;
        D_8014AEC0.unk0 = t + 1;
    }
}
