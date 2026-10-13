#include "o03_types.h"
#include "veu3n06_types.h"
extern O3Pm *D_auto_800F0A20;
extern s32 *D_auto_800E42A4[];
void func_auto_0040ED18(void *it, s32 on);
O3TxtItem *func_auto_0040F070(void *p, s32 id);
void func_auto_00421A90(void) {
    s32 i, k, txt;
    O3TxtItem *it;
    i = D_auto_800F0A20->f28;
    k = D_auto_800F0A20->f30;
    do {
        txt = D_auto_800E42A4[D_801462C8.lang][k];
        if (txt != 0) {
            k++;
        }
        it = func_auto_0040F070(D_auto_800F0A20->w8, 0x3B8);
        switch (i) {
        case 0:
            it = func_auto_0040F070(D_auto_800F0A20->w8, 0x3B8);
            break;
        case 1:
            it = func_auto_0040F070(D_auto_800F0A20->w8, 0x3B9);
            break;
        case 2:
            it = func_auto_0040F070(D_auto_800F0A20->w8, 0x3BA);
            break;
        case 3:
            it = func_auto_0040F070(D_auto_800F0A20->w8, 0x3BB);
            break;
        case 4:
            it = func_auto_0040F070(D_auto_800F0A20->w8, 0x3BC);
            break;
        case 5:
            it = func_auto_0040F070(D_auto_800F0A20->w8, 0x3BD);
            break;
        case 6:
            it = func_auto_0040F070(D_auto_800F0A20->w8, 0x3BE);
            break;
        case 7:
            it = func_auto_0040F070(D_auto_800F0A20->w8, 0x3BF);
            break;
        case 8:
            it = func_auto_0040F070(D_auto_800F0A20->w8, 0x3C0);
            break;
        case 9:
            it = func_auto_0040F070(D_auto_800F0A20->w8, 0x3C1);
            break;
        }
        it->txt = (void *)txt;
        i++;
    } while (i < 10);
    if (D_auto_800E42A4[D_801462C8.lang][D_auto_800F0A20->f30] != 0) {
        if (D_auto_800F0A20->f28 == 0) {
            D_auto_800F0A20->f30 = D_auto_800F0A20->f30 + 1;
        }
    } else {
        func_auto_0040ED18(D_auto_800F0A20->item, 0);
        func_auto_0040ED18(func_auto_0040F070(D_auto_800F0A20->w8, 0x3AB), 1);
        D_auto_800F0A20->f34 = 1;
    }
    if (D_auto_800F0A20->f28 > 0) {
        D_auto_800F0A20->f28 = D_auto_800F0A20->f28 - 1;
    }
}
