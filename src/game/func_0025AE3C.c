#include "b13_types.h"

typedef struct SCore { u8 pad0[8]; void *player; u8 pad[0x54]; s16 snd[16]; } SCore;
extern f32 D_800C9058;
extern u8 D_80145088[];
void alSndpSetSound(void *p, s16 id);
s32 alSndpGetState(void *p);
void alSndpStop(void *p);
void alSndpPlay(void *p);
void alSndpDeallocate(void *p, s16 id);
s32 func_00239594(void *p, void *pos);
void func_0025A3EC(SndVoice *o);
void func_0025A864(SndVoice *o);
void func_0025ABB4(SndVoice *o);

void func_0025AE3C(SndVoice *o) {
    SndMgr *m;
    SCore *core;
    s32 st;
    s32 n;
    s32 *p;
    o->mgr->unk2B98 = func_00239594(D_80145088, &o->pos);
    {
    register SndMgr *m0 __asm__("$16");
    m0 = o->mgr;
    alSndpSetSound(m0->player, m0->snd[o->idx]);
    st = alSndpGetState(m0->player);
    }
    if (o->unk2C <= D_800C9058 || ((o->unkA4 & 4) && o->unk18 == 0)) {
        o->unkAC = 1;
    }
    if (o->unkBC != 0 && o->mgr->unk134 != o->tag) {
        o->unkAC = 1;
    }
    if (st != 0) {
        if (o->unkAC != 0) {
            m = o->mgr;
            o->unkAC = 1;
            o->unk50 = 0;
            if (o->unk10 != m->unk104) {
                alSndpSetSound(m->player, m->snd[o->idx]);
                if (alSndpGetState(m->player) != 0) {
                    alSndpStop(m->player);
                }
                o->unk4 = -1;
            }
        } else {
            goto blk;
        }
    } else {
        n = o->unkA0;
        if (n > 0) {
            o->unkA0 = n - 1;
            o->unkA4 |= 0x10;
            return;
        }
blk:
        if ((o->unkA4 & 0x18) == 0x10) {
            alSndpPlay(o->mgr->player);
            return;
        }
        if (st == 0) {
            m = o->mgr;
            core = (SCore *)((u8 *)m + 0x7C);
            alSndpDeallocate(m->player, core->snd[o->idx]);
            core->snd[o->idx] = -1;
            o->unk38 = 0;
            o->unkC = -1;
            o->unk8 = -1;
            o->tag = -1;
            o->unk3A = -1;
            o->unkB4 = (SndMgr *)-1;
            return;
        }
        p = (s32 *)o->unk50;
        if (p != 0) {
            o->pos = *(Vec3f *)p;
        }
        func_0025A3EC(o);
        func_0025A864(o);
        func_0025ABB4(o);
    }
}