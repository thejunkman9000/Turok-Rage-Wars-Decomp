#include "b13_types.h"

extern f32 D_800C90FC;
extern f32 D_800C9100;
extern f32 D_800C9104;

void func_0025DAEC(SndSeq *s) {
    f32 f;
    s->unk1C = 2;
    s->unk18 = 0x20;
    s->unk20 = (s32)(s->vol * D_800C90FC);
    f = s->unk30;
    if (!(D_800C9100 <= f)) {
        f = D_800C9100;
    }
    s->unk30 = f;
    s->unk28 = 0;
    s->unk34 = (f32)s->unk20 / (f * D_800C9104);
}
