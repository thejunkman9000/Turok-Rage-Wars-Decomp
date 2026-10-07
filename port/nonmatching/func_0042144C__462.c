#include "o03_types.h"
extern O3Pm *D_800E4400;
void func_0040E958(void *it, s32 on);
O3TxtItem *func_0040ECB0(void *p, s32 id);
void func_004215D8();
void func_0042144C(void) {
    s32 i;
    O3TxtItem *it;
    func_0040E958(D_800E4400->item, 1);
    i = 0;
    func_0040E958(func_0040ECB0(D_800E4400->w8, 0x3AB), i);
    D_800E4400->timer = 1;
    D_800E4400->f28 = 8;
    D_800E4400->f30 = 0;
    D_800E4400->f34 = 0;
    do {
        switch (i) {
        case 1:
            it = func_0040ECB0(D_800E4400->w8, 0x3B9);
            break;
        case 2:
            it = func_0040ECB0(D_800E4400->w8, 0x3BA);
            break;
        case 3:
            it = func_0040ECB0(D_800E4400->w8, 0x3BB);
            break;
        case 4:
            it = func_0040ECB0(D_800E4400->w8, 0x3BC);
            break;
        case 5:
            it = func_0040ECB0(D_800E4400->w8, 0x3BD);
            break;
        case 6:
            it = func_0040ECB0(D_800E4400->w8, 0x3BE);
            break;
        case 7:
            it = func_0040ECB0(D_800E4400->w8, 0x3BF);
            break;
        case 8:
            it = func_0040ECB0(D_800E4400->w8, 0x3C0);
            break;
        case 9:
            it = func_0040ECB0(D_800E4400->w8, 0x3C1);
            break;
        case 0:
        default:
            it = func_0040ECB0(D_800E4400->w8, 0x3B8);
            break;
        }
        it->h.alpha = 0x96;
        it->txt = 0;
        i++;
    } while (i < 10);
    func_004215D8();
}
