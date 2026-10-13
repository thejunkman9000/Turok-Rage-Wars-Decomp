#include "o05_types.h"

typedef struct { u8 pad[0x1C]; s32 f1C; } O05M5830;
extern O05M5830 *D_800E5830;
extern s32 D_80146894;
void func_0029A73C(void);
s32 func_0029AA08(void);
s32 func_0043C4E8(void *p);
void func_0043C458(void *p);
void func_00435190(s32 a);
void func_00299368(s32 a);
void func_0042EB68(s32 a);

s32 func_auto_00438D94(void) {
    func_0029A73C();
    if (func_0043C4E8(D_800E5830) == 1) {
        return 0;
    }
    D_80146894 = 0;
    switch (func_0029AA08()) {
    case 0x26E:
        func_0043C458(D_800E5830);
        D_800E5830->f1C = 0;
        break;
    case 0x26F:
        func_00435190(5);
        func_00299368(0x13);
        break;
    case 0x273:
        func_0042EB68(0x21);
        break;
    }
    return 0;
}
