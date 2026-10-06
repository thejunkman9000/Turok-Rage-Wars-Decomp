#include "b07_types.h"
s32 func_0022EEF4(u8 *str, s32 len)
{
    s32 count = 0;
    while (1) {
        len--;
        if (str[len] != ' ') break;
        count++;
        if (len <= 0) break;
    }
    return count;
}
