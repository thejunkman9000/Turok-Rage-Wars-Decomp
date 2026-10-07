#include "o04_types.h"
typedef struct { u8 pad0[0x80]; s8 unk80; u8 pad81[0x96 - 0x81]; } O04Ent96u;
typedef struct { u8 pad[0x190]; } O04Row190u;
extern O04Cfg D_801462C8[];
extern O04Row190u D_80102B00[];
extern s32 D_8015402C;
s32 func_0022F5B4(void *row, s32 bit);
void func_0022F594(void *row, s32 bit);
s32 func_00425854(s32 a) {
    O04Row190u *row;
    s32 s3;
    s32 s1;
    s32 s2;
    row = &D_80102B00[a];
    s3 = -1;
    if (D_801462C8->unkD != 1) {
        return s3;
    }
    if (D_801462C8->unk680 != 1) {
        return s3;
    }
    if (D_8015402C < 0x23) {
        return s3;
    }
    switch (((O04Ent96u *)((u8 *)D_801462C8 + 0xD0))[a].unk80) {
    case 0:
        if (!func_0022F5B4(row, 0x11)) {
            func_0022F594(row, 0x11);
            s3 = 0x11;
        }
        break;
    case 1:
        if (!func_0022F5B4(row, 0x6)) {
            func_0022F594(row, 0x6);
            s3 = 0x6;
        }
        break;
    case 2:
        if (!func_0022F5B4(row, 0x3)) {
            func_0022F594(row, 0x3);
            s3 = 0x3;
        }
        break;
    case 3:
        if (!func_0022F5B4(row, 0x4)) {
            func_0022F594(row, 0x4);
            s3 = 0x4;
        }
        break;
    case 4:
        if (!func_0022F5B4(row, 0xE)) {
            func_0022F594(row, 0xE);
        }
        break;
    case 5:
        if (!func_0022F5B4(row, 0x1)) {
            func_0022F594(row, 0x1);
            s3 = 0x1;
        }
        break;
    case 6:
        if (!func_0022F5B4(row, 0x12)) {
            func_0022F594(row, 0x12);
            s3 = 0x12;
        }
        break;
    case 7:
        if (!func_0022F5B4(row, 0x8)) {
            func_0022F594(row, 0x8);
            s3 = 0x8;
        }
        break;
    case 8:
        if (!func_0022F5B4(row, 0x9)) {
            func_0022F594(row, 0x9);
            s3 = 0x9;
        }
        break;
    case 9:
        if (!func_0022F5B4(row, 0xA)) {
            func_0022F594(row, 0xA);
            s3 = 0xA;
        }
        break;
    case 17:
        if (!func_0022F5B4(row, 0x2)) {
            func_0022F594(row, 0x2);
            s3 = 0x2;
        }
        break;
    case 18:
        break;
    }
    s2 = func_0022F5B4(row, 0x11);
    if (s2 == 1) {
        s1 = func_0022F5B4(row, 0x1);
        if (s1 == s2) {
            if (func_0022F5B4(row, 0x8) == s1) {
                if (func_0022F5B4(row, 0xB) == 0) {
                    func_0022F594(row, 0xB);
                }
            }
        }
    }
    s2 = func_0022F5B4(row, 0x2);
    if (s2 == 1) {
        s1 = func_0022F5B4(row, 0x6);
        if (s1 == s2) {
            if (func_0022F5B4(row, 0x9) == s1) {
                if (func_0022F5B4(row, 0xC) == 0) {
                    func_0022F594(row, 0xC);
                }
            }
        }
    }
    s2 = func_0022F5B4(row, 0x3);
    if (s2 == 1) {
        s1 = func_0022F5B4(row, 0x12);
        if (s1 == s2) {
            if (func_0022F5B4(row, 0xA) == s1) {
                if (func_0022F5B4(row, 0xD) == 0) {
                    func_0022F594(row, 0xD);
                }
            }
        }
    }
    return s3;
}
