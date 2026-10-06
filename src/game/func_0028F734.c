#include "common.h"

typedef struct {
    s16 unk0;
    u8 pad2[0x1E];
    s16 unk20;
    u8 pad22[0x1E];
    OSMesgQueue q40;
    OSMesg buf58[8];
    OSMesgQueue q78;
    OSMesg buf90[8];
    OSThread thread;
    u8 padThr[0x2E0 - 0xB0 - sizeof(OSThread)];
    s32 unk2E0;
    s32 unk2E4;
    s32 unk2E8;
    s32 unk2EC;
    s32 unk2F0;
    s32 unk2F4;
    s32 unk2F8;
    s32 unk2FC;
    s32 unk300;
} Vid;

void func_0028E910(void *arg);

void func_0028F734(Vid *o, void *sp, OSPri pri, s32 unused, u8 retrace) {
    o->unk0 = 1;
    o->unk2F4 = 0;
    o->unk2F8 = 0;
    o->unk2E0 = 0;
    o->unk2FC = 0;
    o->unk2E4 = 0;
    o->unk2E8 = 0;
    o->unk2EC = 0;
    o->unk2F0 = 0;
    o->unk300 = 0;
    o->unk20 = 4;
    osCreateMesgQueue(&o->q40, o->buf58, 8);
    osCreateMesgQueue(&o->q78, o->buf90, 8);
    osSetEventMesg(4, &o->q40, (OSMesg)0x29B);
    osSetEventMesg(9, &o->q40, (OSMesg)0x29C);
    osSetEventMesg(14, &o->q40, (OSMesg)0x29D);
    osViSetEvent(&o->q40, (OSMesg)0x29A, retrace);
    osCreateThread(&o->thread, 7, func_0028E910, o, sp, pri);
    osStartThread(&o->thread);
}
