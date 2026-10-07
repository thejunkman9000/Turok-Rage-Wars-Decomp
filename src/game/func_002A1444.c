#include "common.h"
unsigned char *func_002A1444(const unsigned char *string, s32 ch)
{
    unsigned char *start = (unsigned char *)string;
    while (*string++)
        ;
    while (--string != start && *string != (unsigned char)ch)
        ;
    if (*string == (unsigned char)ch)
        return (unsigned char *)string;
    return 0;
}
