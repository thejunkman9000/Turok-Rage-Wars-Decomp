#include "o03_types.h"
typedef struct { u8 pad[0x20]; s32 f20; } O3Q24;
extern O3Q24 *D_800E44A0;
extern u8 D_801462D5;
s32 func_0043C4E8(void *p);
void func_002A3358();
void func_002A338C();
void func_00245B18();
void func_0042B4C4();
void func_0043C458(void *p);
s32 func_00422370(void) {
    if (func_0043C4E8(D_800E44A0) == 1) return 0;
    func_002A3358();
    if (D_800E44A0->f20 != 1) return 0;
    func_002A338C();
    if (D_801462D5 == 0) {
        func_00245B18();
        func_0042B4C4();
    }
    func_0043C458(D_800E44A0);
    return 0;
}
