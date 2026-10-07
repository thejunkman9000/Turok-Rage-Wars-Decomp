#include "o04_types.h"
typedef struct {
    u8 pad0[0x7E]; u8 unk7E[5]; u8 unk83[5]; u8 unk88[5]; u8 unk8D[5]; u8 pad92[0x190 - 0x92];
} O04Row190e;
extern O04ModeS4690 *D_800E4690;
extern u8 D_801462D5;
extern O04Row190e D_80102B00[];
s32 func_00265670(void *p, s32 a);
void func_002656A8(void *p, s32 a, s32 b);
void func_00427690(void);
void func_004271E8(void) {
    s32 i;
    for (i = 0; i < 0x24; i++) {
        func_002656A8(D_800E4690->unkA74, i, 0);
        func_002656A8(D_800E4690->unkA79, i, 0);
    }
    switch (D_801462D5) {
    case 1:
        for (i = 0; i < 0x24; i++) {
            func_002656A8(D_800E4690->unkA74, i, func_00265670(D_80102B00[D_800E4690->unkA5C].unk7E, i));
        }
        break;
    case 2:
        for (i = 0; i < 0x24; i++) {
            func_002656A8(D_800E4690->unkA74, i, func_00265670(D_80102B00[D_800E4690->unkA5C].unk83, i));
        }
        break;
    case 3:
        for (i = 0; i < 0x24; i++) {
            func_002656A8(D_800E4690->unkA74, i, func_00265670(D_80102B00[D_800E4690->unkA5C].unk88, i));
        }
        break;
    case 4:
        for (i = 0; i < 0x24; i++) {
            func_002656A8(D_800E4690->unkA74, i, func_00265670(D_80102B00[D_800E4690->unkA5C].unk8D, i));
        }
        break;
    }
    func_00427690();
}
