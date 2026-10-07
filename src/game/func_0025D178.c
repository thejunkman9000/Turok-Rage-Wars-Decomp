#include "b13_types.h"

extern u8 D_800D0D78[];

void *func_00258D60(SndMgr *m);
s16 alSndpAllocate(void *p, void *snd);

void func_0025D178(SndFx *fx, SndMgr *m) {
    fx->owner = m;
    fx->unk4 = -1;
    fx->unkC = -1;
    fx->unk8 = 0;
    fx->unk14 = 0;
    fx->unk18 = 0x40;
    fx->sndId = alSndpAllocate(func_00258D60(fx->owner), D_800D0D78);
}
