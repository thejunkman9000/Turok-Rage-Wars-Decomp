#include "b13_types.h"
#include "libaudio.h"

extern f32 D_800C9114;
extern f32 D_800C9118;
extern f32 D_800C911C;
extern f32 D_800C9120;

void alCSPSetVol(void *csp, s16 vol);

void func_0025DCA8(SndSeq *s) {
    f32 f;
    if (s->unk38 != 0) {
        f = (f32)s->unk24;
        f *= s->owner->unk2BA4 * D_800C9114;
        f *= s->unk3C;
    } else {
        f = (f32)s->unk24 * (s->owner->unk2BA4 * D_800C9118);
        if (s->owner->unk2BB8 != 0) {
            f *= D_800C911C;
        }
        if (f == s->vol) {
            return;
        }
    }
    alCSPSetVol(s->csp, f * D_800C9120);
    s->vol = f;
}
