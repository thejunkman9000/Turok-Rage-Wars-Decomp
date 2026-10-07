#include "b20_types.h"

typedef struct { void *data; s32 size; } Blk;
typedef struct { u8 pad0[4]; u8 unk4; } Ent4;
typedef struct {
    u8 pad0[0x21];
    u8 unk21;
    u8 unk22;
    u8 unk23;
    u8 unk24;
    u8 pad25[3];
    u8 unk28;
} Cfg;

void *memcpy(void *dst, const void *src, u32 n);
void func_00245AB8(void);
void func_00245A68();
s32 func_0028FE08(s32 *tbl, s32 *a, s32 idx);
void *func_00254224(s32 a, s32 *out, s32 b, void *c);
Blk *func_002543A8(s32 a, s32 b, s32 c, s32 d, void *e, s32 f, void *g);
void func_002537D8(s32 a, void *b);
void func_002A1C08();
s32 func_0022F444(u8 *p, s32 a);
void func_0028DA50(u8 *p);
s32 *func_002518DC(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, void *g, void *h, s32 i);
s32 func_0028FE1C(s32 tbl, s32 base, s32 idx, s32 *size);
void func_00285130();
s32 func_0041F1B0(s32 a);
extern s32 D_8011FED4;
extern s32 D_8011FEA4;
extern s32 D_8015402C;
extern u8 D_800CA200[];
extern u8 D_8011FE88[];
extern s32 D_800CA370[];
extern s32 D_8013B294;
extern u8 D_801462D5;
extern s32 D_80154028[];
extern Cfg *D_800E4680;
extern char *D_800D7380;
extern char *D_800D7378;
extern char *D_800D737C;
extern char *D_800D738C;
extern char *D_800D7384;
extern char *D_800D7388;
extern char *D_800D7390;
extern char *D_800D7394;
extern char *D_800D73BC;
extern char *D_800D73C0;
extern s32 D_800D7364;
extern s32 D_800D7330;
extern s32 D_800D7360;
extern s32 D_800D7368;
extern s32 D_800D736C;
extern char *D_800D7398;
extern char *D_800D739C;
extern char *D_800D73B4;
extern char *D_800D73B8;
extern char *D_800D73A0;
extern char *D_800D73A4;
extern char *D_800D73A8;
extern char *D_800D73AC;
extern char *D_800D73B0;
extern char *D_800D73C4;
extern u8 D_80102B00[];
extern s32 D_8011FE9C;
extern s32 D_8011FEA0;
extern s32 D_8011FE94;
extern s32 D_8011FE98;
extern u8 D_800CA380[];
extern u8 D_800CA3AC[];
extern u8 D_800E3ABC[];

