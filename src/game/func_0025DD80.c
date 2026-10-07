#include "b13_types.h"
#include "libaudio.h"

extern f32 D_800C9124;
extern f32 D_800C9128;

void alCSeqNew(void *seq, s32 data);
void alCSPSetSeq(void *csp, void *seq);
void alCSPSetBank(void *csp, s32 bank);
void alCSPSetChlFXMix(void *csp, u8 chan, u8 fx);
void alCSPSetVol(void *csp, s16 vol);

void func_0025DD80(SndSeq *s) {
    s32 i = 0;
    f32 f;
    alCSeqNew(s->unk10, s->unkC);
    alCSPSetSeq(s->csp, s->unk10);
    alCSPSetBank(s->csp, s->unk8[1]);
    for (i = 0; i < 0x14; i++) {
        alCSPSetChlFXMix(s->csp, i, 0);
    }
    f = (f32)s->unk24 * (s->owner->unk2BA4 * D_800C9124);
    alCSPSetVol(s->csp, f * D_800C9128);
    s->vol = f;
}
