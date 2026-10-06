#include "common.h"

typedef struct { s32 high; s32 low; } DIstruct;
typedef union { DIstruct s; s64 ll; } DIunion;

s32 __cmpdi2(s64 a, s64 b) {
    DIunion au, bu;
    au.ll = a, bu.ll = b;
    if (au.s.high < bu.s.high) return 0;
    else if (au.s.high > bu.s.high) return 2;
    if ((u32)au.s.low < (u32)bu.s.low) return 0;
    else if ((u32)au.s.low > (u32)bu.s.low) return 2;
    return 1;
}
