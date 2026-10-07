#include "o01_types.h"

typedef struct O01SubA {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ s8 unk4;
} O01SubA;
typedef struct O01OwnA {
    /* 0x00 */ u8 pad0[0xC];
    /* 0x0C */ u8 *unkC;
    /* 0x10 */ u8 pad10[0x10];
    /* 0x20 */ O01SubA *unk20;
} O01OwnA;
extern s32 D_8015375C;
extern s32 D_800E28C8;
extern s32 D_800E28C4;
extern char *D_800D770C;
extern char *D_800D7708;
extern char *D_800D7700;
extern char *D_800D7704;
s32 func_0040458C(s32 pad, s32 idx, s32 *valid, u8 *name, u8 *ext, s32 *blocks, u8 *company, u8 *game);
s32 func_002A1238(char *s);
s32 func_002A137C(char *a, char *b);

static inline s32 O01Match(char *a, char *b) {
    if (func_002A1238(b) == 4 && func_002A1238(a) == 2 && func_002A137C(b, D_800D770C) == 0 && func_002A137C(a, D_800D7708) == 0) {
        return 1;
    }
    return 0;
}

void func_00405F48(O01OwnA *own) {
    u8 ext[8];
    u8 company[8];
    u8 game[8];
    u8 name[16];
    s32 valid;
    s32 blocks;
    s32 pad;
    s32 i;
    s32 ok;
    s32 m;
    char *n2;
    u32 *flags;
    if (D_8015375C != 0) {
        pad = D_800E28C8;
    } else {
        pad = own->unk20->unk4;
    }
    for (i = 0; i < 16; i++) {
        ok = 1;
        if (func_0040458C(pad, i, &valid, name, ext, &blocks, company, game) == 0 && valid != 0) {
            m = D_800E28C4;
            switch (m) {
            case 1:
                m = O01Match((char *)company, (char *)game);
                n2 = D_800D7700;
                break;
            case 2:
                m = O01Match((char *)company, (char *)game);
                n2 = D_800D7704;
                break;
            case 0:
            default:
                ok = 0;
                goto next;
            }
            if (func_002A137C((char *)name, n2) == 0) {
                if (m != 0) {
                    ok = 0;
                }
            }
        }
    next:
        flags = (u32 *)(own->unkC + i * 0x28 + 0x78 + 8);
        if (ok != 0) {
            *flags &= 0xFEFFFFFF;
        } else {
            *flags |= 0x01000000;
        }
    }
}