void func_0028A924(void) {
    char bufA[0x28];
    char bufB[0x28];
    s32 sp78;
    s32 sp7C;
    s32 s0;
    s32 s3;
    void *s2;
    Blk *b;
    s32 n;
    s32 ty;
    s32 idx;
    s32 v;
    s32 a2;
    s32 a3;
    char *a1;
    s32 *h;
    s32 p;
    s32 sz;
    func_00245AB8();
    s3 = D_8015402C;
    s0 = func_0028FE08((s32 *)D_8011FED4, &D_8011FEA4, s3);
    s2 = func_00254224(0, &sp78, s0, D_800CA200);
    b = func_002543A8(0, sp78, 8, s0, D_8011FE88, 0, &D_800CA370[1]);
    n = b->size;
    if (0x3F < n) {
        n = 0x3F;
    }
    memcpy(bufA, b->data, n);
    func_002537D8(0, b);
    if (D_8013B294 != s3) {
        func_002537D8(0, s2);
    }
    func_00245A68(bufA);
    if (D_801462D5 != 0) {
        switch (D_80154028[0]) {
        case 0:
            if (D_801462D5 == 2) {
                a1 = D_800D7380;
                a2 = D_800E4680->unk23;
            } else if (D_800E4680->unk23 < 2) {
                a1 = D_800D7378;
                a2 = D_800E4680->unk23;
            } else {
                a1 = D_800D737C;
                a2 = D_800E4680->unk23;
            }
            func_002A1C08(bufB, a1, a2);
            break;
        case 1:
            if (D_801462D5 == 2) {
                a1 = D_800D738C;
                a2 = D_800E4680->unk21;
            } else if (D_800E4680->unk21 < 2) {
                a1 = D_800D7384;
                a2 = D_800E4680->unk21;
            } else {
                a1 = D_800D7388;
                a2 = D_800E4680->unk21;
            }
            func_002A1C08(bufB, a1, a2);
            break;
        case 2:
            if (D_800E4680->unk21 < 2) {
                a1 = D_800D7390;
            } else {
                a1 = D_800D7394;
            }
            a2 = D_800E4680->unk21;
            func_002A1C08(bufB, a1, a2);
            break;
        case 3:
            switch (D_80154028[1]) {
            case 9:
                func_002A1C08(bufB, D_800D73C0, D_800D7364, D_800D7330);
                break;
            case 4:
                func_002A1C08(bufB, D_800D73BC, D_800D7360);
                break;
            case 0x16:
                func_002A1C08(bufB, D_800D73BC, D_800D7368);
                break;
            case 0x23:
                func_002A1C08(bufB, D_800D73BC, D_800D736C);
                break;
            default:
                if (D_800E4680->unk22 < 2) {
                    a1 = D_800D7398;
                } else {
                    a1 = D_800D739C;
                }
                a2 = D_800E4680->unk22;
                func_002A1C08(bufB, a1, a2);
                break;
            }
            break;
        }
        switch (D_801462D5) {
        case 1:
            func_00245A68(bufB);
            a2 = ((func_0022F444(D_80102B00, D_80102B00[0xF]) & 0xFF) >> 1) + 1;
            if (a2 < 2) {
                a1 = D_800D73B4;
            } else {
                a1 = D_800D73B8;
            }
            func_002A1C08(bufA, a1, a2);
            func_00245A68(bufA);
            break;
        case 3:
            func_00245A68(bufB);
            v = D_800E4680->unk24;
            if (v < 0x3D) {
                func_002A1C08(bufA, D_800D73A0, v);
            } else {
                a2 = (v / 60) & 0xFF;
                if (a2 < 2) {
                    a3 = (v - (v / 60) * 60) & 0xFF;
                    if (a3 == 0) {
                        func_002A1C08(bufA, D_800D73AC, a2);
                    } else {
                        func_002A1C08(bufA, D_800D73A4, a2, a3);
                    }
                } else {
                    a3 = (v - (v / 60) * 60) & 0xFF;
                    if (a3 == 0) {
                        func_002A1C08(bufA, D_800D73B0, a2);
                    } else {
                        func_002A1C08(bufA, D_800D73A8, a2, a3);
                    }
                }
            }
            func_00245A68(bufA);
            break;
        case 4:
            s3 = D_8015402C;
            if (D_8011FE9C == 0 || D_8011FEA0 != s3) {
                func_0028DA50(D_8011FE88);
                if (D_8011FE94 != 0) {
                    h = func_002518DC(0, D_8011FE94, D_8011FE94, D_8011FE98, 0x10, 0, 0, D_800CA380, 1);
                    if (h != 0) {
                        p = func_0028FE1C(*h, D_8011FE94, s3, &sp7C);
                        func_002537D8(0, h);
                        D_8011FE9C = (s32)func_002518DC(0, p, p, sp7C, 0x10, 0, func_00285130, D_800CA3AC, 1);
                        if (D_8011FE9C == 0) {
                            goto skip;
                        }
                        D_8011FEA0 = s3;
                    }
                }
            }
            if (D_8011FE9C != 0) {
                idx = *(s32 *)D_8011FE9C;
            } else {
                idx = 0;
            }
skip:
            ty = func_0041F1B0(((Ent4 *)idx)->unk4);
            func_002A1C08(bufA, "%s", **(char ***)(D_800E3ABC + ty * 112));
            func_00245A68(bufA);
            func_00245A68(bufB);
            if (D_800E4680->unk28 < 2) {
                a1 = D_800D73B4;
            } else {
                a1 = D_800D73B8;
            }
            func_002A1C08(bufA, a1, D_800E4680->unk28);
            func_00245A68(bufA);
            break;
        case 2:
            func_00245A68(bufB);
            if (D_80154028[0] == 1 || (D_80154028[0] >= 2 && D_80154028[0] == D_801462D5)) {
                func_00245A68(D_800D73C4);
            }
            break;
        }
    }
}
