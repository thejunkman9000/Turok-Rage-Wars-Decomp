#include "b17_types.h"

void func_00278C80(Rec14 *r);

void func_00278F70(Rec14 *r) {
    Rec14 tmp;

    r->flagsE |= 0x20;
    if (r->b11 == 1) {
        tmp = *r;
        tmp.b12 = 2;
        tmp.b10 = 0;
        func_00278C80(&tmp);
    }
}
