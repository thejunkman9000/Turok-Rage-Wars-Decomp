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
        return r;
    case 2:
        func_0022F3E8(row, row->unkF);
        if ((func_0022F444(row, row->unkF) & 1) == 0) {
            r = 0x1389;
        }
        return r;
    case 3:
        func_0022F4AC(row, 0x4);
        return r;
    case 4:
        func_0022F504(row, 0x2);
        return r;
    case 5:
        func_0022F4AC(row, 0xE);
        return r;
    case 6:
        func_0022F504(row, 0x6);
        return r;
    case 7:
        func_0022F4AC(row, 0x7);
        return r;
    case 8:
        func_0022F504(row, 0x10);
        return r;
    case 9:
        func_0022F504(row, 0x5);
        return r;
    case 10:
        func_0022F504(row, 0x11);
        return r;
    case 11:
        func_0022F4AC(row, 0x6);
        return r;
    case 12:
        func_0022F504(row, 0xE);
        return r;
    case 13:
        func_0022F504(row, 0x4);
        return r;
    case 14:
        func_0022F4AC(row, 0xC);
        return r;
    case 15:
        func_0022F4AC(row, 0xA);
        return r;
    case 16:
        func_0022F30C(row);
        return r;
    case 17:
        func_0022F504(row, 0x8);
        return r;
    case 18:
        func_0022F4AC(row, 0x8);
        return r;
    case 19:
        func_0022F4AC(row, 0xF);
        return r;
    case 20:
        func_0022F504(row, 0xB);
        return r;
    case 21:
        func_0022F504(row, 0xA);
        return r;
    case 22:
        func_0022F504(row, 0x3);
        return r;
    case 23:
        func_0022F354(row);
        return r;
    case 24:
        func_0022F330(row);
        return r;
    case 25:
        func_0022F4AC(row, 0xD);
        return r;
    case 26:
        func_0022F4AC(row, 0x9);
        return r;
    case 27:
        func_0022F504(row, 0x1);
        return r;
    case 28:
        func_0022F504(row, 0x9);
        return r;
    case 29:
        func_0022F504(row, 0x7);
        return r;
    case 30:
        func_0022F504(row, 0xD);
        return r;
    case 31:
        func_0022F4AC(row, 0x5);
        return r;
    case 33:
        func_0022F4AC(row, 0x1);
        return r;
    case 34:
        func_0022F504(row, 0);
        return r;
    case 37:
        func_0022F4AC(row, 0xB);
        return r;
    case 53:
        row->unk17++;
        break;
    case 57:
        func_0022F378(row);
        return r;
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
