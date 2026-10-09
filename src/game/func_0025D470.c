#include "b13_types.h"
#include "libaudio.h"

extern f32 D_800C90C0;
extern f32 D_800C90C4;
extern f32 D_800C90C8;
extern f32 D_800C90CC;
extern f32 D_800C90D0;
extern f32 D_800C90D4;
extern f32 D_800C90D8;
extern f32 D_800C90DC;
extern f32 D_800C90E0;
extern f32 D_800C90E4;
extern s32 D_800D0D90;
extern s32 D_800D0D94;

void alCSeqNew(void *seq, s32 data);
void alCSPSetSeq(void *csp, void *seq);
void alCSPSetBank(void *csp, s32 bank);
void alCSPSetChlFXMix(void *csp, u8 chan, u8 fx);
void alCSPSetVol(void *csp, s16 vol);
void alCSPPlay(void *csp);
s32 alCSPGetState(void *csp, s32 x);
f32 Trunc16ToF32(u16 v);
s32 func_00265508(void *tab, s32 n, s32 key);

typedef struct SndNodeRec { s32 w0; u16 h4; } SndNodeRec;
SndNodeRec *func_0028FD94(void *node, s32 idx);

static inline s32 SeqLoad_(SndSeq *s, s32 key) {
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
            s->unk30 = D_800C90C0;
        }
        res = (s32)r;
    } else {
        res = 0;
    }
    s->unkC = res;
    return res != 0;
}

static inline void SeqStart_(SndSeq *s) {
    s32 i = 0;
    f32 f;
    alCSeqNew(s->unk10, s->unkC);
    alCSPSetSeq(s->csp, s->unk10);
    alCSPSetBank(s->csp, s->unk8[1]);
    for (i = 0; i < 0x14; i++) {
        alCSPSetChlFXMix(s->csp, i, 0);
    }
    f = (f32)s->unk24 * (s->owner->unk2BA4 * D_800C90C4);
    alCSPSetVol(s->csp, f * D_800C90C8);
    s->vol = f;
}

void func_0025D470(SndSeq *s) {
    f32 vol;
    f32 t;
    s32 c40 = 0x40;
    switch (s->unk18) {
    case 0x20:
        if (s->unk1C & 4) {
            s->unk1C = 0;
            D_800D0D90 = -1;
            if (s->unk28 >= 0) {
                s->unk18 = 0x40;
                return;
            }
            s->unk18 = 0x10;
            return;
        }
        return;
    case 0x100:
        if (s->unk1C & 8) {
            s->unk18 = 0x80;
            s->unk1C = 0;
            return;
        }
        D_800D0D94 = D_800D0D94 + 1;
        if (D_800D0D94 >= 10) {
            D_800D0D90 = -1;
            s->unk18 = 0x40;
            return;
        }
        break;
    case 0x40:
        if (s->unk28 != -1) {
            if (!SeqLoad_(s, s->unk28)) {
                s->unk18 = 0x100;
                D_800D0D94 = 0;
                s->unk1C = 0;
                return;
            }
            s->unk18 = 0x80;
            s->unk4 = 1;
    case 0x80:
            SeqStart_(s);
            alCSPPlay(s->csp);
            s->unk1C = 0;
            s->unk18 = 0x10;
            D_800D0D90 = s->unk28;
            return;
        }
        s->unk18 = 0x10;
        break;
    case 0x10:
    default:
        if (D_800D0D90 > 0 && alCSPGetState(s->csp, c40) == 0) {
            D_800D0D90 = 0;
            s->unk28 = 0;
        } else {
            if (s->unk38 != 0) {
                vol = (f32)s->unk24;
                vol = vol * (s->owner->unk2BA4 * D_800C90CC);
                vol = vol * s->unk3C;
                goto setvol;
            }
            vol = (f32)s->unk24 * (s->owner->unk2BA4 * D_800C90D0);
            if (s->owner->unk2BB8 != 0) {
                vol *= D_800C90D4;
            }
            if (vol != s->vol) {
setvol:
                alCSPSetVol(s->csp, vol * D_800C90D8);
                s->vol = vol;
            }
        }
        if (s->unk28 != D_800D0D90) {
            if (D_800D0D90 > 0) {
                t = s->unk30;
                s->unk1C = 2;
                s->unk18 = 0x20;
                s->unk20 = s->vol * D_800C90DC;
                if (!(D_800C90E0 <= t)) {
                    t = D_800C90E0;
                }
                s->unk30 = t;
                s->unk34 = (f32)s->unk20 / (t * D_800C90E4);
                return;
            }
            s->unk1C = 0;
            s->unk18 = 0x40;
        }
        break;
    }
}
