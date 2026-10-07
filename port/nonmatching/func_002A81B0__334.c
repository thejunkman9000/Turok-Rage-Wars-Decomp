#include "b24_types.h"


extern u8 D_800D2F80[];
extern u8 D_800D2F90[];
extern u8 D_800E8000[];
extern u8 D_800F81F0[];
extern u8 D_800FD1F0[];
extern u8 D_8010FC40[];
extern u8 D_801462C8[];
extern u8 D_8016E000[];
extern s32 D_8014D330;
s32 func_00293424(u8 *, char *);
void func_002934A4(u8 *, char *);
void func_00292F08(void);
void *memset(void *, s32, u32);

typedef struct S15 {
    char c[15];
} S15;

inline s32 func_002A8544(u32 a) {
    u32 p = a | 0x80000000;
    if ((p >= (u32)D_800D2F80 && p < (u32)(D_800D2F80 + 0x10)) || p == (u32)&D_8014D330) {
        return 0;
    }
    if (D_8014D330 != 0) {
        return 1;
    }
    if ((p >= (u32)D_8010FC40 && p < (u32)(D_8010FC40 + 0x430)) ||
        (p >= (u32)D_801462C8 && p < (u32)(D_801462C8 + 0x584)) ||
        (p >= (u32)D_800FD1F0 && p < (u32)(D_800FD1F0 + 0x5800)) ||
        (p >= (u32)D_800F81F0 && p < (u32)(D_800F81F0 + 0x5000))) {
        return 0;
    }
    if (p >= (u32)(D_801462C8 + 0x5D8) && p <= (u32)(D_801462C8 + 0x688)) {
        return 0;
    }
    return 1;
}

inline s32 chkA(u32 a) {
    u32 p = a | 0x80000000;
    if ((p >= (u32)D_800D2F80 && p < (u32)D_800D2F90) || p == (u32)&D_8014D330) {
        return 0;
    }
    if (D_8014D330 != 0) {
        return 1;
    }
    if ((p >= (u32)D_8010FC40 && p < (u32)(D_8010FC40 + 0x430)) ||
        (p >= (u32)D_801462C8 && p < (u32)(D_801462C8 + 0x584)) ||
        (p >= (u32)D_800FD1F0 && p < (u32)(D_800FD1F0 + 0x5800)) ||
        (p >= (u32)D_800F81F0 && p < (u32)(D_800F81F0 + 0x5000))) {
        return 0;
    }
    if (p >= (u32)(D_801462C8 + 0x5D8) && p <= (u32)(D_801462C8 + 0x688)) {
        return 0;
    }
    return 1;
}

s32 func_002A81B0(void) {
    char buf[16];
    u32 *dst;
    u32 *src;
    s32 n;
    u32 *p;
    u32 *pi;

    *(S15 *)buf = *(S15 *)"systembootdone";
    memset(&buf[15], 0, 1);
    if (func_00293424(D_800D2F80, buf) == 0) {
        D_8014D330 = 0;
    } else {
        D_8014D330 = 1;
        func_002934A4(D_800D2F80, buf);
    }
    if (D_8014D330 == 0) {
        pi = (u32 *)0xA4600010;
        dst = (u32 *)0x80000400;
        src = (u32 *)0xB0001000;
        for (n = 0x3FFFF; n != 0; n--) {
            while (*pi & 3) {}
            if (chkA((u32)dst)) {
                *dst = *src;
            }
            dst++;
            src++;
        }
    }
    for (p = (u32 *)D_800E8000; p < (u32 *)D_8016E000; p++) {
        if (func_002A8544((u32)p)) {
            *p = 0;
        }
    }
    osInitialize();
    func_00292F08();
    return 0;
}
