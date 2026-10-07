#include "b13_types.h"

extern s32 D_800D0D3C;
extern s32 D_800D0D40;

void func_0025AE3C(SndVoice *v);

void func_0025BD20(SndVoices *p) {
    s32 i;
    s32 n = 0;
    SndVoice *v = p->v;
    for (i = 0; i < 16; i++) {
        if (v->unk8 != -1 && p->owner->unk102 != i) {
            func_0025AE3C(v);
            n++;
        }
        v++;
    }
    D_800D0D3C = n;
    if (D_800D0D40 < n) {
        D_800D0D40 = n;
    }
}
