#include "common.h"

char *func_002934A4(char *dst, char *src) {
    u8 *p = (u8 *)dst;
    while ((*p++ = *(u8 *)src++) != 0)
        ;
    return dst;
}
