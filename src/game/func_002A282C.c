#include "b23_types.h"

extern MinMaxF D_800D2BDC;
extern MinMaxF D_800D2BE8;
extern MinMaxF D_800D2BF4;

void func_002A282C(void) {
    D_800D2BDC.lo = D_800D2BDC.cur;
    D_800D2BDC.hi = D_800D2BDC.cur;
    D_800D2BE8.lo = D_800D2BE8.cur;
    D_800D2BE8.hi = D_800D2BE8.cur;
    D_800D2BF4.lo = D_800D2BF4.cur;
    D_800D2BF4.hi = D_800D2BF4.cur;
}
