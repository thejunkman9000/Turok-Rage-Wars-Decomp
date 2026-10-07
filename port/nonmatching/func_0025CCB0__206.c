#include "b13_types.h"

typedef struct M04Fx {
    /* 0x00 */ SndMgr *owner;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ s32 state;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ s32 idx;
    /* 0x14 */ s32 vol;
    /* 0x18 */ u8 pad18[3];
    /* 0x1B */ u8 pan;
    /* 0x1C */ u8 pad1C[2];
    /* 0x1E */ s16 snd;
    /* 0x20 */ f32 f20;
    /* 0x24 */ f32 f24;
} M04Fx;

typedef struct M04Hdr {
    u32 a;
    u16 b;
} M04Hdr;

typedef struct M04Strm {
    s32 unk0;
    s32 unk4;
} M04Strm;

extern f64 D_800C9090;
extern f32 D_800C9098;
extern f32 D_800C909C;
extern f32 D_800C90A0;
extern M04Strm *D_800D0D78;
extern s32 D_8010C064[];
void adecClearStopFlag();
void adecGetStopFlag();
s32 adecStreamOpen(void *p, s32 rate, s32 *out);
s32 alSndpGetState(void *p);
void alSndpPlay(void *p);
void alSndpSetFXMix(void *p, s32 mix);
void alSndpSetPan(void *p, u8 pan);
void alSndpSetPitch(void *p, f32 pitch);
void alSndpSetPriority(void *p, s16 id, s32 pri);
void alSndpSetSound(void *p, s16 id);
void alSndpSetVol(void *p, s16 vol);
void func_00258760(SndMgr *m);
void func_002587C4(SndMgr *m);
void *func_00258D60(SndMgr *m);
void *func_0028FD94(void *n, s32 i);

void func_0025CCB0(M04Fx *f) {
    void *pl;
    s32 rate;
    s32 off;
    s32 a1;
    f32 fx;
    M04Hdr *h;
    void *h2;
    s32 *d;
    func_00258760(f->owner);
    pl = func_00258D60(f->owner);
    switch (f->state) {
    case 0:
        break;
    case 3:
        adecGetStopFlag();
        break;
    case 2:
        alSndpSetSound(pl, f->snd);
        if (alSndpGetState(pl) == 0) {
            adecClearStopFlag();
            if (f->unkC >= 0) {
                f->state = 1;
            } else {
                f->state = 0;
            }
        }
        break;
    case 1:
        d = D_8010C064;
        d[0] = 0;
        *(u8 *)&d[1] = 2;
        d[2] = 0;
        off = f->idx * 2;
        h = (M04Hdr *)func_0028FD94(f->owner->node2B50, off);
        f->f20 = (f32)h->a * D_800C9098;
        f->f24 = (f32)h->b;
        h2 = func_0028FD94(f->owner->node2B50, off | 1);
        d[-1] = (s32)h2;
        D_800D0D78->unk4 = adecStreamOpen(h2, 0x5622, &rate);
        f->state = 3;
        alSndpSetSound(pl, f->snd);
        alSndpSetPitch(pl, (f32)rate * D_800C909C);
        alSndpSetVol(pl, (s16)(s32)((f32)f->vol * f->f20));
        alSndpSetPan(pl, f->pan);
        alSndpSetPriority(pl, f->snd, 0x7F);
        fx = f->f24;
        if (D_800C90A0 <= fx) {
            a1 = (s32)(fx - D_800C90A0) | 0x80000000;
        } else {
            a1 = (s32)fx;
        }
        alSndpSetFXMix(pl, a1 & 0xFF);
        alSndpPlay(pl);
        f->unkC = -1;
        break;
    }
    func_002587C4(f->owner);
}

