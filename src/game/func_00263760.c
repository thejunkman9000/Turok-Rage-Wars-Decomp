#include "b14_types.h"

typedef struct M04Pad {
    u16 button;
    s8 x;
    s8 y;
    u8 err;
    u8 pad;
} M04Pad;

extern f32 D_800C93E0;
extern B14Ctl D_8010F0E0;
extern B14Ctl D_8010F328[];
extern M04Pad D_8010EEA0[];
extern u8 D_8010FBB8;
extern OSMesgQueue D_8010FC00;
extern OSMesg D_8010FBD8;
extern u8 D_8010FBE0[];
void func_00263D10(B14Ctl *c);
void func_00263E1C(B14Ctl *c, s8 x, s8 y, u16 b);

void func_00263760(void) {
    s32 i;
    switch (D_8010FBB8) {
    case 0:
        osRecvMesg(&D_8010FC00, &D_8010FBD8, 1);
        osContGetReadData((OSContPad *)D_8010EEA0);
        D_8010F0E0.port = -1;
        D_8010F0E0.f0 = 0;
        D_8010F0E0.fC4 = 0;
        D_8010F0E0.fC5 = 0;
        D_8010F0E0.fC6 = 0;
        D_8010F0E0.fC7 = 0;
        D_8010F0E0.fB0 = 0;
        D_8010F0E0.fAC = 0;
        D_8010F0E0.fB4 = 0;
        D_8010F0E0.fB8 = 0;
        D_8010F0E0.fBC = 0;
        D_8010F0E0.fC0 = 0;
        D_8010F0E0.f18 = 0;
        D_8010F0E0.f14 = 0;
        D_8010F0E0.f1C = 0;
        D_8010F0E0.f20 = 0;
        D_8010F0E0.f24 = 0;
        D_8010F0E0.f28 = 0;
        for (i = 0; i < 4; i++) {
            func_00263E1C(&D_8010F328[i], D_8010EEA0[i].x, D_8010EEA0[i].y, D_8010EEA0[i].button);
            D_8010F0E0.f0 |= D_8010F328[i].f0;
            D_8010F0E0.fC4 += D_8010F328[i].fC4;
            D_8010F0E0.fC5 += D_8010F328[i].fC5;
            D_8010F0E0.fC6 += D_8010F328[i].fC6;
            D_8010F0E0.fC7 += D_8010F328[i].fC7;
            D_8010F0E0.fB0 |= D_8010F328[i].fB0;
            D_8010F0E0.fB4 |= D_8010F328[i].fB4;
            D_8010F0E0.fB8 |= D_8010F328[i].fB8;
            D_8010F0E0.fBC |= D_8010F328[i].fBC;
            D_8010F0E0.fC0 |= D_8010F328[i].fC0;
            D_8010F0E0.f18 |= D_8010F328[i].f18;
            D_8010F0E0.f14 |= D_8010F328[i].f14;
            D_8010F0E0.f1C |= D_8010F328[i].f1C;
            D_8010F0E0.f20 |= D_8010F328[i].f20;
            D_8010F0E0.f24 |= D_8010F328[i].f24;
            D_8010F0E0.f28 |= D_8010F328[i].f28;
        }
        D_8010F0E0.fC4 = (s8)((f32)(s8)D_8010F0E0.fC4 * D_800C93E0);
        D_8010F0E0.fC5 = (s8)((f32)(s8)D_8010F0E0.fC5 * D_800C93E0);
        D_8010F0E0.fC6 = (s8)((f32)(s8)D_8010F0E0.fC6 * D_800C93E0);
        D_8010F0E0.fC7 = (s8)((f32)(s8)D_8010F0E0.fC7 * D_800C93E0);
        break;
    case 1:
        osRecvMesg(&D_8010FC00, &D_8010FBD8, 1);
        osContGetQuery((OSContStatus *)D_8010FBE0);
        for (i = 0; i < 4; i++) {
            func_00263D10(&D_8010F328[i]);
        }
        break;
    case 3:
        osContReset(&D_8010FC00, (OSContStatus *)D_8010FBE0);
    case 2:
        break;
    }
}
