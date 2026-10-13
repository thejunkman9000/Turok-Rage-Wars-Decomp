#include "o01_types.h"
#include "veu3n06_types.h"

extern s32 D_auto_8015D4E4;
extern s8 D_auto_8015D490[];
extern O01Text D_auto_800E2994;
extern O01Text D_auto_800E29B4[];
extern u8 *D_auto_800E3234[];
extern u8 *D_auto_800E3244[];
extern u8 *D_auto_800E3294[];
extern u8 *D_auto_800E32B4[];
extern u8 *D_auto_800E32C4[];
s32 func_auto_00442EE0();

s32 func_auto_0040AC68(O01Item *item) {
    u8 *src;
    u8 *dst;
    s32 i;
    if (D_auto_8015D4E4 != 0) {
        item->unk14 = &D_auto_800E2994;
    } else {
        item->unk14 = D_auto_800E29B4;
        switch (D_auto_8015D490[0]) {
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
            src = D_auto_800E3234[D_801462C8.lang];
            break;
        case 5:
            src = D_auto_800E3244[D_801462C8.lang];
            break;
        case 3:
            src = D_auto_800E3294[D_801462C8.lang];
            break;
        case 2:
            src = D_auto_800E32B4[D_801462C8.lang];
            break;
        case 14:
            src = D_auto_800E32C4[D_801462C8.lang];
            break;
        }
        dst = (u8 *)item->unk14[D_801462C8.lang].buf;
        dst += func_auto_00442EE0() - 11;
        for (i = 0; i < 11; i++) {
            *dst++ = *src++;
        }
    }
    return 0;
}
