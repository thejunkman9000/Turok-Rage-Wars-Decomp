#include "s1005_types.h"

extern u8 D_80145040[];
extern s32 D_800D29B4;
extern u8 D_800FD1F0[];
extern u8 D_800F81F0[];

extern void func_0028D628(S5Scene *lv);
extern void func_0044DE04(S5Scene *lv);
extern void func_0044AA68(void *holder);
extern void func_002538A8(s32 a);
extern void *func_00254224(s32 a, void *out, s32 id, void *name);
extern s32 func_0028FE08(void *tab, s32 base, s32 idx);
extern void **func_002543A8(s32 a, void *tab, s32 idx, s32 base, S5Scene *lv, void *cb, void *name);
extern s32 func_0028FE1C(void *tab, s32 base, s32 idx, s32 *out);
extern void func_00403BE0(void);
extern void *func_00254094(s32 a, void *out, s32 c, void *name, s32 e);
extern void func_002537D8(s32 a, void *h);
extern void func_0020A604(void *p);
extern void func_0044DC48(S5Scene *lv, s32 data);
extern void func_0044C250(S5Scene *lv, S5Simp *out, s32 id);
extern void func_00286A78(void *p, s32 a, s32 b);
extern void func_00285130();
extern void func_0044E584();
extern void func_0044E454();

void func_0044C410(S5Scene *lv, s32 data) {
    s32 *tab;
    s32 *blk;
    void **p;
    void **h;
    void *h2;
    s32 v;

    func_0028D628(lv);
    lv->f0 = 0;
    func_0044DE04(lv);
    lv->f4 = 0;
    lv->f8 = 0;
    lv->f1B40C = -1;
    lv->f1B31C = 0;
    lv->f1B308 = 0;
    lv->f1B614 = 0;
    lv->f1B618 = 0;
    lv->f1B61C = 0;
    lv->f1B660 = 0;
    lv->f1B6A4 = 0;
    lv->f1B6AC = 0;
    func_0044AA68(D_80145040);
    func_002538A8(0);
    func_00254224(0, &tab, data, "cartridge index");
    v = func_0028FE08(tab, data, 5);
    lv->f1C = v;
    func_00254224(0, &lv->f4C, v, "levels index");
    v = func_0028FE08(tab, data, 3);
    lv->f20 = v;
    func_00254224(0, &lv->f50, v, "texture sets index");
    p = func_002543A8(0, tab, 2, data, lv, func_00285130, "object types");
    lv->f94 = *p;
    v = func_0028FE08(tab, data, 0);
    lv->f24 = v;
    func_00254224(0, &lv->f54, v, "objects index");
    p = func_002543A8(0, tab, 1, data, lv, func_0044E584, "intelligence");
    lv->f78 = *p;
    p = func_002543A8(0, tab, 4, data, lv, func_0044E454, "particle effects");
    lv->fB4 = p;
    p = func_002543A8(0, tab, 0xA, data, lv, func_00285130, "object types");
    lv->f98 = *p;
    v = func_0028FE08(tab, data, 9);
    lv->f28 = v;
    func_00254224(0, &lv->f58, v, "binaries index");
    p = func_002543A8(0, tab, 0xB, data, lv, func_00285130, "particle swooshes");
    lv->f70 = *p;
    p = func_002543A8(0, tab, 0xC, data, lv, func_00285130, "dynamic lights");
    lv->fA0 = *p;
    lv->f80 = D_800FD1F0;
    v = func_0028FE1C(tab, data, 6, &lv->f44);
    lv->f38 = v;
    lv->f84 = D_800F81F0;
    v = func_0028FE1C(tab, data, 7, &lv->f48);
    lv->f3C = v;
    p = func_002543A8(0, tab, 8, data, lv, func_00285130, "warp dests");
    lv->f10C = p;
    lv->f90 = *p;
    p = func_002543A8(0, tab, 0xD, data, lv, func_00285130, "curves");
    lv->fA4 = *p;
    p = func_002543A8(0, tab, 0xE, data, lv, func_00285130, "rumbles");
    lv->fAC = *p;
    p = func_002543A8(0, tab, 0xF, data, lv, func_00285130, "rumble types");
    lv->fA8 = *p;
    p = func_002543A8(0, tab, 0x11, data, lv, func_00285130, "graphicset type");
    lv->f9C = *p;
    v = func_0028FE08(tab, data, 0x10);
    lv->f2C = v;
    func_00254224(0, &lv->f5C, v, "graphicset index");
    v = func_0028FE08(tab, data, 0x12);
    lv->f34 = v;
    func_00254224(0, &lv->f74, v, "Cinemas index");
    func_00403BE0();
    p = func_002543A8(0, tab, 0x13, data, lv, func_00285130, "link group types");
    lv->fB0 = *p;
    lv->fC = 0;
    lv->f10 = 0;
    lv->f14 = 0;
    lv->f18 = -1;
    if (*tab >= 0x16) {
        lv->fC = func_0028FE08(tab, data, 0x15);
        h2 = func_00254094(0, &blk, lv->fC, "CScene__Construct: BLLevelData Index", 1);
        if (h2 != 0) {
            lv->f10 = (*blk * 4 + 0xF) & ~7;
            func_002537D8(0, h2);
        } else {
            lv->fC = 0;
        }
    }
    if (*tab >= 0x18) {
        h = func_002543A8(0, tab, 0x17, data, lv, func_00285130, "Bloodlust Weapon Data");
        func_0020A604(*h);
        func_002537D8(0, h);
    }
    func_0044DC48(lv, data);
    D_800D29B4 = 1;
    func_0044C250(lv, &lv->simp[0], 0xDAC);
    func_0044C250(lv, &lv->simp[1], 0xDAD);
    func_0044C250(lv, &lv->simp[2], 0xDAE);
    func_0044C250(lv, &lv->simp[3], 0xDAF);
    func_0044C250(lv, &lv->simp[4], 0xDB0);
    lv->fF0 = 0;
    lv->fF4 = 0;
    lv->fFC = 0;
    lv->fF8 = 0;
    lv->f88 = 0;
    lv->f120 = 0;
    lv->f124 = 0;
    func_00286A78(lv, 0, 0);
}
