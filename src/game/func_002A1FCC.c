#include "b23_types.h"
extern s32 (*D_800D2B9C)(s32 fp, u8 *buf, s32 n);
s32 func_002A1FCC(s32 fp) {
    u8 c;
    return D_800D2B9C(fp, &c, 1) ? c : -1;

}
