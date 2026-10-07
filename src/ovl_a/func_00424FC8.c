#include "o04_types.h"
typedef struct { u8 pad[0x15]; u8 unk15; u8 pad16[0x3A - 0x16]; u8 unk3A[0x190 - 0x3A]; } O04Row190t;
extern O04Row190t D_80102B10[];
extern char *D_800D722C;
extern char *D_800D7230;
extern char *D_800D7234;
extern char *D_800D7238;
extern char *D_800D723C;
extern char *D_800D7240;
extern char *D_800D7244;
extern char *D_800D7248;
extern char *D_800D724C;
extern char *D_800D7250;
extern char *D_800D7254;
extern char *D_800D7258;
extern char *D_800D725C;
extern char *D_800D7260;
extern char *D_800D7264;
extern char *D_800D7268;
extern char *D_800D726C;
extern char *D_800D7270;
extern char *D_800D7274;
extern char *D_800D7278;
extern char *D_800D727C;
s32 func_00265670(void *p, s32 a);
char *func_00424FC8(s32 a) {
    s32 n;
    s32 i;
    s32 lv;
    char *s;
    if (a >= 4) {
        return D_800D722C;
    }
    n = 0;
    for (i = 0; i < 0x32; i++) {
        if (func_00265670(D_80102B10[a].unk3A, i) == 1) {
            n++;
        }
    }
    switch (n) {
    case 0:
    case 1:
        lv = 0;
        s = D_800D722C;
        break;
    case 2:
    case 3:
        lv = 1;
        s = D_800D7230;
        break;
    case 4:
    case 5:
        lv = 2;
        s = D_800D7234;
        break;
    case 6:
    case 7:
        lv = 3;
        s = D_800D7238;
        break;
    case 8:
    case 9:
        lv = 4;
        s = D_800D723C;
        break;
    case 10:
    case 11:
        lv = 5;
        s = D_800D7240;
        break;
    case 12:
    case 13:
        lv = 6;
        s = D_800D7244;
        break;
    case 14:
    case 15:
        lv = 7;
        s = D_800D7248;
        break;
    case 16:
    case 17:
        lv = 8;
        s = D_800D724C;
        break;
    case 18:
    case 19:
        lv = 9;
        s = D_800D7250;
        break;
    case 20:
    case 21:
        lv = 10;
        s = D_800D7254;
        break;
    case 22:
    case 23:
    case 24:
        lv = 11;
        s = D_800D7258;
        break;
    case 25:
    case 26:
    case 27:
        lv = 12;
        s = D_800D725C;
        break;
    case 28:
    case 29:
    case 30:
        lv = 13;
        s = D_800D7260;
        break;
    case 31:
    case 32:
    case 33:
        lv = 14;
        s = D_800D7264;
        break;
    case 34:
    case 35:
    case 36:
        lv = 15;
        s = D_800D7268;
        break;
    case 37:
    case 38:
    case 39:
        lv = 16;
        s = D_800D726C;
        break;
    case 40:
    case 41:
    case 42:
    case 43:
    case 44:
        lv = 17;
        s = D_800D7270;
        break;
    case 45:
    case 46:
    case 47:
    case 48:
    case 49:
        lv = 18;
        s = D_800D7274;
        break;
    default:
        lv = 0x13;
        s = D_800D7278;
        break;
    }
    D_80102B10[a].unk15 = lv;
    return s;
}
