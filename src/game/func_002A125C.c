#include "b23_types.h"
u8 *func_002A125C(u8 *dst, u8 *src) {
    u8 *d = dst;
    while ((*d++ = *src++) != 0) ;
    return dst;

}
