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
typedef struct { char **name; u8 pad4[0x6C]; } Ent70;

void *memcpy(void *dst, const void *src, u32 n);
void func_00245AB8(void);
void func_00245A68();
s32 func_0028FE08(s32 a, s32 b, s32 idx);
void *func_00254224(s32 a, s32 *out, s32 b, void *c);
Blk *func_002543A8(s32 a, s32 b, s32 c, s32 d, void *e, s32 f, void *g);
void func_002537D8(s32 a, void *b);
void func_002A1C08();
u32 func_0022F444(u8 *p, s32 a);
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
typedef struct { u8 pad0[0xD]; u8 mode; u8 pad1[0x573]; u8 lang; } Stt;
extern Stt D_auto_80152208;
extern u8 D_auto_80152789;
extern s32 D_80154028[];
extern Cfg *D_800E4680;
extern char *D_auto_800E17A4[];
extern char *D_auto_800E1784[];
extern char *D_auto_800E1794[];
extern char *D_auto_800E17D4[];
extern char *D_auto_800E17B4[];
extern char *D_auto_800E17C4[];
extern char *D_auto_800E17E4[];
extern char *D_auto_800E17F4[];
extern char *D_auto_800E1894[];
extern char *D_auto_800E18A4[];
extern char *D_auto_800E1734[];
extern char *D_800E1664_eu[];
extern char *D_auto_800E1724[];
extern char *D_auto_800E1744[];
extern char *D_auto_800E1754[];
extern char *D_auto_800E1804[];
extern char *D_auto_800E1814[];
extern char *D_auto_800E1874[];
extern char *D_auto_800E1884[];
extern char *D_auto_800E1824[];
extern char *D_auto_800E1834[];
extern char *D_auto_800E1844[];
extern char *D_auto_800E1854[];
extern char *D_auto_800E1864[];
extern char *D_auto_800E18B4[];
extern u8 D_80102B00[];
extern s32 D_8011FE9C;
extern s32 D_8011FEA0;
extern s32 D_8011FE94;
extern s32 D_8011FE98;
extern u8 D_800CA380[];
extern u8 D_800CA3AC[];
extern char D_800CA3D4[];
extern Ent70 D_800E3ABC[];

