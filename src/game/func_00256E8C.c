#include "p2_types.h"

extern Ctx256 D_8010BDF0;
extern u8 D_8010B928[];
void func_00257210(void);

void (*func_00256E8C(Ctx256 **out))(void) {
    if (D_8010BDF0.inited == 0) {
        D_8010BDF0.f8 = D_8010B928;
        D_8010BDF0.f4 = 0;
        D_8010BDF0.inited = 1;
    }
    *out = &D_8010BDF0;
    return func_00257210;
}