#include "b13_types.h"

extern f32 D_800C906C;
extern f32 D_800C9070;
extern f32 D_800C9074;
extern s16 D_8010BFA0[];

void func_0025B778(SndVoices *p, SndMgr *m) {
    s32 i;
    f32 x;
    f32 y;
    SndVoice *v;
    p->owner = m;
    for (i = 0; i <= 90; i++) {
        x = (f32)i * D_800C906C;
        y = x * x * x * x * x * D_800C9070;
        D_8010BFA0[90 - i] = (s32)y;
    }
    for (i = 0; i < 17; i++) {
        SND_VOICE_AT(v, p, i);
        v->idx = i;
        v->mgr = m;
        v->unkC = -1;
        v->unk8 = -1;
        v->unk3A = -1;
        v->unk38 = 0;
        v->unk40 = -1;
        v->unk14 = 0;
        v->unk2C = D_800C9074;
        v->unk58 = 0;
        v->unk5C = 0;
        v->unk34 = D_800C9074;
        v->unkA4 = 0;
        v->unkAC = 0;
        v->unkB4 = (SndMgr *)-1;
        v->unkB8 = D_800C9074;
        v->unkBC = 0;
        v->unkC0 = 0;
        v->unkC4 = 1;
    }
}
