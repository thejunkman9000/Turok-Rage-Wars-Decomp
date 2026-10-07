#include "o05_types.h"
typedef struct { u8 pad0[0x54]; s32 f54; u8 pad58[0x78 - 0x58]; s32 f78; u8 pad7C[0xA8 - 0x7C]; s32 fA8; } O05G;
extern O05G D_801468A0[];
extern s32 D_8015402C;
void func_00299368(s32 a);

void func_00438BD0(void) {
    s32 a;
    s32 ten;
    s32 three;
    O05G *g;
    D_801468A0->f78 = 0;
    (g = D_801468A0)->f54 = 0;
    if (g->fA8 == 1) {
        ten = 10;
        if (D_8015402C < 0x23) {
            a = ten;
        } else {
            three = 3;
            switch (*((u8 *)g - 0x5CB)) {
            case 3:
                a = 3;
                break;
            case 1:
                a = 7;
                break;
            case 4:
                a = three;
                break;
            default:
                a = 3;
                break;
            }
        }
    } else {
        a = 10;
    }
    func_00299368(a);
}
