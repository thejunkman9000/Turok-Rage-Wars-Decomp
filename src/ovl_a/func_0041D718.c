#include "o03_types.h"
extern O3Pk *D_800E3590;
extern O3Rec D_80102B00[];
O3TxtItem *func_0040ECB0(s32 p, s32 id);
void func_0040E958(void *it, s32 on);
void func_002A1C08();
void *func_00424FC8(s32 slot);
s32 func_004261E4(s32 slot);
void func_0041D718(void) {
    O3TxtItem *it;
    s32 v;
    it = func_0040ECB0(D_800E3590->parent, 0x1F3);
    func_0040E958(it, 1);
    it->txt = &D_80102B00[D_800E3590->slot];
    it = func_0040ECB0(D_800E3590->parent, 0x1F2);
    func_0040E958(it, 1);
    it->txt = func_00424FC8(D_800E3590->slot);
    it = func_0040ECB0(D_800E3590->parent, 0x1FD);
    func_0040E958(it, 1);
    func_002A1C08(D_800E3590->name, "%ld", D_80102B00[D_800E3590->slot].f70);
    it->txt = D_800E3590->name;
    it = func_0040ECB0(D_800E3590->parent, 0x1F4);
    func_0040E958(it, 1);
    func_002A1C08(D_800E3590->str142, "%ld", D_80102B00[D_800E3590->slot].f6C);
    it->txt = D_800E3590->str142;
    it = func_0040ECB0(D_800E3590->parent, 0x1F6);
    func_0040E958(it, 1);
    func_002A1C08(D_800E3590->str174, "%ld", D_80102B00[D_800E3590->slot].f74);
    it->txt = D_800E3590->str174;
    v = func_004261E4(D_800E3590->slot);
    it = func_0040ECB0(D_800E3590->parent, 0x1F9);
    func_0040E958(it, 1);
    func_002A1C08(D_800E3590->str1A6, "%d", v);
    it->txt = D_800E3590->str1A6;
    it = func_0040ECB0(D_800E3590->parent, 0x1FA);
    func_0040E958(it, 1);
    func_002A1C08(D_800E3590->str1D8, "%d", D_80102B00[D_800E3590->slot].f17);
    it->txt = D_800E3590->str1D8;
}
