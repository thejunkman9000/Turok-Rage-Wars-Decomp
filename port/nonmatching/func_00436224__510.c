#include "o05_types.h"
typedef struct { u8 pad[0x1C]; s32 f1C; } O05W20;
extern O05W20 *D_800E5554;
extern u8 D_801462D5;
void func_0029A73C(void);
s32 func_0029AA08(void);
void func_00299368(s32 a);
s32 func_0025E2E4(void);
void func_0025E2F4(s32 a);
void func_002A338C(void);
void func_0043C458(void *p);

s32 func_00436224(void) {
    func_0029A73C();
    switch (func_0029AA08()) {
    case 0x3D5:
        func_00299368(1);
        return 0;
    case 0x3D3:
        if (func_0025E2E4() != 0) {
            func_0025E2F4(0x34);
        }
        func_002A338C();
        switch (D_801462D5) {
        case 0:
            D_800E5554->f1C = 10;
            break;
        case 1:
            D_800E5554->f1C = 15;
            break;
        case 2:
            D_800E5554->f1C = 10;
            break;
        case 3:
        case 4:
        default:
            D_800E5554->f1C = 20;
            break;
        }
        func_0043C458(D_800E5554);
        return 0;
    default:
        return 0;
    }
}
