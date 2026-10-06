#include "common.h"

typedef struct {
    u8 pad0[8];
    u32 flags8;
    u8 padC[4];
    s32 unk10;
} Msg;
typedef struct {
    u8 pad0[0x78];
    OSMesgQueue q78;
    u8 pad90[0x2F4 - 0x90 - sizeof(OSMesgQueue) + 0x18];
    s32 unk2F4;
    s32 unk2F8;
    s32 unk2FC;
    s32 unk300;
} Vid;

void func_0028F934(Vid *o, Msg *m);
void func_0028FBB8(Vid *o);
s32 func_0028F524(Vid *o, s32 *a, s32 *b, s32 c);
void func_0028FA40(Vid *o, s32 a, s32 b);
extern s32 D_800D2954;
extern s32 D_800D2B28;
extern OSThread D_8010A248;

void func_0028FBF0(Vid *o) {
    Msg *m;
    s32 a;
    s32 b;
    s32 mode;
    m = 0;
    a = 0;
    b = 0;
    while (osRecvMesg(&o->q78, (OSMesg *)&m, 0) != -1) {
        if (m->unk10 == 1 && (m->flags8 & 0x20) && D_800D2954 == 0) {
            D_800D2954 = 2;
            osSetThreadPri(&D_8010A248, D_800D2B28);
        }
        func_0028F934(o, m);
    }
    if (o->unk300 != 0 && o->unk2F4 != 0) {
        func_0028FBB8(o);
    } else {
        mode = (o->unk2F4 == 0) << 1 | (o->unk2F8 == 0);
        if (func_0028F524(o, &a, &b, mode) != mode) {
            func_0028FA40(o, a, b);
        }
    }
}
