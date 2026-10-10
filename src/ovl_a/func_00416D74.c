#include "o03_types.h"
extern s32 D_800E32C0;
extern s32 D_80153F6C;
void func_00416D74(s32 mode) {
    if (mode != D_800E32C0) {
        D_800E32C0 = mode;
        O3_Sync();
        O3_PUSH(0xE3000A01, 0);
        switch (mode) {
        case 1:
            if (D_80153F6C) {
                O3_PUSH(0xFC12B225, 0xFF67DBED);
            } else {
                O3_PUSH(0xFC12FE25, 0xFFFFFDFE);
            }
            break;
        case 2:
            if (D_80153F6C) {
                O3_PUSH(0xFC12FE25, 0xFFFFF7FB);
            } else {
                O3_PUSH(0xFC12FE25, 0xFFFFFDFE);
            }
            break;
        case 3:
            O3_PUSH(0xFC12FE25, 0xFFFFFDFE);
            break;
        case 4:
            if (D_80153F6C) {
                O3_PUSH(0xFC121824, 0xFF33FFFF);
            } else {
                O3_PUSH(0xFC127E24, 0xFFFFFDFE);
            }
            break;
        case 5:
            if (D_80153F6C) {
                O3_PUSH(0xFCFFFFFF, 0xFFFE793C);
            } else {
                O3_PUSH(0xFCFFFFFF, 0xFFFE7D3E);
            }
            break;
        }
    }
}
