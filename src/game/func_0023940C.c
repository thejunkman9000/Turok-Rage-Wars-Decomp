#include "b08_types.h"

typedef struct ModeBlk {
    u8 padFC[0xFC];
    s32 modeFC;
    s32 unk100;
} ModeBlk;

void func_0023940C(ModeBlk *p) {
    p->unk100 = 0;
    p->modeFC = 2;
}
