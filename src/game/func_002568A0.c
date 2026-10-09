#include "b12_types.h"
#include "libaudio.h"

typedef struct B12AiCfg {
    u32 unk0;
    u32 unk4;
    s32 unk8;
} B12AiCfg;

typedef struct B12AiTask {
    /* 0x00 */ s32 *cmd;
    /* 0x04 */ u8 pad4[0x14];
    /* 0x18 */ s32 f18;
    /* 0x1C */ s32 f1C;
    /* 0x20 */ u8 *f20;
    /* 0x24 */ s32 f24;
    /* 0x28 */ u8 *f28;
    /* 0x2C */ s32 f2C;
    /* 0x30 */ u8 *f30;
    /* 0x34 */ s32 f34;
    /* 0x38 */ s32 f38;
    /* 0x3C */ s32 f3C;
    /* 0x40 */ s32 f40;
    /* 0x44 */ s32 f44;
    /* 0x48 */ u8 pad48[8];
    /* 0x50 */ s32 f50;
    /* 0x54 */ s32 f54;
    /* 0x58 */ OSMesgQueue *f58;
    /* 0x5C */ struct B12AiTask *f5C;
    /* 0x60 */ u8 pad60[0x10];
} B12AiTask;

typedef struct B12DbEnt2 {
    ALLink link;
    s32 f8;
    s32 fC;
    void *data;
} B12DbEnt2;

extern s8 D_8010BDF0[];
extern s32 D_8010BE98;
extern s32 D_8010BE9C;
extern s32 D_8010BEA0;
extern s32 D_8010BDFC;
extern B12DbEnt2 D_8010B928[];
extern void *D_8010BE20[];
extern B12AiTask *D_8010BE28[];
extern u8 D_8010BE34[];
extern OSMesgQueue D_8010BE80;
extern OSMesgQueue D_8010BE00;
extern OSMesgQueue D_8010BDD8;
extern OSMesg D_8010B6D0[];
extern OSMesg D_8010B6A8[];
extern OSMesg D_8010BEA8[];
extern OSThread D_8010B6F8;
extern u8 D_800E9400[];
extern u8 D_800DCC40[];
extern u8 D_800DCD10[];
extern u8 D_800DF230[];
extern u8 D_800E0860[];
void func_00256E8C(void);
void func_00256CB0(void *arg);
void alInit(void *g, ALSynConfig *c);
void *alHeapDBAlloc(u8 *file, s32 line, void *hp, s32 num, s32 size);

void func_002568A0(ALSynConfig *cfg, s32 pri, B12AiCfg *c2) {
    s32 freq;
    u32 n;
    f32 t;
    u32 i;
    B12AiTask **tp;
    B12AiTask *tk;
    u8 *a20;
    s32 a24;
    s32 n4;
    D_8010BDF0[0] = 0;
    cfg->dmaproc = (void *)func_00256E8C;
    freq = osAiSetFrequency(c2->unk0);
    cfg->outputRate = freq;
    t = (f32)c2->unk4 * (f32)freq * 0.016666668f;
    n = (s32)t;
    D_8010BE98 = n;
    if ((f32)n < t) {
        D_8010BE98 = n + 1;
    }
    if (D_8010BE98 & 0xF) {
        D_8010BE98 = (D_8010BE98 & ~0xF) + 0x10;
    }
    alInit(D_8010BE34, cfg);
    D_8010B928[0].link.prev = 0;
    D_8010B928[0].link.next = 0;
    for (i = 0; i < 0x3B; i++) {
        ALLink *next = &D_8010B928[i + 1].link;
        ALLink *prev = &D_8010B928[i].link;
        alLink(next, prev);
        D_8010B928[i].data = alHeapDBAlloc(0, 0, cfg->heap, 1, 0x300);
    }
    D_8010B928[i].data = alHeapDBAlloc(0, 0, cfg->heap, 1, 0x300);
    for (i = 0; i < 2; i++) {
        D_8010BE20[i] = alHeapDBAlloc(0, 0, cfg->heap, 1, c2->unk8 * 8);
    }
    D_8010BE9C = c2->unk8;
    i = 0;
    a20 = D_800DCC40;
    a24 = D_800DCD10 - D_800DCC40;
    tp = D_8010BE28;
    for (; i < 3; i++) {
        tk = alHeapDBAlloc(0, 0, cfg->heap, 1, 0x70);
        n4 = D_8010BE98 * 4;
        *tp = tk;
        (*tp)->cmd = alHeapDBAlloc(0, 0, cfg->heap, 1, n4);
        (*tp)->f58 = &D_8010BE80;
        (*tp)->f5C = *tp;
        (*tp)->f18 = 2;
        (*tp)->f20 = a20;
        (*tp)->f24 = a24;
        (*tp)->f1C = 0;
        (*tp)->f28 = D_800DF230;
        (*tp)->f2C = 0x1000;
        (*tp)->f30 = D_800E0860;
        (*tp)->f34 = 0x800;
        (*tp)->f50 = 0;
        (*tp)->f54 = 0;
        (*tp)->f38 = 0;
        (*tp)->f3C = 0;
        (*tp)->f40 = 0;
        (*tp)->f44 = 0;
        tp++;
    }
    osCreateMesgQueue(&D_8010BE80, D_8010B6D0, 10);
    osCreateMesgQueue(&D_8010BE00, D_8010B6A8, 10);
    osCreateMesgQueue(&D_8010BDD8, D_8010BEA8, 0x3C);
    osSetEventMesg(6, &D_8010BE00, (OSMesg)7);
    D_8010BDFC = 0;
    D_8010BEA0 = (s32)cfg->heap;
    memset(D_800E9400, 8, 0x2800);
    osCreateThread(&D_8010B6F8, 8, func_00256CB0, 0, D_800E9400 + 0x2800, pri);
    osStartThread(&D_8010B6F8);
    osSendMesg(&D_8010BE00, (OSMesg)7, 0);
}