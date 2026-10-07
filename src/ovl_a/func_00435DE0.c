#include "o05_types.h"

extern void *D_800E5550;
void func_00254784(void *p);
void func_002A33BC(s32 a);
void func_0026497C(void);

s32 func_00435DE0(void) {
    func_00254784(D_800E5550);
    D_800E5550 = 0;
    func_002A33BC(2);
    func_0026497C();
    return 0;
}
