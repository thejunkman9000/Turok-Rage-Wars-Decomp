#include "o01_types.h"

extern s32 D_80153774;
extern s8 D_80153720[];
extern O01Text D_800D77FC;
extern O01Text D_800D7804;
extern u8 *D_800D7A24;
extern u8 *D_800D7A28;
extern u8 *D_800D7A3C;
extern u8 *D_800D7A44;
extern u8 *D_800D7A48;

s32 func_auto_0040A8D0(O01Item *item) {
    u8 *src;
    u8 *dst;
    s32 i;
    if (D_80153774 != 0) {
        item->unk14 = &D_800D77FC;
    } else {
        item->unk14 = &D_800D7804;
        switch (D_80153720[0]) {
        default:
        case 0:
        case 1:
        case 4:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
            src = D_800D7A24;
            break;
        case 5:
            src = D_800D7A28;
            break;
        case 3:
            src = D_800D7A3C;
            break;
        case 2:
            src = D_800D7A44;
            break;
        case 14:
            src = D_800D7A48;
            break;
        }
        dst = (u8 *)item->unk14->buf;
        dst += 6;
        for (i = 0; i < 14; i++) {
            *dst++ = *src++;
        }
    }
    return 0;
}
