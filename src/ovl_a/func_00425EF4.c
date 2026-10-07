#include "o04_types.h"
typedef struct {
    u8 pad0[0x7E]; u8 unk7E[5]; u8 unk83[5]; u8 unk88[5]; u8 unk8D[5]; u8 pad92[0x190 - 0x92];
} O04Row190e;
extern u8 D_801462D5;
extern s32 D_8015402C;
extern O04Row190e D_80102B00[];
void func_002656A8(void *p, s32 a, s32 b);
void func_00425EF4(s32 a) {
    switch (D_801462D5) {
    case 1:
        func_002656A8(D_80102B00[a].unk7E, D_8015402C, 1);
        break;
    case 2:
        func_002656A8(D_80102B00[a].unk83, D_8015402C, 1);
        break;
    case 3:
        func_002656A8(D_80102B00[a].unk88, D_8015402C, 1);
        break;
    case 4:
        func_002656A8(D_80102B00[a].unk8D, D_8015402C, 1);
        break;
    }
}
