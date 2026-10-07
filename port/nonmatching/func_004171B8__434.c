#include "q02_types.h"
#include "common.h"
typedef struct O3Dl { u32 w0; u32 w1; } O3Dl;
extern O3Dl *D_80110634;
#define O3_PUSH(a, b) { O3Dl *_g = D_80110634++; _g->w0 = (a); _g->w1 = (b); }
extern volatile s32 D_800E32E4;
typedef struct { s32 f[5]; } O02Fl;
extern s32 D_800E32CC;
extern s32 D_800E32A0;
extern O02Fl D_80153F60;
void func_0041900C(void);
static inline void SyncNC(void) {
    D_800E32E4 = 1;
    O3_PUSH(0xE7000000, 0);
}
void func_004171B8(u32 m) {
    O02Fl fl;
    u32 hi, lo; s32 sel;
    fl.f[0] = (m & 0x5) == 0x5;
    fl.f[1] = (m & 0x30) == 0x30;
    fl.f[2] = (m & 0x300) == 0x300;
    fl.f[3] = (m & 0x3000) == 0x3000;
    fl.f[4] = (m & 0x30000) == 0x30000;
    func_0041900C();
    D_800E32E4 = 0;
    SyncNC();
    if (fl.f[1]) {
        D_800E32CC = 0xC;
    } else {
        D_800E32CC = 0xB;
    }
    O3_PUSH(0xE3000A01, 0);
    O3_PUSH(0xD9D0F9FA, 0);
    O3_PUSH(0xD9FFFFFF, 0x200404);
    if (fl.f[4]) {
        O3_PUSH(0xD9FFFFFF, 1);
    }
    lo = 0;
    hi = 0;
    sel = lo < fl.f[3];
    if (fl.f[4]) sel += 2;
    switch (sel) {
    case 0:
        lo = 0x0C084000;
        hi = 0x03024000;
        break;
    case 1:
        lo = 0x404240;
        hi = 0x104240;
        break;
    case 2:
        lo = 0x442230;
        hi = 0x112230;
        break;
    case 3:
        lo = 0x404A50;
        hi = 0x104A50;
        break;
    }
    D_800E32A0 = 1;
    O3_PUSH(0xE200001C, lo | hi);
    D_80153F60 = fl;
}
