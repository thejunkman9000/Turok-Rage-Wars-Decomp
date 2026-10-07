#include "o01_types.h"

typedef struct O01It {
    /* 0x00 */ s32 code;
    /* 0x04 */ u8 pad4[0x10];
    /* 0x14 */ O01Text *unk14;
} O01It;
typedef struct O01Sub7 {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ s8 unk4;
} O01Sub7;
typedef struct O01Own7 {
    /* 0x00 */ u8 pad0[0x20];
    /* 0x20 */ O01Sub7 *unk20;
} O01Own7;
extern s32 D_80153784;
extern s32 D_8015375C;
extern s32 D_800E28C8;
extern char *D_800D7784;
extern char *D_800D7788[];
extern u8 D_800E0DA4[];
s32 func_0040458C(s32 pad, s32 idx, s32 *valid, u8 *name, u8 *ext, s32 *blocks, u8 *company, u8 *game);
s32 func_004057BC(u8 *p, s32 n);
char *func_002A125C(char *dst, char *src);
void func_00265904(char *dst, u8 *fmt, s32 a);

s32 func_00407F6C(O01It *item, O01Own7 *own) {
    u8 name[16];
    u8 ext[8];
    u8 company[8];
    u8 game[8];
    s32 valid;
    s32 blocks;
    s32 pad;
    s32 idx;
    s32 r;
    s32 ok;
    s32 c;
    s32 i;
    u8 *dst;
    idx = item->code - 3;
    c = 0x20;
    if (D_80153784 != 0) {
        return 0;
    }
    if (D_8015375C != 0) {
        pad = D_800E28C8;
    } else {
        pad = own->unk20->unk4;
    }
    r = func_0040458C(pad, idx, &valid, name, ext, &blocks, company, game);
    if (valid != 0 && r == 0) {
        if (func_004057BC(name, 16) != 0) {
            func_002A125C((char *)name, D_800D7784);
        }
    } else {
        func_002A125C((char *)name, D_800D7788[0]);
        func_002A125C((char *)ext, D_800D7788[0]);
        blocks = 0;
    }
    ok = 1;
    dst = (u8 *)item->unk14->buf;
    dst += 3;
    for (i = 0; i < 16; i++) {
        if (ok != 0) {
            c = name[i];
        }
        if (c != 0) {
            *dst = c;
        } else {
            ok = 0;
            c = 0x20;
            *dst = c;
        }
        dst++;
    }
    ok = 1;
    dst += ok;
    for (i = 0; i < 4; i++) {
        if (ok != 0) {
            c = ext[i];
        }
        if (c != 0) {
            *dst = c;
        } else {
            ok = 0;
            c = 0x20;
            *dst = c;
        }
        dst++;
    }
    *dst = *dst + 2;
    func_00265904((char *)dst, D_800E0DA4, blocks);
    return 0;
}