void func_auto_0028A8F4(void) {
    char bufA[0x28];
    char bufB[0x28];
    s32 sp78;
    s32 sp7C;
    s32 s0;
    s32 s3;
    s32 t3;
    void *s2;
    Blk *b;
    s32 n;
    s32 m;
    Cfg *cfg;
    char *pA;
    u32 uv;
    u8 *nv;
    u32 qq;
    s32 sa3;
    u32 ua3w;
    u8 ua2;
    u8 ua3;
    s32 ent;
    u8 mode;
    s32 ty;
    s32 *h;
    s32 p;
    s32 sz;
    s32 v;
    s32 q;
    s32 a2;
    s32 a3;
    Stt *sa;
    Stt *sb;
    Stt *sc;
    char **nm;
    func_00245AB8();
    s3 = D_8015402C;
    s0 = func_0028FE08(D_8011FED4, D_8011FEA4, s3);
    s2 = func_00254224(0, &sp78, s0, D_800CA200);
    b = func_002543A8(0, sp78, 8, s0, D_8011FE88, 0, &D_800CA370[1]);
    pA = bufA;
    n = b->size;
    m = 0x3F;
    if (m < n) {
        n = m;
    }
    memcpy(pA, b->data, n);
    func_002537D8(0, b);
    if (D_8013B294 != s3) {
        func_002537D8(0, s2);
    }
    func_00245A68(pA);
    sa = &D_auto_80152208;
    if (sa->mode != 0) {
        switch (D_80154028[0]) {
        case 0:
            if (sa->mode == 2) {
                func_002A1C08(bufB, D_auto_800E17A4[sa->lang], D_800E4680->unk23);
            } else {
                cfg = D_800E4680;
                if (cfg->unk23 < 2) {
                    func_002A1C08(bufB, D_auto_800E1784[sa->lang], cfg->unk23);
                } else {
                    func_002A1C08(bufB, D_auto_800E1794[sa->lang], cfg->unk23);
                }
            }
            break;
        case 1:
            if (sa->mode == 2) {
                func_002A1C08(bufB, D_auto_800E17D4[sa->lang], D_800E4680->unk21);
            } else {
                cfg = D_800E4680;
                if (cfg->unk21 < 2) {
                    func_002A1C08(bufB, D_auto_800E17B4[sa->lang], cfg->unk21);
                } else {
                    func_002A1C08(bufB, D_auto_800E17C4[sa->lang], cfg->unk21);
                }
            }
            break;
        case 2:
            cfg = D_800E4680;
            if (cfg->unk21 < 2) {
                func_002A1C08(bufB, D_auto_800E17E4[sa->lang], cfg->unk21);
            } else {
                func_002A1C08(bufB, D_auto_800E17F4[sa->lang], cfg->unk21);
            }
            break;
        case 3:
            switch (D_80154028[1]) {
            case 4:
                func_002A1C08(bufB, D_auto_800E1894[sa->lang], D_auto_800E1724[sa->lang]);
                break;
            case 9:
                func_002A1C08(bufB, D_auto_800E18A4[sa->lang], D_auto_800E1734[sa->lang], D_800E1664_eu[sa->lang]);
                break;
            case 0x16:
                func_002A1C08(bufB, D_auto_800E1894[sa->lang], D_auto_800E1744[sa->lang]);
                break;
            case 0x23:
                func_002A1C08(bufB, D_auto_800E1894[sa->lang], D_auto_800E1754[sa->lang]);
                break;
            default:
                cfg = D_800E4680;
                if (cfg->unk22 < 2) {
                    func_002A1C08(bufB, D_auto_800E1804[D_auto_80152789], cfg->unk22);
                } else {
                    func_002A1C08(bufB, D_auto_800E1814[D_auto_80152789], cfg->unk22);
                }
                break;
            }
            break;
        }
        sb = &D_auto_80152208;
        mode = sb->mode;
        switch (mode) {
        case 1:
            func_00245A68(bufB);
            uv = func_0022F444(D_80102B00, D_80102B00[0xF]);
            a2 = ((uv & 0xFF) >> 1) + 1;
            if (a2 < 2) {
                func_002A1C08(bufA, D_auto_800E1874[sb->lang], a2);
            } else {
                func_002A1C08(bufA, D_auto_800E1884[sb->lang], a2);
            }
            func_00245A68(bufA);
            break;
        case 3:
            func_00245A68(bufB);
            cfg = D_800E4680;
            if (cfg->unk24 < 0x3D) {
                func_002A1C08(bufA, D_auto_800E1824[sb->lang], cfg->unk24);
            } else {
                uv = cfg->unk24;
                ua2 = uv / 60;
                if (ua2 < 2) {
                    ua3w = (uv % 60) & 0xFF;
                    if (ua3w == 0) {
                        func_002A1C08(bufA, D_auto_800E1854[sb->lang], ua2);
                    } else {
                        func_002A1C08(bufA, D_auto_800E1834[sb->lang], ua2, ua3w);
                    }
                } else {
                    ua3w = (uv % 60) & 0xFF;
                    if (ua3w == 0) {
                        func_002A1C08(bufA, D_auto_800E1864[sb->lang], ua2);
                    } else {
                        func_002A1C08(bufA, D_auto_800E1844[sb->lang], ua2, ua3w);
                    }
                }
            }
            func_00245A68(bufA);
            break;
        case 4:
            t3 = D_8015402C;
            if (D_8011FE9C == 0 || D_8011FEA0 != t3) {
                nv = D_800CA380;
                func_0028DA50(D_8011FE88);
                sz = D_8011FE94;
                if (sz != 0) {
                    sz = 0;
                    { register s32 av __asm__("$5"); av = D_8011FE94; h = func_002518DC(0, av, av, D_8011FE98, 0x10, 0, 0, nv, 1); }
                    if (h != 0) {
                        p = func_0028FE1C(*h, D_8011FE94, t3, &sp7C);
                        func_002537D8(0, h);
                        D_8011FE9C = (s32)func_002518DC(0, p, p, sp7C, 0x10, 0, func_00285130, D_800CA3AC, 1);
                        if (D_8011FE9C != 0) {
                            D_8011FEA0 = t3;
                        }
                    }
                }
            }
            if (D_8011FE9C != 0) {
                ent = *(s32 *)D_8011FE9C;
            } else {
                ent = 0;
            }
            ty = func_0041F1B0(((Ent4 *)ent)->unk4);
            nm = D_800E3ABC[ty].name;
            sc = &D_auto_80152208;
            func_002A1C08(bufA, D_800CA3D4, nm[sc->lang]);
            func_00245A68(bufA);
            func_00245A68(bufB);
            cfg = D_800E4680;
            if (cfg->unk28 < 2) {
                func_002A1C08(bufA, D_auto_800E1874[sc->lang], cfg->unk28);
            } else {
                func_002A1C08(bufA, D_auto_800E1884[sc->lang], cfg->unk28);
            }
            func_00245A68(bufA);
            break;
        case 2:
            func_00245A68(bufB);
            if (D_80154028[0] == 1 || (D_80154028[0] >= 2 && D_80154028[0] == mode)) {
                func_00245A68(D_auto_800E18B4[sb->lang]);
            }
            break;
        }
    }
}
