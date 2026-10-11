#include "common.h"

typedef struct Qn Qn;
struct Qn { Qn *next; OSMesgQueue *q; };
typedef struct {
    u8 pad0[0x20];
    OSMesg msg20;
    u8 pad24[0x1C];
    OSMesgQueue q40;
    u8 pad58[0x2E0 - 0x58];
    Qn *unk2E0;
} Vid;

void osViBlack(u8 black);
void func_0028EAAC(Vid *o);
void func_0028ED80(Vid *o);
void func_0028F258(Vid *o);
void func_0028FBF0(Vid *o);
void func_0025E338(void);
void func_0025E234(s32 a);
s32 func_0025CC8C(void);
void func_0025CC0C(s32 a);
void func_0040C398(void);
extern s32 D_800D2958;
extern s32 D_800D295C;

void func_auto_0028E880(Vid *o) {
    s32 msg;
    Qn *n;
    while (1) {
        osRecvMesg(&o->q40, (OSMesg *)&msg, 1);
        switch (msg) {
        case 0x29A:
            if (D_800D2958 != 0) {
                D_800D295C = D_800D295C - 1;
                if (D_800D295C <= 0) {
                    osViBlack(1);
                    while (1) {
                    }
                }
            }
            func_0028EAAC(o);
            func_0040C398();
            break;
        case 0x29B:
            func_0028ED80(o);
            break;
        case 0x29C:
            func_0028F258(o);
            break;
        case 0x29D:
            func_0025E338();
            func_0025E234(-1);
            func_0025CC0C(func_0025CC8C());
            n = o->unk2E0;
            D_800D2958 = 1;
            D_800D295C = 0x14;
            while (n != 0) {
                osSendMesg(n->q, (OSMesg)&o->msg20, 0);
                n = n->next;
            }
            break;
        case 6:
            func_0028FBF0(o);
            break;
        }
    }
}
