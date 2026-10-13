#include "o01_types.h"

extern u16 D_8015371C;
extern u8 D_auto_80152789;
extern char *D_auto_800E2814[];
extern char *D_auto_800E2824[];
extern char *D_auto_800E2834[];
extern char *D_auto_800E2844[];
extern char *D_auto_800E2854[];
extern char *D_auto_800E2864[];
extern char *D_auto_800E2874[];
extern char *D_auto_800E2884[];
extern char *D_auto_800E2894[];
extern char *D_auto_800E28A4[];
extern char *D_auto_800E28B4[];
extern char *D_auto_800E28C4[];
s32 func_auto_00442EE0();

s32 func_auto_00408CAC(O01Item *item) {
    u32 v = D_8015371C;
    char *s = 0;
    u8 *dst;
    s32 i;
    if (v < 50) {
        s = D_auto_800E2814[D_auto_80152789];
    } else if (v >= 50 && v < 150) {
        s = D_auto_800E2824[D_auto_80152789];
    } else if (v >= 150 && v < 300) {
        s = D_auto_800E2834[D_auto_80152789];
    } else if (v >= 300 && v < 500) {
        s = D_auto_800E2844[D_auto_80152789];
    } else if (v >= 500 && v < 800) {
        s = D_auto_800E2854[D_auto_80152789];
    } else if (v >= 800 && v < 1300) {
        s = D_auto_800E2864[D_auto_80152789];
    } else if (v >= 1300 && v < 2000) {
        s = D_auto_800E2874[D_auto_80152789];
    } else if (v >= 2000 && v < 3000) {
        s = D_auto_800E2884[D_auto_80152789];
    } else if (v >= 3000 && v < 4500) {
        s = D_auto_800E2894[D_auto_80152789];
    } else if (v >= 4500 && v < 6500) {
        s = D_auto_800E28A4[D_auto_80152789];
    } else if (v >= 6500 && v < 9999) {
        s = D_auto_800E28B4[D_auto_80152789];
    } else if ((s32)v >= 9999) {
        s = D_auto_800E28C4[D_auto_80152789];
    }
    dst = (u8 *)((u8 **)item->unk14)[D_auto_80152789];
    dst += func_auto_00442EE0() - 11;
    if (s != 0) {
        for (i = 0; i < 11; i++) {
            *dst++ = *s++;
        }
    }
    return 0;
}
