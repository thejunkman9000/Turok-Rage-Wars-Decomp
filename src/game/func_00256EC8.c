#include "b12_types.h"
#include "libaudio.h"

typedef struct B12AiCtx {
    /* 0x00 */ void *buf;
    /* 0x04 */ s16 frames;
    /* 0x06 */ u8 pad6[2];
    /* 0x08 */ u8 msg[0x40];
    /* 0x48 */ s32 cmdList;
    /* 0x4C */ s32 cmdLen;
} B12AiCtx;

extern s32 D_800D0948;
extern s32 D_8010BE20[];
extern OSMesgQueue D_8010BE80;
extern u16 D_8010BE9A;
extern u8 D_801469E8[];
void func_00256FE0(void);
void func_0025E4AC(void);
void func_0025E4D0(void);
void func_0025E25C(void);
void func_0028FD2C(void *a, void *b);
s32 alAudioFrame(s32 cmdList, s32 *cmdLen, u32 outBuf, s32 outLen);

s32 func_00256EC8(B12AiCtx *t) {
    s32 len;
    OSMesg m;
    u32 phys;
    s32 end;
    func_00256FE0();
    phys = osVirtualToPhysical(t->buf);
    t->frames = D_8010BE9A;
    func_0025E4AC();
    end = alAudioFrame(D_8010BE20[D_800D0948], &len, phys, t->frames);
    func_0025E4D0();
    if (len == 0) {
        return 0;
    }
    t->cmdList = D_8010BE20[D_800D0948];
    t->cmdLen = ((end - D_8010BE20[D_800D0948]) >> 3) * 8;
    osWritebackDCacheAll();
    func_0028FD2C(D_801469E8, t->msg);
    D_800D0948 ^= 1;
    func_0025E25C();
    osRecvMesg(&D_8010BE80, &m, 1);
    osAiSetNextBuffer(t->buf, t->frames * 4);
    return 1;
}
