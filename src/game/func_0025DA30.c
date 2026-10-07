#include "b13_types.h"

extern f32 D_800C90F8;

typedef struct SndNodeRec { s32 w0; u16 h4; } SndNodeRec;

s32 func_00265508(void *tab, s32 n, s32 key);
SndNodeRec *func_0028FD94(void *node, s32 idx);
f32 Trunc16ToF32(u16 v);

s32 func_0025DA30(SndSeq *s, s32 key) {
    s32 i;
    SndNodeRec *r;
    SndNodeRec *n;
    s32 res;
    i = func_00265508(s->owner->unk2B60, s->owner->unk2B64, key);
    if (i != -1) {
        i <<= 1;
        r = func_0028FD94(s->owner->node2B50, i | 1);
        n = func_0028FD94(s->owner->node2B50, i);
        s->unk24 = n->w0;
        s->unk30 = Trunc16ToF32(n->h4);
        if (s->unk30 <= 0.0f) {
            s->unk30 = D_800C90F8;
        }
        res = (s32)r;
    } else {
        res = 0;
    }
    s->unkC = res;
    return res != 0;
}
