#include "o03_types.h"
/* real entry is glabel+2 words (rom 0x18D2A0): 2 leading junk words */
extern O3Pj *D_800E42D0;
extern O3IdRow D_800E42D4[];
extern O3Row D_800E3A50[];
extern O3Pl4 D_80146398[];
extern f32 D_800E1570;
void *func_00252FFC(s32 size);
s32 func_0041B690(s32 p, s32 n);
void func_0041B768(s32 p, s32 i, s32 id);
void func_0042EB80();
s32 func_0041F1FC(s32 key);
s32 func_0041F248(s32 key);
void func_0041CB48(void *o, s32 a, s32 b, s32 c, s32 d, O3Vec3 v, O3V3i w, f32 f, s32 g);
O3Hdr *func_0040ECB0(s32 p, u16 id);
O3Sp2 *func_0040ECB0b(s32 p, u16 id) __asm__("func_0040ECB0");
void func_0040E958(void *it, s32 on);
s32 func_00419ED4(s32 a, s32 b);
void func_0041FF9C(void);
void func_00420378(s32 i);
void func_002A338C();
s32 func_0041F298(s32 root) {
    O3Vec3 v;
    s32 i, k, key, ch, row, t;
    O3Sp2 *it;
    D_800E42D0 = func_00252FFC(0x1358);
    D_800E42D0->f0 = root;
    D_800E42D0->menu = func_0041B690(root, 4);
    func_0041B768(root, 0, 0x7A);
    func_0041B768(root, 1, 0x7A);
    func_0041B768(root, 2, 0x7A);
    func_0041B768(root, 3, 0x7A);
    func_0042EB80(0, 0);
    ((O3PjT *)&D_800E42D0[4])->f30 = 0;
    v.x = D_800E1570;
    v.y = D_800E1570;
    v.z = D_800E1570;
    i = 0;
    do {
        (D_800E42D0 + i)->fC = 0;
        key = *(s32 *)&D_800E42D4[i];
        (D_800E42D0 + i)->f8 = 0;
        (D_800E42D0 + i)->state = 0;
        (D_800E42D0 + i)->f18 = 0;
        (D_800E42D0 + i)[1].f0 = 0;
        (D_800E42D0 + i)->f10 = key;
        ch = func_0041F248(key);
        row = func_0041F1FC((D_800E42D0 + i)->f10);
        v.x = v.y = v.z = D_800E3A50[row].fC[i];
        func_0041CB48((D_800E42D0 + i)->sub, 9, ch + 0x38F, 0x4B, 0x5DC0, v, D_800E3A50[row].v2C[i], D_800E3A50[row].f1C[i], D_800E3A50[row].f5C[i]);
        func_0040ECB0(D_800E42D0->f0, D_800E42D4[i].e[2].id)->alpha = 0x6E;
        for (k = 0; k < 3; k++) {
            func_0040ECB0(D_800E42D0->f0, D_800E42D4[i].e[3 + k].id)->alpha = 0x50;
            func_0040E958(func_0040ECB0(D_800E42D0->f0, D_800E42D4[i].e[6 + k].id), 1);
        }
        i++;
    } while (i < 4);
    D_800E42D0[4].f18 = 1;
    D_800E42D0[4].f1C = 4;
    it = func_0040ECB0b(root, 0xAC);
    ((O3PjT *)&D_800E42D0[4])->f8 = it;
    it->f14 = it->f14 - it->f18;
    t = ((O3PjT *)&D_800E42D0[4])->f8->f18;
    if (t < 0) {
        t += 3;
    }
    t >>= 2;
    ((O3PjT *)&D_800E42D0[4])->fC = t;
    it = ((O3PjT *)&D_800E42D0[4])->f8;
    it->f14 = it->f14 + (it->f18 - t * 4);
    it = func_0040ECB0b(root, 0x93);
    ((O3PjT *)&D_800E42D0[4])->f10 = it;
    it->f14 = it->f14 + it->f18;
    t = ((O3PjT *)&D_800E42D0[4])->f10->f18;
    if (t < 0) {
        t += 3;
    }
    k = 0;
    t >>= 2;
    ((O3PjT *)&D_800E42D0[4])->f14 = t;
    it = ((O3PjT *)&D_800E42D0[4])->f10;
    it->f14 = it->f14 - (it->f18 - t * 4);
    func_0040ECB0(root, 0x76)->alpha = 0x6E;
    func_0040ECB0(root, 0x79)->alpha = 0x19;
    ((O3PjT *)&D_800E42D0[4])->f20 = func_00419ED4(0x74, 0xFF);
    ((O3PjT *)&D_800E42D0[4])->f24 = func_0040ECB0(root, 0x74);
    func_0040E958(((O3PjT *)&D_800E42D0[4])->f24, k);
    ((O3PjT *)&D_800E42D0[4])->f28 = func_0040ECB0(root, 0x7B);
    func_0040E958(((O3PjT *)&D_800E42D0[4])->f28, k);
    ((O3Hdr *)((O3PjT *)&D_800E42D0[4])->f28)->alpha = 0;
    ((O3PjT *)&D_800E42D0[4])->f2C = 0x32;
    func_0041FF9C();
    for (i = 0; i < 4; i++) {
        if (D_80146398[i].f78 == 1) {
            func_00420378(i);
        }
    }
    func_002A338C();
    ((O3PjT *)&D_800E42D0[4])->f34 = -1;
    return 0;
}
