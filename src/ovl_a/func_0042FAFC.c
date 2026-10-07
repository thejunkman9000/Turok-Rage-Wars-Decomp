#include "o05_types.h"
typedef struct { u8 pad[0x14]; u16 h14; } O05Wh;
typedef struct { void *f0; u8 pad4[0x20]; void *f24; void *f28; } O05X;
extern O05Lobby *D_800E54A4;
extern s32 D_800E28E0;
void func_0025DF54(s32 a);
void func_0040E958(void *w, s32 a);
void func_00419FD8(void *w, s32 a);
void func_0029A73C(void);
void func_00299368(s32 a);
void func_002A3358(void);
s32 func_00419FB8(void *w);
void func_00419FA4(void *w);
s32 func_00433574(s32 a);

s32 func_0042FAFC(s32 a, s32 b, s32 ev) {
    if (D_800E28E0 >= 2) {
        return 0;
    }
    switch (D_800E54A4->h.f4C) {
    case 1:
        ((O05Wh *)D_800E54A4->h.f3C)->h14 += D_800E54A4->h.h42;
        ((O05Wh *)D_800E54A4->h.f44)->h14 -= D_800E54A4->h.h4A;
        D_800E54A4->h.f50--;
        if (D_800E54A4->h.f50 <= 0) {
            func_0025DF54(0xE79);
            func_0040E958(D_800E54A4->h.f28, 1);
            func_00419FD8(D_800E54A4->h.f24, 4);
            D_800E54A4->h.f4C = 4;
            D_800E54A4->h.f50 = 4;
        }
        break;
    case 2:
        ((O05Wh *)D_800E54A4->h.f3C)->h14 -= D_800E54A4->h.h42;
        ((O05Wh *)D_800E54A4->h.f44)->h14 += D_800E54A4->h.h4A;
        D_800E54A4->h.f50--;
        if (D_800E54A4->h.f50 <= 0) {
            D_800E54A4->h.f4C = 3;
            func_0029A73C();
            func_00299368(D_800E54A4->f3470);
            return 0;
        }
        break;
    case 3:
        func_002A3358();
        break;
    case 4:
        {
            O05Hdr *p = &D_800E54A4->h;
            s32 y = p->f50;
            s32 x = y - 1;
            s32 t = x >= 0 ? y - (y >= x) : 0;
            p->f50 = t;
        }
        if (D_800E54A4->h.f50 <= 0) {
            if (func_00419FB8(D_800E54A4->h.f24) != 0) {
                func_00419FA4(D_800E54A4->h.f24);
                D_800E54A4->h.f4C = 3;
            }
        }
        break;
    case 5:
        func_0025DF54(0xE78);
        D_800E54A4->h.f4C = 2;
        D_800E54A4->h.f50 = 4;
        func_0040E958(D_800E54A4->h.f28, 0);
        break;
    }
    if (D_800E54A4->h.f4C == 3) {
        func_00433574(ev);
    }
    return 0;
}
