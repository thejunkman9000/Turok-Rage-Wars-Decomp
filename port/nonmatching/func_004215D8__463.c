#include "o03_types.h"
extern O3Pm *D_800E4400;
extern s32 *D_800D7E40;
void func_0040E958(void *it, s32 on);
O3TxtItem *func_0040ECB0(void *p, s32 id);
void func_004215D8(void) {
    s32 i, k, txt;
    O3TxtItem *it;
    i = D_800E4400->f28;
    k = D_800E4400->f30;
    do {
        txt = D_800D7E40[k];
        if (txt != 0) {
            k++;
        }
        it = func_0040ECB0(D_800E4400->w8, 0x3B8);
        switch (i) {
        case 0:
            it = func_0040ECB0(D_800E4400->w8, 0x3B8);
            it->txt = (void *)txt;
            break;
        case 1:
            it = func_0040ECB0(D_800E4400->w8, 0x3B9);
            it->txt = (void *)txt;
            break;
        case 2:
            it = func_0040ECB0(D_800E4400->w8, 0x3BA);
            it->txt = (void *)txt;
            break;
        case 3:
            it = func_0040ECB0(D_800E4400->w8, 0x3BB);
            it->txt = (void *)txt;
            break;
        case 4:
            it = func_0040ECB0(D_800E4400->w8, 0x3BC);
            it->txt = (void *)txt;
            break;
        case 5:
            it = func_0040ECB0(D_800E4400->w8, 0x3BD);
            it->txt = (void *)txt;
            break;
        case 6:
            it = func_0040ECB0(D_800E4400->w8, 0x3BE);
            it->txt = (void *)txt;
            break;
        case 7:
            it = func_0040ECB0(D_800E4400->w8, 0x3BF);
            it->txt = (void *)txt;
            break;
        case 8:
            it = func_0040ECB0(D_800E4400->w8, 0x3C0);
            it->txt = (void *)txt;
            break;
        case 9:
            it = func_0040ECB0(D_800E4400->w8, 0x3C1);
            it->txt = (void *)txt;
            break;
        default:
            it->txt = (void *)txt;
            break;
        }
        i++;
    } while (i < 10);
    if (D_800D7E40[D_800E4400->f30] != 0) {
        if (D_800E4400->f28 == 0) {
            D_800E4400->f30 = D_800E4400->f30 + 1;
        }
    } else {
        func_0040E958(D_800E4400->item, 0);
        func_0040E958(func_0040ECB0(D_800E4400->w8, 0x3AB), 1);
        D_800E4400->f34 = 1;
    }
    if (D_800E4400->f28 > 0) {
        D_800E4400->f28 = D_800E4400->f28 - 1;
    }
}
