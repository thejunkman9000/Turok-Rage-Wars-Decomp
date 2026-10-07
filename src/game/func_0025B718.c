#include "b13_types.h"

extern f32 D_800C9068;

void func_0025B718(SndVoice *v, SndMgr *m, s32 idx) {
    v->unkC = -1;
    v->unk8 = -1;
    v->unk3A = -1;
    v->unk40 = -1;
    v->unkB4 = (SndMgr *)-1;
    v->mgr = m;
    v->idx = idx;
    v->unk38 = 0;
    v->unk14 = 0;
    v->unk58 = 0;
    v->unk5C = 0;
    v->unkA4 = 0;
    v->unkAC = 0;
    v->unkBC = 0;
    v->unkC0 = 0;
    v->unkC4 = 1;
    v->unk2C = D_800C9068;
    v->unk34 = D_800C9068;
    v->unkB8 = D_800C9068;
}
