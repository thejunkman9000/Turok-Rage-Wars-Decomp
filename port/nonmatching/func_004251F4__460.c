#include "o04_types.h"
typedef struct {
    u8 pad0[0xF]; u8 unkF; u8 pad10[7]; u8 unk17; u8 pad18[0x125 - 0x18]; u8 grid[4][5]; u8 padx[0x190 - 0x125 - 20];
} O04Row190w;
extern O04Row190w D_80102B00[];
extern s32 D_8015402C[];
extern u8 *D_800E4680;
s32 func_00265670(void *p, s32 a);
void func_002656A8(void *p, s32 a, s32 b);
void func_0022F3E8(void *row, s32 a);
s32 func_0022F444(void *row, s32 a);
void func_0022F30C(void *row);
void func_0022F330(void *row);
void func_0022F354(void *row);
void func_0022F378(void *row);
void func_0022F4AC(void *row, s32 a);
void func_0022F504(void *row, s32 a);
s32 func_004251F4(s32 a) {
    s32 r = -1;
    O04Row190w *row = &D_80102B00[a];
    s32 t;
    if (func_00265670(row->grid[row->unkF], D_8015402C[0]) == 0) {
        func_002656A8(row->grid[row->unkF], D_8015402C[0], 1);
        t = D_800E4680[0];
        r = t + 0x1388;
        switch (t) {
    case 1:
        func_0022F3E8(row, row->unkF);
        func_0022F3E8(row, row->unkF);
        break;
    case 2:
        func_0022F3E8(row, row->unkF);
        if ((func_0022F444(row, row->unkF) & 1) == 0) {
            r = 0x1389;
        }
        break;
    case 3:
        func_0022F4AC(row, 0x4);
        break;
    case 4:
        func_0022F504(row, 0x2);
        break;
    case 5:
        func_0022F4AC(row, 0xE);
        break;
    case 6:
        func_0022F504(row, 0x6);
        break;
    case 7:
        func_0022F4AC(row, 0x7);
        break;
    case 8:
        func_0022F504(row, 0x10);
        break;
    case 9:
        func_0022F504(row, 0x5);
        break;
    case 10:
        func_0022F504(row, 0x11);
        break;
    case 11:
        func_0022F4AC(row, 0x6);
        break;
    case 12:
        func_0022F504(row, 0xE);
        break;
    case 13:
        func_0022F504(row, 0x4);
        break;
    case 14:
        func_0022F4AC(row, 0xC);
        break;
    case 15:
        func_0022F4AC(row, 0xA);
        break;
    case 16:
        func_0022F30C(row);
        break;
    case 17:
        func_0022F504(row, 0x8);
        break;
    case 18:
        func_0022F4AC(row, 0x8);
        break;
    case 19:
        func_0022F4AC(row, 0xF);
        break;
    case 20:
        func_0022F504(row, 0xB);
        break;
    case 21:
        func_0022F504(row, 0xA);
        break;
    case 22:
        func_0022F504(row, 0x3);
        break;
    case 23:
        func_0022F354(row);
        break;
    case 24:
        func_0022F330(row);
        break;
    case 25:
        func_0022F4AC(row, 0xD);
        break;
    case 26:
        func_0022F4AC(row, 0x9);
        break;
    case 27:
        func_0022F504(row, 0x1);
        break;
    case 28:
        func_0022F504(row, 0x9);
        break;
    case 29:
        func_0022F504(row, 0x7);
        break;
    case 30:
        func_0022F504(row, 0xD);
        break;
    case 31:
        func_0022F4AC(row, 0x5);
        break;
    case 33:
        func_0022F4AC(row, 0x1);
        break;
    case 34:
        func_0022F504(row, 0);
        break;
    case 37:
        func_0022F4AC(row, 0xB);
        break;
    case 53:
        row->unk17++;
        break;
    case 57:
        func_0022F378(row);
        break;
    case 52:
        break;
        case 0:
        default:
            r = -1;
            break;
        }
    }
    return r;
}
