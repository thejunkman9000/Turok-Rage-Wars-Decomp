#include "b13_types.h"

extern f32 D_800C90F0;
extern f32 D_800C90F4;

void alCSPSetVol(void *csp, s16 vol);
void alCSPStop(void *csp);

void func_0025D948(SndSeq *s) {
    f32 cur;
    f32 tgt;
    f32 n;
    if (s->unk1C & 2) {
        alCSPSetVol(s->csp, ((s16 *)&s->unk20)[1]);
        s->unk20 = (s32)((f32)s->unk20 - s->unk34);
        if (s->unk20 <= 0) {
            s->unk20 = 0;
            alCSPStop(s->csp);
            s->unk1C |= 4;
        }
    } else if (s->unk38 != 0) {
        cur = s->unk3C;
        tgt = s->unk40.f;
        if (tgt < cur) {
            n = cur - D_800C90F0;
            if (!(tgt <= n)) {
                n = tgt;
            }
            s->unk3C = n;
        } else if (cur < tgt) {
            n = cur + D_800C90F4;
            if (!(n <= tgt)) {
                n = tgt;
            }
            s->unk3C = n;
        }
    }
}
